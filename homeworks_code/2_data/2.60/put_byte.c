#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char *byte_pointer;

unsigned put_byte(unsigned x, unsigned char b, int i) 
{
	/* should check i? */
	byte_pointer start = (byte_pointer)&x + i;
	/* replace the ith byte with b */ 
	*start = b;  // asignment
	return x;
}

void test_put_byte()
{
	printf("%x\n", put_byte(0x12345678, 0xAB, 2));
	printf("%x\n", put_byte(0x12345678, 0xAB, 0));
}

int main()
{
	test_put_byte();
	return 0;
}