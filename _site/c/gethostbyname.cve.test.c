/* *

代码审计公司Qualys的研究人员在glibc库中的__nss_hostname_digits_dots()函数中发现了一个缓冲区溢出的漏洞，这个bug可以经过gethostbyname*()函数被本地或者远程的触发。

1）通过gethostbyname()函数或gethostbyname2()函数，将可能产生一个堆上的缓冲区溢出。经由gethostbyname_r()或gethostbyname2_r()，则会触发调用者提供的缓冲区溢出(理论上说，调用者提供的缓冲区可位于堆，栈，.data节和.bss节等。但是，我们实际操作时还没有看到这样的情况)。

2）漏洞产生时至多sizeof(char* )个字节可被覆盖(注意是char*指针的大小，即32位系统上为4个字节，64位系统为8个字节)。但是payload中只有数字( '0 '...' 9') ，点( “.”) ，和一个终止空字符('\0' ) 可用。

3）尽管有这些限制，我们依然可以执行任意的代码。


该漏洞影响glibc库版本2.2-2.17的Linux操作系统

漏洞修复

更新是在glibc包中，但是这个库会被很多运行中的服务使用。在更新之后，每个服务都要重启一下。要找到所有依赖glibc的服务，请使用如下命令，它会显示所有打开的文件(lsof)，然后找到引用glibc库的文件。
$ lsof | grep libc | awk '{print $1}' | sort | uniq


*/


#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <gnu/libc-version.h>
#define CANARY "in_the_coal_mine"
struct {
char buffer[1024];
char canary[sizeof(CANARY)];
} temp = { "buffer", CANARY };
int main(void) {
struct hostent resbuf;
struct hostent *result;
int herrno;
int retval;
/*** strlen (name) = size_needed - sizeof (*host_addr) - sizeof (*h_addr_ptrs) - 1; ***/
size_t len = sizeof(temp.buffer) - 16*sizeof(unsigned char) - 2*sizeof(char *) - 1;
char name[sizeof(temp.buffer)];
memset(name, '0', len);
name[len] = '\0';
retval = gethostbyname_r(name, &resbuf, temp.buffer, sizeof(temp.buffer), &result, &herrno);
if (strcmp(temp.canary, CANARY) != 0) {
puts("vulnerable");
exit(EXIT_SUCCESS);
}
if (retval == ERANGE) {
puts("not vulnerable");
exit(EXIT_SUCCESS);
}
puts("should not happen");
exit(EXIT_FAILURE);
}
