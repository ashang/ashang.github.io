/*************************************************************************
  > File Name: sum-sum-product.c
*/

#include<stdio.h>

int a[10]= {10, 15, -4, 25, 0, 4, 9, -5, 3, 12};

int main()
{
    int i, sum1, sum2, prod;
    sum1 = sum2 = 0;
    for (i =0; i<=10; i++) {
        if (a[i]<=0)
            continue;
        else {
            if (a[i]>=10)
               sum1 +=++a[i];
            else
               sum2 +=--a[i];
        }
    }
    prod = sum1 * sum2;
    printf("%d %d %d \n", sum1, sum2, prod);
}
