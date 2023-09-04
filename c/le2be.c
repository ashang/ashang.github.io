//If performance is truly important, the particular processor would need to be known. Otherwise, leave it to the compiler.

#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

int main()
{
	// Swap endian (big to little) or (little to big)
	uint32_t num = 9;
	uint32_t b0,b1,b2,b3;
	uint32_t res;

	b0 = (num & 0x000000ff) << 24u;
	b1 = (num & 0x0000ff00) << 8u;
	b2 = (num & 0x00ff0000) >> 8u;
	b3 = (num & 0xff000000) >> 24u;

	res = b0 | b1 | b2 | b3;

	printf("%" PRIX32 "\n", res);

//32bit numerical value represented by the hexadecimal representation (st uv wx yz) shall be recorded in a four-byte field as (st uv wx yz)
//It appears in this case, the endian of the 32-bit number is unknown and the result needs to be store in memory in little endian order

	uint8_t b[4];
	b[0] = (uint8_t) (num >>  0u);
	b[1] = (uint8_t) (num >>  8u);
	b[2] = (uint8_t) (num >> 16u);
	b[3] = (uint8_t) (num >> 24u);
	for (int i=0; i<4; i++)
		printf("%" PRIX32, b[i]);

	printf("\n");
	return 0;
}

