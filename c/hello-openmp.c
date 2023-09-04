// gcc -fopenmp
// export OMP_NUM_THREADS=2
#include <stdio.h>

 int main(int argc, char* argv[])
 {
  #pragma omp parallel
   printf("Hello, world.\n");

   return 1;
 }
