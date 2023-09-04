/* 输入两个浮点数，输出它们中的大 */
#include <stdio.h>
int main()
{
	float x,y,c;				/* 变量定义 */
	printf("Please input x and y:\n");	/* 提示用户输入数据 */
	scanf("%f%f",&x,&y);
	c=x>y?x:y;				/* 计算c=max(x,y) */
	printf("MAX of (%f,%f) is %f",x,y,c);	/* 输出c */
	printf("\n");	/* 输出c */
	return 0;
}

/*
Please input x and y:
33.3
23.4
MAX of (33.299999,23.400000) is 33.299999

$ ./a.out 
Please input x and y:
34 233.3
MAX of (34.000000,233.300003) is 233.300003
*/
