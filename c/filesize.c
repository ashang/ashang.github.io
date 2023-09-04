#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdint.h>

int size(char *dev_name, uint64_t *dev_size)
{
    int fd;

    if (dev_name == NULL || dev_size == NULL){
        fprintf(stderr, "NULL pointer!\n");
        return -1;
    }

    fd = open(dev_name, O_RDWR);
    if (fd < 0){
        fprintf(stderr, "Can not open file %s!\n", dev_name);
        return -1;
    }

    *dev_size = (uint64_t)lseek64(fd, 0, SEEK_END);

    if (*dev_size == -1){
        fprintf(stderr, "Lseek file %s failure!\n", dev_name);
        close(fd);
        return -1;
    }
    close(fd);
    return 0;
};

int main(int argc, char **argv)
{
    int i;
    uint64_t sizeofbyte;
    int ret;
    
    for(i = 1; i < argc; i++) {
        ret = size(argv[i], &sizeofbyte);
        if (ret) {
            fprintf(stderr, "get size of file %s failure\n", argv[i]);
        } else {
            printf("%s \t\t size is \t\t %llu \t\t bypes\n", argv[i], sizeofbyte);
        }
    }
    return 0;
}
