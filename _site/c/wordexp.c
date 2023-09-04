#include <stdio.h>
#include <stdlib.h>
#include <wordexp.h>

int
main(int argc, char **argv)
{
    wordexp_t p;
    char **w;
    int i;

    wordexp("[a-c]*.c", &p, 0);
    w = p.we_wordv;
    for (i = 0; i < p.we_wordc; i++)
        printf("%s\n", w[i]);
    wordfree(&p);
    exit(EXIT_SUCCESS);
}

/*
       wordexp, wordfree - perform word expansion like a posix-shell
       #include <wordexp.h>
       int wordexp(const char *s, wordexp_t *p, int flags);
       void wordfree(wordexp_t *p);
   Feature Test Macro Requirements for glibc (see feature_test_macros(7)):

       wordexp(), wordfree(): _XOPEN_SOURCE
*/
