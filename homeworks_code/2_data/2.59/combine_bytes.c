#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int combine_bytes(long int x, long int y)
{
	return (x & (~0 - 0xFF)) | (y & 0xFF);
}

void test_combine_bytes()
{
	long int x = 0x89ABCDEF;
	long int y = 0x76543210;
	printf("%x\n", combine_bytes(x,y));
}

int main()
{
	test_combine_bytes();
	
	return 0;
}