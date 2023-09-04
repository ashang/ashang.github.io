#include <iostream>
#include <stdio.h>
#include <map>
#include <list>
#include <string>
#include <typeinfo>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

using namespace std;

#define uint32_t unsigned int
#define int32_t  int


int main() {
    int t = 1000000;
    timeval t1, t2;
    sigset_t c;

    sigemptyset(&c);
    sigaddset(&c, SIGINT);

    gettimeofday(&t1, NULL);
    for (int i = 0; i < t ; i++) {

        sigprocmask(SIG_BLOCK, &c, NULL);
        sigprocmask(SIG_UNBLOCK, &c, NULL);
    }
    gettimeofday(&t2, NULL);

    printf("total: %dus\n", (t2.tv_sec-t1.tv_sec)*1000000+(t2.tv_usec-t1.tv_usec));

    return 0;
}
