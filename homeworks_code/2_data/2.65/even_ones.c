#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char *byte_pointer;

unsigned srl(unsigned x, int k)
{
	/* Perform shift arithmetically */
	unsigned xsra = (int) x >> k;
	
	unsigned m = (unsigned) ~(-1 << (8*sizeof(int)-1));
	xsra = xsra & m;
	return xsra;
}

/* Return 1 when x contains an even number of 1s; 0 otherwise.
   Assume w=32 */
int even_ones(unsigned x)
{
	byte_pointer first = (byte_pointer)&x;
	byte_pointer second = first + 1;
	byte_pointer third = second + 1;
	byte_pointer fourth= third + 1;
	
	unsigned char a = ((*first ^ *second) ^ *third) ^ *fourth;
	
	//printf("== %u, %x\n", a, a);
	
	unsigned char b = a << 4;
	unsigned char c = a ^ b;
	unsigned char d = c << 2;
	unsigned char e = c ^ d;
	unsigned char f = e << 1;
	unsigned char g = e ^ f;
	
	unsigned char m = 128;
	return !(m & g);
	
	/* 14 operations */ 
}

int even_ones_b(unsigned x)
{	
	unsigned a = x ^ (x >> (8*sizeof(unsigned)/2));	
	a = a ^ (a >> 8*sizeof(char));
	
	// printf("== %u, %x\n", a, a);
	
	unsigned char b = a >> 4;
	unsigned char c = a ^ b;
	unsigned char d = c >> 2;
	unsigned char e = c ^ d;
	unsigned char f = e >> 1;
	unsigned char g = e ^ f;
	
	unsigned char m = 1;
	return !(m & g);
	
	/* 15 operations */ 
}

/* Return 1 when x contains an even number of 1s; 0 otherwise.
   Assume w=32 */
int even_ones_c(unsigned x)
{	
	unsigned y = x >> 16;
	unsigned z = x ^ y;
	
	unsigned n = z >> 8;
	unsigned a = n ^ z;	
	 
	unsigned char b = a >> 4;
	unsigned char c = a ^ b;
	unsigned char d = c >> 2;
	unsigned char e = c ^ d;
	unsigned char f = e >> 1;
	unsigned char g = e ^ f;
	
	unsigned char m = 1;
	return !(m & g);
	
	/* 12 operations */ 
}

void test_even_ones()
{
	unsigned y = 0x87654321;
	printf("%u -> %d\n", y, even_ones(y));
	
	y = 0x8765432;
	printf("%u -> %d\n", y, even_ones(y));

	y = 0x7;
	printf("%u -> %d\n", y, even_ones(y));

	y = 0x8;
	printf("%u -> %d\n", y, even_ones(y));
	
	y = 0xA;
	printf("%u -> %d\n", y, even_ones(y));

	y = 0xB;
	printf("%u -> %d\n", y, even_ones(y));

}

void test_even_ones_b()
{
	unsigned y = 0x87654321;
	printf("%u -> %d\n", y, even_ones_b(y));
	
	y = 0x8765432;
	printf("%u -> %d\n", y, even_ones_b(y));

	y = 0x7;
	printf("%u -> %d\n", y, even_ones_b(y));

	y = 0x8;
	printf("%u -> %d\n", y, even_ones_b(y));
	
	y = 0xA;
	printf("%u -> %d\n", y, even_ones_b(y));

	y = 0xB;
	printf("%u -> %d\n", y, even_ones_b(y));

}

void test_even_ones_c()
{
	unsigned y = 0x87654321;
	printf("%u -> %d\n", y, even_ones_c(y));
	
	y = 0x8765432;
	printf("%u -> %d\n", y, even_ones_c(y));

	y = 0x7;
	printf("%u -> %d\n", y, even_ones_c(y));

	y = 0x8;
	printf("%u -> %d\n", y, even_ones_c(y));
	
	y = 0xA;
	printf("%u -> %d\n", y, even_ones_c(y));

	y = 0xB;
	printf("%u -> %d\n", y, even_ones_c(y));

}

int main()
{
	printf("Calling even_ones:\n");
	test_even_ones();
	
	printf("Calling even_ones_b:\n");
	test_even_ones_b();
	
	printf("Calling even_ones_c:\n");
	test_even_ones_c();
	
	return 0;
}