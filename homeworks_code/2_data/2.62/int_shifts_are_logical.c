#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char *byte_pointer;

int is_any_bit_eq_zero(int x)
{
	return !(!(~x));
}

int int_shifts_are_logical()
{
	/* Example: x = 1111 1111 1111 1111 (32-bit)
	   right shitf: 
		arith: 1111 1111 1111 1111 
	    logical: 0111 1111 1111 1111 
	*/
	int x = -1;
	x = x>>1;
	// if any bit of x equals 0, then it is logical
	return is_any_bit_eq_zero(x); 

	/* notes: 更直接的方式是判断x不等于－1，用inequality(!=)运算 */
}

void test_shifts()
{
	printf("%d\n", int_shifts_are_logical());
}

int main()
{
	test_shifts();
	return 0;
}