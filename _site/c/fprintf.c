// fprintf.c
#include <stdio.h>

int main () {
    char str[80];
    int i, n=2;


    FILE *fptr = fopen("/tmp/a.c", "w");
    if (NULL == fptr)
    {
	printf("Could not open file");
	return 0;
    }

    for (i=0; i<n; i++)
    {
	puts("Enter a name");
	gets(str);
	//fgets(str, sizeof(str), fptr);
	fprintf(fptr, "%d. %s\n", i, str);
    }

    fclose(fptr);

    return(0);
}
