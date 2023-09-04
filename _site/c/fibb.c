#include <stdio.h>
int
main(){
  for (int a=1, b=0; a<100; a+=b+=a) {
    printf("%d\n%d\n", b,a);
  }
}
