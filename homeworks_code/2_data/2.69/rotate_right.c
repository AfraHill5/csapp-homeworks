#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned rotate_right(unsigned x, int n)
{
	unsigned m = ((1 << n) - 1) & x;
	/* Assume w=32 */
	m = m << (32 - n);
	/* logical right shift */
	x = (unsigned) x >> n;
	x = x | m;
	return x;
}

void test_rotate_right()
{
	unsigned x = 0x12345678;
	
	int n = 4;
	printf("x = %x, n = %d -> %x\n", x, n, rotate_right(x, n));
	
	n = 20;
	printf("x = %x, n = %d -> %x\n", x, n, rotate_right(x, n));
}

int main()
{
	test_rotate_right();
	return 0;
}