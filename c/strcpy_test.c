#include <stdint.h>
#include <sys/time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

typedef uint64_t microclock_t;

static inline microclock_t microclock() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000ULL + tv.tv_usec;
}

int main(int argc, char **argv) {
    if(argc < 2) {
        fprintf(stderr, "Usage: %s <teststr>\n", argv[0]);
        return 1;
    }

    char buffer[1024];

    microclock_t start, end;
    const int nloops = 10000000;

    /* dummy accesses to warm up the cache */
    for(int i=0; i<nloops; i++) {
        memcpy(buffer, argv[1], strnlen(argv[1], sizeof(buffer)-1) + 1);
        buffer[sizeof(buffer) - 1] = 0;
    }

    start = microclock();
    for(int i=0; i<nloops; i++) {
        memcpy(buffer, argv[1], strnlen(argv[1], sizeof(buffer)-1) + 1);
        buffer[sizeof(buffer) - 1] = 0;
    }
    end = microclock();
    printf("memcpy:   %7"PRIu64" us\n", end - start);


#ifndef __linux__
    start = microclock();
    for(int i=0; i<nloops; i++) {
        strlcpy(buffer, argv[1], sizeof(buffer));
    }
    end = microclock();
    printf("strlcpy:  %7"PRIu64" us\n", end - start);
#endif


    start = microclock();
    for(int i=0; i<nloops; i++) {
        strncpy(buffer, argv[1], sizeof(buffer) - 1);
        buffer[sizeof(buffer) - 1] = 0;
    }
    end = microclock();
    printf("strncpy:  %7"PRIu64" us\n", end - start);


    start = microclock();
    for(int i=0; i<nloops; i++) {
        sprintf(buffer, "%.*s", (int)sizeof(buffer)-1, argv[1]);
    }
    end = microclock();
    printf("sprintf:  %7"PRIu64" us\n", end - start);


    start = microclock();
    for(int i=0; i<nloops; i++) {
        snprintf(buffer, sizeof(buffer), "%s", argv[1]);
    }
    end = microclock();
    printf("snprintf: %7"PRIu64" us\n", end - start);
}
