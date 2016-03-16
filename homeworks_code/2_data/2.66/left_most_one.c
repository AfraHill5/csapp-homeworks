#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int left_most_one(unsigned x)
{
	unsigned m; // mask
	
	m = x >> 1;
	x = x | m;
	
	m = x >> 2;
	x = x | m;
	
	m = x >> 4;
	x = x | m;
	
	m = x >> 8;
	x = x | m;
	
	m = x >> 16;
	x = x | m;

	/* logical right shift and addition */
	return (x >> 1) + 1;
}

void test_left_most_one()
{
	unsigned y = 0x87654321;
	printf("%x -> %x\n", y, left_most_one(y));
	
	y = 0x8765432;
	printf("%x -> %x\n", y, left_most_one(y));
	
	y = 0x5765432;
	printf("%x -> %x\n", y, left_most_one(y));	
	
	y = 0x57432;
	printf("%x -> %x\n", y, left_most_one(y));	

	y = 0x7;
	printf("%x -> %x\n", y, left_most_one(y));

	y = 0x8;
	printf("%x -> %x\n", y, left_most_one(y));
	
	y = 0xA;
	printf("%x -> %x\n", y, left_most_one(y));

	y = 0xB;
	printf("%x -> %x\n", y, left_most_one(y));

	y = 0xC;
	printf("%x -> %x\n", y, left_most_one(y));
	
	y = 0xD;
	printf("%x -> %x\n", y, left_most_one(y));

	y = 0xE;
	printf("%x -> %x\n", y, left_most_one(y));	
}

int main()
{
	test_left_most_one();
	return 0;
}
