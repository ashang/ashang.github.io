
/* Inline assembly */
#include <stdio.h>
char message[] = "Hello, world!\n";
int main(void)
{
long _res;
__asm__ volatile (
"int $0x80"
: "=a" (_res)
: "a" ((long) 4),
"b" ((long) 1),
"c" ((long) message),
"d" ((long) sizeof(message)));
return 0;
}
