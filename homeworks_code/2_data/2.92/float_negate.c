#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned float_bits;

const unsigned UMax = -1;

float_bits float_negate(float_bits f)
{
	/* float: |31|30-23|22-0| */
	unsigned sign = f>>31;
	unsigned exp = f>>23 & 0xFF;
	unsigned frac = f & 0x7FFFFF;
	
	if (!(exp == ((1<<8) - 1) && frac == 0)) {
		/* Not a NaN, compute |f| */
		sign = (unsigned) (!sign); /* 0|1 -> 1|0 */		
		return (sign << 31) | f;
	} else {
		/* NaN, return f */
		return f;
	}
}



void test_float_absval()
{
	// unsigned one = 1;
	// unsigned UMax = (one<<31) + ((one<<31) - 1);  /* or -1 */
	// printf("UMax = %u, %u\n", UMax, -1); 
	
	for (int i=0; i <= UMax; i++) // oveflow
	{
		
	}	
}

int main()
{
	/* run tests */
	test_float_absval();
	
	return 0;
}