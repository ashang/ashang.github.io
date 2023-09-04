#include <stdio.h>
#include <string.h>

int main(){
    char* haystack="stack";
    char* needle="tack";
    static int hlen, nlen, found=0;
    //int i,j,k;
    int i,j;

    found = 0;
    hlen = strlen(haystack);
    nlen = strlen(needle);

    for (i = 0; i < hlen; ++i) {
        for (j = 0; j < nlen; ++j) {
            if (haystack[i+j] != needle[j]) break;
            if (j == nlen - 1) found = 1;
        };
    };

    printf("%d\n", found);
    return found;
}
