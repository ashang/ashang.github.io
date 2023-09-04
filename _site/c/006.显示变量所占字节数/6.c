/* 输出不同类型所占的字节数*/
#include <stdio.h>
int main()
{
    /* sizeof()是保留字，它的作用是求某类型或某变量类型的字节数, */
    /* 括号中可以是类型保留字或变量。*/
    /*int型在不同的机器，不同的编译器中的字节数不一样,*/
    printf("The bytes of the variables are:\n");

    printf("int:%9d bytes\n", (int) sizeof(int));

    printf("char:%9d byte\n", (int) sizeof(char));

    printf("short:%9d bytes\n", (int) sizeof(short));

    printf("long:%9d bytes\n", (int) sizeof(long));

    printf("long long:%9d bytes\n", (int) sizeof(long long));

    printf("float:%9d bytes\n", (int) sizeof(float));

    printf("double:%9d bytes\n", (int)sizeof(double));

    printf("long double:%9d bytes\n", (int)sizeof(long double));

    getchar();
    return 0;

}


