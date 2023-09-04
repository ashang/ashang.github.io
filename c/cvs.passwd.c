/*
请问 CVS 客户端如何修改自己的用户口令？
如果你的意思是：“是否存在 cvs passwd 命令，能够让客户端远程修改口令？”，好像 CVSNT, cvsnserver 等支持或部分支持，但是 CVS 暂时不可以。
但是并不说就没有办法让用户修改口令，你可以写一个小程序来实现。
下面的一段代码，就是我的一个实现。用户的 unix 系统账号都带有前缀 u_ ，CVS 账号则没有此前缀。CVS账号和系统账号一一对应，并保存在 /etc/passwd.cvs 文件中，每个 CVS 工程都在 CVSROOT 目录中创建一个符号链接: passwd -&gt; /etc/passwd.cvs。
下面的程序只能够稳定工作，至于是否有安全上的 BUG，还不确定，如果实现上有可改进之处，请不吝赐教。
*/


#include &lt;unistd.h&gt;
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;string.h&gt;
#include &lt;sys/types.h&gt;
#include &lt;sys/ipc.h&gt;
#include &lt;sys/sem.h&gt;
#include &lt;string.h&gt;
#include &lt;assert.h&gt;
#include &lt;curses.h&gt;
#include &lt;time.h&gt;

#include "pwd_check.h"
#include "semtool.h"
#include "crypt.h"

#define	_CMD_PASSWD_		"/usr/bin/passwd"
#define	_CVS_PASSWD_FILE_	"/etc/passwd.cvs"
#define	_TEMP_FILE_			"/tmp/cvspass.XXXXXX"
#ifndef _PASSWORD_LEN
#define	_PASSWORD_LEN	128
#endif

#define	out_msg(format, ...)	fprintf (stderr, format, ## __VA_ARGS__)

#ifdef	_DEBUG
#define	debug_msg(format, ...)	fprintf (stderr, format, ## __VA_ARGS__)
#else
static __inline__ void
debug_msg (char *fmt, ...)
{
}
#endif

int init_screen ();
void change_unix_passwd ();
int change_cvs_passwd ();
char *encrypt_passwd (char *plain);
int test_encrypt_passwd (char *pass, char *encrypt);
int rewrite_cvspass (char *username, char *encrypt, bool b_adduser=false);
char *get_new_passwd ();
void check_old_passwd ();
void curses_init ();
void add_user(char *username);

int uid;
char *uname = NULL;
char * program;

char PASSWD_CHAR[]="abcdefghjkmnpqrstuvwxyABCDEFGHIJKLMNPQRSTUVWXY23456789@%&amp;^";

void
help()
{
	extern char * program;
	printf("\nUsage:\n");
	printf("    %s\n\t    gen passwd\n",program);
	printf("    %s -p\n\t    gen passwd\n",program);
	printf("    %s -a &lt;username&gt;\n\t    add user\n",program);
	printf("\n");
}

void
init_random()
{
	FILE	*fp;
	long	x = 0;

	if ((fp = fopen("/dev/urandom", "r")) != NULL)
	{
		(void) fread(&amp;x, sizeof(x), 1, fp);
		fclose(fp);
	}
	x += time(NULL) + getpid() + getppid();
	srand(x);
}

char *
rand_passwd(char *passwd, int size)
{
	char *p;	
	int begin=0;
	int end=sizeof(PASSWD_CHAR)/sizeof(PASSWD_CHAR[0])-1;
	int idx=0, i=0;
	
	p = passwd;
	
	init_random();
	//printf("rand number between %d, and %d: \n", begin, end);
	for(i=0; i&lt;size-1; i++)
	{
		idx = (int) (end*1.0*rand()/(RAND_MAX+1.0));
		if(idx&lt;begin)	idx=begin;
		if(idx&gt;end)	idx=end;
		*(p++) = PASSWD_CHAR[idx];
	}
	*p = 0;
	return passwd;
}

void
add_user(char *uname)
{
	char cmd[1024] = {'\0'};
	char plain[11];
	char *encrypt;
	char cvs_plain[11];
	char *cvs_encrypt;
	
	char *unix_uname, *cvs_uname;
	int size;
	size = strlen(uname)+3;
	
	unix_uname= (char *) malloc(size);
	cvs_uname = (char *) malloc(size);
	bzero(unix_uname, size);
	bzero(cvs_uname, size);
	if(uname[0] == 'u' &amp;&amp; uname[1] == '_')
	{
		strcpy(unix_uname, uname);
		strcpy(cvs_uname, uname+2);
	}
	else
	{
		strcpy(cvs_uname, uname);
		sprintf(unix_uname, "u_%s", uname);
	}

	rand_passwd(plain, sizeof(plain));
	encrypt = encrypt_passwd (plain);
	snprintf(cmd, sizeof(cmd)-1, "adduser -M -s /bin/cvspasswd -g nobody -p '%s' %s", encrypt, unix_uname);
	system(cmd);

	cvs_ipc_init ();
	rand_passwd(cvs_plain, sizeof(cvs_plain));
	cvs_encrypt = encrypt_passwd (cvs_plain);
	rewrite_cvspass (unix_uname, cvs_encrypt, true);

	//printf("cmd : %s\n", cmd);
	printf("Unix Username : %s\n", unix_uname);
	printf("Unix Passwd   : %s\n", plain);
	printf("CVS  Username : %s\n", cvs_uname);
	printf("CVS  Passwd   : %s\n", cvs_plain);
	printf("\n");
	printf("CVS 登录口令自己去修改。\n");
}


int
main (int argc, char *argv[], char **environ)
{
	char passwd[11];

	// Regist program name
	char *p;
	p = argv[0] + strlen(argv[0]);
	while (--p != argv[0])
	{
		if (*p == '/' || *p == '\\')
		{
			p++;
			break;
		}
	}
	program = strdup(p);

	if(argc&gt;1)
	{
		char ch;
		while ((ch = getopt(argc, argv, "h?pa:")) != -1) {
			switch (ch) {
				case 'h':
				case '?':
					help();
					break;
				case 'p':
					printf("%s\n",rand_passwd(passwd, sizeof(passwd)));
					break;
				case 'a':
					add_user(optarg);
					break;
				default:
					printf("%s\n",rand_passwd(passwd, sizeof(passwd)));
					help();
					break;
			}
		}
		exit(0);
	}

	uid = getuid();
	uname = strdup(getlogin());
	if (uid == 0)
	{
		out_msg ("Can not be root, Uid = 0!");
		return 1;
	}
	
	while (1)
	{
		switch (init_screen ())
		{
		case 1:
			// 为了使口令修改更便捷
			/*
			if (setreuid (0, 0) != 0)
			{
				out_msg ("setuid failed!\n");
				return 1;
			}
			*/
			change_unix_passwd ();
			break;
		case 2:
			cvs_ipc_init ();

			// 缺省设置，更安全
			/*
			if (setreuid (uid, 0) != 0)
			{
				out_msg ("setuid failed!\n");
				return 1;
			}
			*/
			change_cvs_passwd ();
			break;
		case 3:
		case 0:
			out_msg ("\nbye bye\n");
			exit(0);
			break;
		default:
			break;
		}
		out_msg ("\nPress any key to Continue...");
		getch ();
	}
	return 0;
}


/*
 * 显示菜单
 */
void
curses_init ()
{
	initscr ();
	cbreak ();
	nonl ();
	noecho ();
	intrflush (stdscr, FALSE);
	keypad (stdscr, TRUE);
	refresh ();
}

int
init_screen ()
{
#define _MENU_START_LINE_	5	/* 可选菜单从第5行开始 */
#define _MENU_ITEM_NUM_		3	/* 共三项 */
#define _MENU_LEFT_COL_		5	/* 菜单的左侧启示列 */

	int x, y;
	int ch;

	curses_init ();

/* 画方框 */
	box (stdscr, '|', '-');

/* 开启反白模式 */
	attron (A_REVERSE);

/* 在 (20,0) 处输出反白字元 */
	mvaddstr (0, 20, "CVS Account Management");

/* 关闭反白模式 */
	attroff (A_REVERSE);

	mvaddstr (_MENU_START_LINE_ + 0, _MENU_LEFT_COL_,
			  "1	---	Change Linux login passwd");
	mvaddstr (_MENU_START_LINE_ + 1, _MENU_LEFT_COL_,
			  "2	---	Change CVS   login passwd");
	mvaddstr (_MENU_START_LINE_ + 2, _MENU_LEFT_COL_, "3	---	Exit");

	mvaddstr (_MENU_START_LINE_ + _MENU_ITEM_NUM_ + 2, _MENU_LEFT_COL_,
			  "Use Number/Cursor to select, and press ENTER to excute!");

/* 将游标移至初始位置 */
	x = _MENU_LEFT_COL_;
	y = _MENU_START_LINE_;
	move (x, y);

	while (1)
	{
		ch = getch ();
		switch (ch)
		{

/* 判断是否"↑"键被按下 */
		case KEY_UP:
			if (y &gt; _MENU_START_LINE_)
				--y;
			break;

/* 判断是否"↓"键被按下 */
		case KEY_DOWN:
			if (y &lt; _MENU_START_LINE_ + _MENU_ITEM_NUM_ - 1)
				++y;
			break;

/* 判断是否"→"键被按下 */
		case KEY_RIGHT:
			//++x;
			break;

/* 判断是否"←"键被按下 */
		case KEY_LEFT:
			//--x;
			break;

/* 判断是否 ENTER 键被按下 */
		case '1':
			y = _MENU_START_LINE_;
			break;
		case '2':
			y = _MENU_START_LINE_ + 1;
			break;
		case '0':
		case '3':
			y = _MENU_START_LINE_ + 2;
			break;
		case '\r':
		case '\n':
			endwin ();
			return y + 1 - _MENU_START_LINE_;
			break;

/* 判断是否[ESC]键被按下, 则退出 curses 模式 */
		case 27:
			endwin ();
			exit (1);

		default:
			//addch (ch);
			break;
		}
		/* 移动游标至现在位置 */
		move (y, x);
	}

	return 0;
}


/*
 * 修改 Unix 口令
 */
void
change_unix_passwd ()
{
	char cmd[1024];
	memset(cmd, 0, 1024);	

	//out_msg("orignal uid: %d, getuid: %d, geteuid: %d, getlogin:%s\n", uid, getuid(), geteuid(), getlogin());

	if (getuid() == 0)
	{
		assert(strcmp(uname, "root")!=0);
		snprintf(cmd, 1024, "%s %s", _CMD_PASSWD_, uname);
		system(cmd);
	}
	else
	{
		system(_CMD_PASSWD_);
	}
}

/*
 * 修改 CVS 口令
 */
int
change_cvs_passwd ()
{
	char *newpasswd = NULL;
	char *encrypt = NULL;
	int pfd, tfd;

	out_msg ("\n\nChange your CVS Account Password:\n");

	// 获取 loginname

	// 检查是否存在 /etc/passwd.cvs 文件
	if (access (_CVS_PASSWD_FILE_, F_OK) != 0)
	{
		out_msg ("Not find file %s!\n",
				 _CVS_PASSWD_FILE_);
		return 1;
	}

	// 输入旧口令
	// 修改CVS口令，无须输入旧口令
	//check_old_passwd();

	// 输入新口令（两次，需要匹配）
	newpasswd = get_new_passwd ();
	if (strlen (newpasswd) == 0)
	{
		out_msg ("CVS passwd not changed!");
		return 1;
	}

	// 新口令加密
	encrypt = encrypt_passwd (newpasswd);


	// 检查用户账号是否和 /etc/passwd.cvs 文件的 realname 字段匹配，格式 aliases:passwd:realname
	// 重新生成 /etc/passwd.cvs 文件
	rewrite_cvspass (uname, encrypt);

	return 0;
}



/*
 * 获取用户的原口令输入
 */
void
check_old_passwd ()
{
	FILE *fp;
	char line[1024];			//, buf[1024];
	char *buf;
	char *t1, *t2, *t3;
	char *oldpasswd;
	int match = 0;

	oldpasswd = getpass ("Old password:");

	// cvs_lock
	cvs_lock ();

	if ((fp = fopen (_CVS_PASSWD_FILE_, "r")) == NULL)
	{
		out_msg ("can not open cvspass file\n");
		exit (1);
	}

	while (fgets (line, 1024, fp))
	{
		//strncpy(buf, line, 1024);
		if (line[strlen (line) - 1] == '\n')
			line[strlen (line) - 1] = 0;

		buf = (char *) strdup (line);
		t1 = (char *) strtok (buf, ":");
		t2 = (char *) strtok (NULL, ":");
		t3 = (char *) strtok (NULL, ":");

		if (t3 != NULL &amp;&amp; strcmp (t3, getlogin ()) == 0)
		{
			if (test_encrypt_passwd (oldpasswd, t2))
			{
				out_msg ("Wrong password!\n");
				match = 0;
			}
			else
			{
				match = 1;
			}
		}
	}
	fclose (fp);

	// cvs_unlock()
	cvs_unlock ();

	if (!match)
	{
		exit (1);
	}

	return;
}


/*
 * 获取用户的新口令输入
 */
char *
get_new_passwd ()
{
	int tries, pwd_tries = 3;
	char *newpasswd = NULL;
	char *p;

#ifdef	_OLDPWD_CHECK_
	check_old_passwd ();
#endif

	if (newpasswd == NULL)
	{
		newpasswd = (char *) malloc (_PASSWORD_LEN + 1);
	}

	for (newpasswd[0] = '\0', tries = 0; tries &lt; pwd_tries; tries++)
	{
		p = getpass ("New password:");
		if (!*p)
		{
			out_msg ("Password unchanged.\n");
			newpasswd[0] = '\0';
			break;
		}
		if (strcmp (p, "s/key") == 0)
		{
			out_msg
				("That password collides with a system feature. Choose another.\n");
			continue;
		}

		if ((tries &lt; pwd_tries || pwd_tries == 0) 
				    &amp;&amp; pwd_check(p) == 0)
			continue;

		strncpy (newpasswd, p, _PASSWORD_LEN);
		newpasswd[_PASSWORD_LEN] = 0;
		if (strcmp (newpasswd, getpass ("Retype new password:")) == 0)
		{
			break;
		}
		else
		{
			newpasswd[0] = 0;
			out_msg ("Mismatch; try again, EOF to quit.\n");
		}
	}

	return (newpasswd);
}


/*
 * 修改 cvs 口令文件
 * username is Unix Username, such as: u_xxx
 */
int
rewrite_cvspass (char *username, char *encrypt, bool b_adduser)
{
	FILE *fp;
	int fdtmp;
	char *tmpfile = NULL;
	char line[1024];			//, buf[1024];
	char *buf;
	char *t1, *t2, *t3;
	int err = 0, changed = 0;
	char *alias;

	// cvs_lock
	cvs_lock ();

	tmpfile = (char *) strdup (_TEMP_FILE_);
	fdtmp = mkstemp (tmpfile);

	if (fdtmp == -1)
	{
		out_msg ("can not open cvspass temp file: %s\n", tmpfile);

		err = 1;
		goto clean;
	}

	if ((fp = fopen (_CVS_PASSWD_FILE_, "r")) == NULL)
	{
		out_msg ("can not open cvspass file!\n");

		err = 1;
		close(fdtmp);
		goto clean;
	}

	// 重新生成 /etc/passwd.cvs 文件
	while (fgets (line, 1024, fp))
	{
		//strncpy(buf, line, 1024);
		if (line[strlen (line) - 1] == '\n'
			|| line[strlen (line) - 1] == '\r')
			line[strlen (line) - 1] = 0;
		if (line[strlen (line) - 1] == '\n'
			|| line[strlen (line) - 1] == '\r')
			line[strlen (line) - 1] = 0;

		buf = (char *) strdup (line);
		t1 = (char *) strtok (buf, ":");
		t2 = (char *) strtok (NULL, ":");
		t3 = (char *) strtok (NULL, ":");

		if (t3 != NULL &amp;&amp; strcmp (t3, username) == 0)
		{
			snprintf (line, 1024, "%s:%s:%s", t1, encrypt, t3);
			alias = strdup(t1);
			changed = 1;
		}
		write (fdtmp, line, strlen(line));
		write (fdtmp, "\n", 1);
	}

	fclose (fp);
	close (fdtmp);

	if(b_adduser &amp;&amp; !changed)
	{
		if ((fp = fopen (tmpfile, "a")) != NULL)
		{
			if(username[0] == 'u' &amp;&amp; username[1] == '_')
				alias = username+2;
			else
				alias = username;
			snprintf (line, 1024, "%s:%s:%s\n", alias, encrypt,username);
			fputs(line,fp);
			changed = 2;
			fclose(fp);
		}
		
	}

	if (rename (tmpfile, _CVS_PASSWD_FILE_) != 0)
	{
		out_msg ("can not rename %s to %s\n", tmpfile, _CVS_PASSWD_FILE_);

		err = 1;
		goto clean;
	}

clean:
	// cvs_unlock()
	cvs_unlock ();
	
	switch(changed)
	{
	case 1:
		out_msg ("CVS passwd for %s(%s) changed.\n", alias, username);
		break;
	case 2:
		out_msg ("add CVS passwd entry for %s(%s).\n", alias, username);
		break;
	case 0:
	default:
		out_msg ("Not find CVS entry of user: %s\n", username);
		break;
	}
	return err;
}


/*
 * 加密口令
 */
char *
encrypt_passwd (char *plain)
{
	unsigned long seed[2];
	char salt[] = "$1$........";
	const char *const seedchars =
		"./0123456789ABCDEFGHIJKLMNOPQRST"
		"UVWXYZabcdefghijklmnopqrstuvwxyz";
	char *password;
	int i;

	/* Generate a (not very) random seed.
	   You should do it better than this... */
	seed[0] = time (NULL);
	seed[1] = getpid () ^ (seed[0] &gt;&gt; 14 &amp; 0x30000);

	/* Turn it into printable characters from `seedchars'. */
	for (i = 0; i &lt; 8; i++)
		salt[3 + i] = seedchars[(seed[i / 5] &gt;&gt; (i % 5) * 6) &amp; 0x3f];

	/* Read in the user's password and encrypt it. */
	password = (char *) crypt (plain, salt);

	/* Print the results. */
	return password;
}


int
test_encrypt_passwd (char *pass, char *encrypt)
{
	char *result;
	int ok;

	/* Read in the user's password and encrypt it,
	   passing the expected password in as the salt. */
	result = (char *) crypt (pass, encrypt);

	/* Test the result. */
	ok = strcmp (result, encrypt) == 0;

	return ok ? 0 : 1;
}
