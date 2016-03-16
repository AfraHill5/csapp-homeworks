#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Clear all but least signficant n bits of x
 * Examples: x = 0x78ABCDEF, n = 8 --> 0xEF, n = 16 --> 0xCDEF
 * Assume 1 <= n <= w
 */
int lower_bits(int x, int n)
{
	/* Left shift */
	x = x << (8*sizeof(int) - n);
	/* Perform right shift logically */
	x = (unsigned) x >> (8*sizeof(int) - n);
	return x;
}

void test_lower_bits()
{
	int x = 0x78ABCDEF;
	int n = 8;
	
	printf("x = %x, n = %d --> %x\n", x, n, lower_bits(x, n));
	
	n = 16;
	printf("x = %x, n = %d --> %x\n", x, n, lower_bits(x, n));
	
	n = 32;
	printf("x = %x, n = %d --> %x\n", x, n, lower_bits(x, n));
}

int main()
{
	printf("Calling lower_bits:\n");
	test_lower_bits();
	return 0;
}