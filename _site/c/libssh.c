
//$ gcc -I/tmp/ssh/include ssh-test.c /path/to/libssh/build/src/libssh.a -lcrypto -lz

//#define LIBSSH_STATIC 1
#define LIBSSH_STATIC 1

#include <stdlib.h>
#include <stdio.h>
#include <libssh/libssh.h>
int main()
{
    ssh_session my_ssh_session;
    my_ssh_session = ssh_new();

    if (NULL == my_ssh_session)
        exit(-1);


    ssh_free(my_ssh_session);
    return 0;
}
