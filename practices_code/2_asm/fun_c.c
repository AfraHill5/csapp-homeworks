/* Practice Problem 3.49, p.315
 */

#include <stdio.h>

long fun_c(unsigned long x)
{
	long val = 0;
	int i;
	for (i = 0; i < 8; i++) {
		val = val + (x & 0x101010101010101);
		x = x >> 1;
	}
	val = val + (val >> 32);
	val = val + (val >> 16);
	val = val + (val >> 8);

	return val & 0x1111111;
}
		
	
