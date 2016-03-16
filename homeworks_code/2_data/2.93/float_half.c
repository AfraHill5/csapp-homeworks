#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned float_bits;

const unsigned UMax = -1;

/* Compute 0.5*f.  If f is NaN or infinity, then return f */
float_bits float_half(float_bits f)
{
	/* float: |31|30-23|22-0| */
	unsigned sign = f>>31;
	unsigned exp = f>>23 & 0xFF;
	unsigned frac = f & 0x7FFFFF;
	
	if (exp == 0 && frac == 0) {
		/* zero */
		return 0;
	} else if (exp == 0 && frac > 0) {
		/* denormalized */
		frac = frac>>1;
		return (sign<<31) | (exp<<23) | frac;
	} else if (exp == 1) {
		exp = 0;
		frac = ((1<<23) + frac)>>1;
		return (sign<<31) | exp | frac);
	} else if (exp > 1) {
		exp = exp - 1;
		return (sign<<31) | exp | frac;
	} else if (exp == ((1<<8)-1) && frac == 0) {
		/* infinity */
		return f;
	} else {
		/* NaN */
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
}`