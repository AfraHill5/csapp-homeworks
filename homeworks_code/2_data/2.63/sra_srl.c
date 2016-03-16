#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MIN 1<<(8*sizeof(int)-1)
#define INT_SIZE (8*sizeof(int))

int sra(int x, int k)
{
	/* Perform shift logically */
	int xsrl = (unsigned) x >> k;
	
	int sign = ((-1)&INT_MIN) & x;
	int sign_seq = ~(!sign * -1);
	int mask = sign_seq << (INT_SIZE-k);
	xsrl = xsrl | mask;
	
	return xsrl;
	
}

unsigned srl(unsigned x, int k)
{
	/* Perform shift arithmetically */
	unsigned xsra = (int) x >> k;
	
	/* Left shift a bit seq of 1. */
	int mask = ~(-1 << (8*sizeof(int) - 1));
	xsra = xsra & mask;

	return xsra;
}

void test_sra()
{
	int x = -1;
	int k = 3;
	printf("sra: ");
	printf("%x >> %d => %x\n", x, k, sra(x,k));
}

void test_srl()
{
	unsigned x = 1<<(8*sizeof(int)-1);
	int k = 3;
	
	printf("srl: ");
	printf("%x >> %d => %x\n", x, k, srl(x,k));
	
}

int main()
{
	test_sra();
	test_srl();
	return 0;
}