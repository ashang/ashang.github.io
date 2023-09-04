#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#define FILENAME "testfile"

int main(void)
{
    int fd;
    struct stat sb;
    size_t length;
    unsigned char *addr, *vec;
    int page_size, vec_size, i, page_count;

    fd = open(FILENAME, O_RDONLY);
    fstat(fd, &sb);
    length = sb.st_size;

    addr = mmap(NULL, length, PROT_NONE, MAP_PRIVATE, fd, 0);

    page_size = sysconf(_SC_PAGESIZE);
    vec_size = (length + page_size -1)/page_size;
    vec = malloc(vec_size);

    mincore(addr, length, vec);

    for (i = 0; i < vec_size; i++){
        if (vec[i] & 0x1)
            page_count++;
    }

    printf("%d Bytes in core\n", page_count*page_size);

    free(vec);
    return 0;
}

