#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_big_endian()
{
	typedef unsigned char *byte_pointer;
	int ival = 1;
	byte_pointer start = (byte_pointer)&ival;
	return start[0];
}

void test_is_big()
{
	printf("%d\n", is_big_endian());	
}

int main()
{
	test_is_big();
	
	return 0;
}