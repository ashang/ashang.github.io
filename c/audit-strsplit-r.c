// gcc -static foo.c $(pkg-config --static --libs audit)
#include <stdio.h>
#include <libaudit.h>

int main() {
    audit_log_user_message(0, AUDIT_USER_LOGIN, "test", NULL, NULL, NULL, 0);
    return 0;
}
