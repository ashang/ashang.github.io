//* compute the potential energy of a collection of */
//* particles interacting via pairwise potential    */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <windows.h>
#include <time.h>
 
#define NPARTS 1000
#define NITER 201
#define DIMS 3
 
int rand( void );
int computePot(void);
void initPositions(void);
void updatePositions(void);
 
double r[DIMS][NPARTS];
double pot;
double distx, disty, distz, dist;

int main() {
   int i;
   clock_t start, stop;

   initPositions();
   updatePositions();
 
   start=clock();
   for( i=0; i<NITER; i++ ) {
      pot = 0.0;
      computePot();
      if (i%10 == 0) printf("%5d: Potential: %10.7f \n", i, pot);
      updatePositions();
   }
   stop=clock();
   printf ("Seconds = %10.9f \n",(double)(stop-start)/ CLOCKS_PER_SEC);
   getchar();
}
 
 
void initPositions() {
   int i, j;
 
   for( i=0; i<DIMS; i++ )
      for( j=0; j<NPARTS; j++ ) 
         r[i][j] = 0.5 + ( (double) rand() / (double) RAND_MAX );
}
 
 
void updatePositions() {
   int i, j;
 
   for( i=0; i<DIMS; i++ )
      for( j=0; j<NPARTS; j++ )
         r[i][j] -= 0.5 + ( (double) rand() / (double) RAND_MAX );
}
 
 
int computePot() {
   int i, j;

   for( i=0; i<NPARTS; i++ ) {
      for( j=0; j<i-1; j++ ) {
        distx = pow( (r[0][j] - r[0][i]), 2 );
        disty = pow( (r[1][j] - r[1][i]), 2 );
        distz = pow( (r[2][j] - r[2][i]), 2 );
        dist = sqrt( distx + disty + distz );
        pot += 1.0 / dist;
      }
   }
   return 0;
}
