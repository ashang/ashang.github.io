#include <stdio.h>

#include <stdlib.h>
//The atoi() and atoi_l() functions have been deprecated by strtol() and strtol_l() and should not be used in new code.
// atoi equals to (int)strtol(str, (char **)NULL, 10);

//long strtol(const char *restrict str, char **restrict endptr, int base);

//TODO argv scanf()
//TODO int()

int gcd(int a, int b) {
//	printf("gcd of %d %d \n", a, b );
	return b > 0 ? gcd(b, a % b) : a;
}

int main(int argc, char** argv) {
	//printf("gcd of %s %s is %d \n", argv[1], argv[2], gcd(atoi(argv[1]), atoi(argv[2]) ) );
	printf("gcd of %s %s is %d \n", argv[1], argv[2],
        gcd(strtol(argv[1],NULL,10), strtol(argv[2],NULL,10) ) );
}
