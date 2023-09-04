#include <stdio.h>

void main() {

    int n, i;
    printf("Enter a number:");
    scanf("%d", &n);
    for(i=1; i<=n; i++) {
	    if ( 0 == i/3 ) {
		printf("%3d * %3d = %5d\n", n,i,n*i);
	    }
    }
    getchar();

}
