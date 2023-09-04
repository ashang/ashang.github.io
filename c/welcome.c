#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse (char *);

int main() {

	char str[] = "Welcome!";
	printf("Original string is %s\n", str);
	reverse(str);
}

void reverse(char *str) {
	int i , len;
	char *s;
	len = strlen(str);
	if ( (s=malloc(len+1)) == NULL ) exit(1);
	for (i=0; i<len; i++)
		//s[len-i] = str[i];
		s[len-1-i] = str[i];
	//s[len+1]='\0';
	s[len]='\0';
	printf("Reversed string is %s\n", s);
}
