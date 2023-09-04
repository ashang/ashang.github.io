#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
charcomp (const char *x, const char *y)
{
  return (*x - *y);
}

#define WORDMAX 100
int
main (void)
{
  char word[WORDMAX], sig[WORDMAX];
  while (scanf ("%s", word) != EOF)
    {
      strcpy (sig, word);
      qsort (sig, strlen (sig), sizeof (char), charcomp);
      printf ("%s %s\n", sig, word);
    }
  return 0;
}
