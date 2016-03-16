#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char *byte_pointer;

/* Get most significant byte from x */
int get_msb(int x)
{
	/* Shift by w-8 */
	int shift_val = (sizeof(int)-1) << 3;
	/* Arithmetic shift */
	int xright = x >> shift_val;
	/* Zero all but LSB */
	return xright & 0xFF;
}

/* Get least significant byte from x */
int get_lsb(int x)
{
	/* Zero all but LSB */
	return x & 0xFF;
}

/* 尝试去掉casting */
/* 
int is_big_endian()
{
	typedef unsigned char *byte_pointer;
	int ival = 1;
	byte_pointer start = (byte_pointer)&ival;
	return start[0];
}

char get_msb_byte(int x)
{
	size_t int_size = sizeof(int);

}
*/


int main(int argc, char const *argv[])
{
	int x = 0x00ABCD00;

	/* A */
	int val_a = !(!(x));

	/* B */
	int val_b = !(!(~x));

	/* C */
	char x_msb = (char) get_msb(x); // casting, is it perimited?
	int val_c = !(!x_msb);

	/* D */
	char x_lsb = (char) get_lsb(x);
	int val_d = !(!(~x_lsb));

	printf("%d\n", val_a);
	printf("%d\n", val_b);
	printf("%d\n", val_c);
	printf("%d\n", val_d);
	return 0;
}