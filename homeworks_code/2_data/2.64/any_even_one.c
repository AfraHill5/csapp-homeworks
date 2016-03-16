#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char *byte_pointer;

/* Return 1 when anay even bit of x equals 1; 0 otherwise.
   Assume w=32.*/
int any_even_one(unsigned x)
{
	unsigned x_16 = x >> 16;
	unsigned combine_16 = x | x_16;
	
	unsigned x_8 = combine_16 >> 8;
	unsigned combine_8 = x_8 | combine_16;
	
	unsigned char x_4 = combine_8 >> 4;
	unsigned char combine_4 = x_4 | combine_8;

	unsigned char x_2 = combine_4 >> 2;
	unsigned char combine_2 = x_2 | combine_4;;
	
	unsigned char mask = 0x1;
	return mask & combine_2;
}

void test_any_even_one()
{
	unsigned y = 0x87654321;
	printf("%u -> %d\n", y, any_even_one(y));
	
	y = 0x8765432;
	printf("%u -> %d\n", y, any_even_one(y));

	y = 0x7;
	printf("%u -> %d\n", y, any_even_one(y));

	y = 0x8;
	printf("%u -> %d\n", y, any_even_one(y));
	
	y = 0xA;
	printf("%u -> %d\n", y, any_even_one(y));

	y = 0xB;
	printf("%u -> %d\n", y, any_even_one(y));

	y = 0xC;
	printf("%u -> %d\n", y, any_even_one(y));
	
	y = 0xD;
	printf("%u -> %d\n", y, any_even_one(y));

	y = 0xE;
	printf("%u -> %d\n", y, any_even_one(y));
}

int main()
{
	test_any_even_one();
	return 0;
}
