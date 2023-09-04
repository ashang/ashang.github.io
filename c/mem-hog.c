
//~]# mount -t cgroup -o memory memory /cgroup/memory
//~]# mkdir /cgroup/memory/blue
//
//Set the amount of memory which tasks in the blue cgroup can use to 100 MB:
//
//~]# echo 104857600 > memory.limit_in_bytes
//
//Change into the blue directory and make sure the OOM killer is enabled:
//
//~]# cd /cgroup/memory/blue
//blue]# cat memory.oom_control
//oom_kill_disable 0
//under_oom 0
//
//blue]# echo $$ > tasks
//
//Start a test program that attempts to allocate a large amount of memory exceeding the limit you set in step 2. As soon as the blue cgroup runs out of free memory, the OOM killer kills the test program and reports Killed to the standard output:
//
//blue]# ~/mem-hog
//
//
// Disable the OOM killer and rerun the test program. This time, the test program remains paused waiting for additional memory to be freed:
//
//blue]# echo 1 > memory.oom_control
//blue]# ~/mem-hog
//
//
// While the test program is paused, note that the under_oom state of the cgroup has changed to indicate that the cgroup is out of available memory:
//
//~]# cat /cgroup/memory/blue/memory.oom_control
//oom_kill_disable 1
//under_oom 1
//
//
// Reenabling the OOM killer immediately kills the test program.
//To receive notifications about every OOM situation, create a program as specified in Section 2.13, “Using the Notification API”. For example[6]:
//
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//#include <sys/eventfd.h>
//#include <errno.h>
//#include <string.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//static inline void die(const char *msg)
//{
//	fprintf(stderr, "error: %s: %s(%d)\n", msg, strerror(errno), errno);
//	exit(EXIT_FAILURE);
//}
//
//static inline void usage(void)
//{
//	fprintf(stderr, "usage: oom_eventfd_test <cgroup.event_control> <memory.oom_control>\n");
//	exit(EXIT_FAILURE);
//}
//
//#define BUFSIZE 256
//
//int main(int argc, char *argv[])
//{
//	char buf[BUFSIZE];
//	int efd, cfd, ofd, rb, wb;
//	uint64_t u;
//
//	if (argc != 3)
//		usage();
//
//	if ((efd = eventfd(0, 0)) == -1)
//		die("eventfd");
//
//	if ((cfd = open(argv[1], O_WRONLY)) == -1)
//		die("cgroup.event_control");
//
//	if ((ofd = open(argv[2], O_RDONLY)) == -1)
//		die("memory.oom_control");
//
//	if ((wb = snprintf(buf, BUFSIZE, "%d %d", efd, ofd)) >= BUFSIZE)
//		die("buffer too small");
//
//	if (write(cfd, buf, wb) == -1)
//		die("write cgroup.event_control");
//
//	if (close(cfd) == -1)
//		die("close cgroup.event_control");
//
//	for (;;) {
//		if (read(efd, &u, sizeof(uint64_t)) != sizeof(uint64_t))
//			die("read eventfd");
//
//		printf("mem_cgroup oom event received\n");
//	}
//
//	return 0;
//}
//
//The above program detects OOM situations in a cgroup specified as an argument on the command line and reports them using the mem_cgroup oom event received string to the standard output.
//Run the above notification handler program in a separate console, specifying the blue cgroup's control files as arguments:
//
//~]$ ./oom_notification /cgroup/memory/blue/cgroup.event_control /cgroup/memory/blue/memory.oom_control
//
//In a different console, run the mem_hog test program to create an OOM situation to see the oom_notification program report it in the standard output:
//
//blue]# ~/mem-hog

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define KB (1024)
#define MB (1024 * KB)
#define GB (1024 * MB)

int main(int argc, char *argv[])
{
	char *p;

again:
	while ((p = (char *)malloc(GB)))
		memset(p, 0, GB);

	while ((p = (char *)malloc(MB)))
		memset(p, 0, MB);

	while ((p = (char *)malloc(KB)))
		memset(p, 0,
				KB);

	sleep(1);

	goto again;

	return 0;
}
