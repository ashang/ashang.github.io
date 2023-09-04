#include <stdio.h>
#include <math.h>
# define M_PI		3.14159265358979323846	/* pi */
# define M_PIl		3.141592653589793238462643383279502884L /* pi */
//#include <stdio.h>

int main(){


   char str[80];

   sprintf(str, "%f", M_PI);
   printf("Pi = %s\n", str);
   printf("Pi = %3f\n", M_PI);
   printf("Pi = %2.10lf\n", M_PI);
   printf("Pi = %2.32lf\n", M_PIl);

   return(0);
}
