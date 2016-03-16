#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Divide by power of two.   Assume 0 <= k < w-1 */
int divide_power2(int x, int k)
{
	size_t int_size = 8*sizeof(int);
	int is_negative = 0 - (x >> (int_size - 1));
	int bias = (1 << k) - 1;
	 
	return (x + bias * is_negative) >> k   
}