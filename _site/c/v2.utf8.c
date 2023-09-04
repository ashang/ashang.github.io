#include <stdarg.h>
#include <stdio.h>

double average(int count, ...)
{
    va_list ap;
    double sum = 0;
    int j;

    va_start(ap, count);
    for (j = 0; j < count; j++) {
        sum += va_arg(ap, int); /* Increments ap to the next argument. */
    }
    va_end(ap);

    return sum / count;
}

int main(int argc, char const *argv[])
{
    printf("%f\n", average(6, 9, 8, 7, 6, 5, 4) );
    return 0;
}
