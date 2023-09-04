#include <stdio.h>
#include <stdlib.h>


int
main (int argc, char **argv)
{
  int i;
  int a = 0, b = 0, c = 0;
  double d;
  for (i = 0; i < 100; i++)
    {
      a++;
      if (i > 97)
	d = i / 2.0;
      b++;
    }
  return 0;
}
