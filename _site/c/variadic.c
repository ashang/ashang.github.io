#include <stdarg.h>
#include <stdio.h>

double average(int count, ...)
{
    va_list ap;
    double sum = 0;
    int j;

    va_start(ap, count);
    for (j = count; j; j = va_arg(ap, int), count++)
        sum += j;
    va_end(ap);

    return sum / count;
}

int main(void)
{
        double avg;
        avg = average(3, 2, 1, 5, 0);
        printf("%f\n", avg);

        return 0;
}
