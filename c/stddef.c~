#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(void)
{
	static const char *const str = "500000 us in half a second";
	suseconds_t us;
	intmax_t tmp;

	/* Scan the number from the string into the temporary variable */

	sscanf(str, "%jd", &tmp);

	/* Check that the value is within the valid range of suseconds_t */

	if (tmp < -1 || tmp > 1000000) {
		fprintf(stderr, "Scanned value outside valid range!\n");
		exit(EXIT_FAILURE);
	}

	/* Copy the value to the suseconds_t variable 'us' */

	us = tmp;

	/* Even though suseconds_t can hold the value -1, this isn't
	   a sensible number of microseconds */

	if (us < 0) {
		fprintf(stderr, "Scanned value shouldn't be negative!\n");
		exit(EXIT_FAILURE);
	}

	/* Print the value */

	printf("There are %jd microseconds in half a second.\n", (intmax_t) us);

	exit(EXIT_SUCCESS);
}
