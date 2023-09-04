#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>

int
main ()
{

      int a=0, b=0, c=0, d=0, n, v;
      n = sscanf(ZLIB_VERSION, "%d.%d.%d.%d", &a, &b, &c, &d);
      if (n != 3 && n != 4)
              exit(1);
      v = a*1000000 + b*10000 + c*100 + d;
      fprintf(stderr, "found zlib version %s (%d)\n", ZLIB_VERSION, v);

      /* 1.1.4 is OK */
      if (a == 1 && b == 1 && c >= 4)
              exit(0);

      /* 1.2.3 and up are OK */
      if (v >= 1020300)
              exit(0);

      exit(2);

  ;
  return 0;
}
