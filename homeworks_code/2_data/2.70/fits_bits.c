#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fits_bits(int x, int n)
{
	int y = (int) x >> (n - 1);
	return y == 0 || y == -1;
}

void test_fits_bits()
{
	int x = 0xFFFFFFFF;
	
	int n = 8;
	printf("x = %x, n = %d -> %d\n", x, n, fits_bits(x, n));
	
	x = 0x1FFFFFF;
	n = 8;
	printf("x = %x, n = %d -> %d\n", x, n, fits_bits(x, n));
}

int main()
{
	test_fits_bits();
	return 0;
}

