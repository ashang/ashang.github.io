// calc 1-1/2+1/3-1/4+...+1/99-1/100
#include <stdio.h>

int main(){
	int sign = 1;
	int deno = 1;
	//float sum = 1;
	//float term = 0;
	double sum = 1;
	double term = 0;

	for (deno=2; deno<=100; deno++) {
		sign = (-1) * sign;
		term = sign * (1.0/deno);
		sum+=term;
	}
	//printf("1-1/2+1/3-1/4+...+1/99-1/100 = %f\n", sum);
	printf("1-1/2+1/3-1/4+...+1/99-1/100 = %lf\n", sum);
// TODO: input n to calc till 1/n

}
