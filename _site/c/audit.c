
#include <libaudit.h>
#include <stdio.h>
#include <errno.h>

int main()
{
        int audit_fd = audit_open ();
        printf("fd is %d\n", audit_fd);
        printf("errno is %d\n", errno);
        return 0;
}
