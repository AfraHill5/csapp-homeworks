#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned float_bits;

float_bits float_twice(float_bits f)
{
	/* float: |31|30-23|22-0| */
	unsigned sign = f>>31;
	unsigned exp = f>>23 & 0xFF;
	unsigned frac = f & 0x7FFFFF;
	
	if (exp == 0 && frac == 0) {
		/* zero */
	} else if (exp == 0 && frac != 0) {
		/* denorm. benefit from the format */
		frac = frac << 1;
		return (sign<<31) | exp | frac;
	} else if (exp < (1<<8-2)) {
		/* norm */
		exp = exp + 1;
		return (sign<<31) | exp | frac;
	} else if (frac == 0){
		/* infinity */
		exp = exp + 1;
		return (sign<<31) | exp | frac;
	} else {
		/* NaN */
		return f;
	}	
}

void test_float_twice()
{
	;
}

int main()
{
	test_float_twice();
	return 0;
}