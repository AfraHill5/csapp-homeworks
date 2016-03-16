#include <stdio.h>

typedef unsigned char *byte_pointer;
typedef unsigned float_bits;
unsigned roundz(unsigned x, unsigned k);
unsigned absz(int i);
unsigned leftmost_one(unsigned x);
unsigned log2z(unsigned x);

/**************************************************************/


void show_bytes(byte_pointer start, size_t len) {
	int i;
	for (i = 0; i < len; i++)
		printf(" %.2x", start[i]);    //line:data:show_bytes_printf
	printf("\n");
}

void show_int(int x) {
	show_bytes((byte_pointer)&x, sizeof(int)); //line:data:show_bytes_amp1
}

void show_float(float x) {
	show_bytes((byte_pointer)&x, sizeof(float)); //line:data:show_bytes_amp2
}

/**************************************************************/

/* Compute (float) i */
float_bits float_i2f(int i)
{
	/* i = normalized or 0 */
	if (i != 0) {
		/* V=(-1)^S*M*2^E */
		unsigned bias = 127;
		unsigned k = 8;
		unsigned n = 23;
		
		/* S=sign */
		unsigned sign = i>>31;  
				
		/* E=order -> exp */
		unsigned abs_i = absz(i);
		unsigned order = log2z(leftmost_one(abs_i)); 
		unsigned exp = order + bias;
		
		/* M=1+f */		
		unsigned frac;
		if (order > n) {
			/* Right shift & Rounding to even */
			unsigned M = roundz(abs_i, order-n);
			frac = M - (1<<n); /* remove the implied 1 */
		} else {
			/* Left shift to the right place */
			unsigned M = abs_i << (n-order);
			frac = M - (1<<n); /* remove the implied 1 */
		}
		
		return (sign<<31) | (exp<<23) | frac;
	} else {
		return 0;
	}
}

unsigned roundz(unsigned x, unsigned k)
{
	/* Rounding to even
	 * x = 0100 1000 1001 0000 , k = 5 -> x = 0100 1000 1000 0000, 舍去
	 * x = 0100 1000 1011 0000 , k = 5 -> x = 0100 1000 1100 0000, 进位 
	 */
	unsigned major = x >> k;
	unsigned reminder = x & ((1<<k)-1);
	
	if (reminder == (1<<(k-1))) {
		/* At the middle. Rounding to even */
		unsigned last_bit = x>>k & 0x1;
		if (last_bit == 1) {
			/* promote */
			return major + 1; 		
		} else {
			return major;
		}
	} else if  (reminder > (1<<(k-1))) {
		return major + 1;
	} else {
		return major;
	}
}

unsigned absz(int i)
{
	if (i < 0) {
		return ~i+1;
	} else {
		return i;
	}
}

unsigned leftmost_one(unsigned x)
{
	/* 获取masking code，表示一个二进制序列最左位的1.
	 * input: 01010101
	 * output: 01000000
	 *
	 * input: 00111001
	 * output: 00100000
	 */
	unsigned m;
	
	m = x >> 1;
	x = x | m;
	
	m = x >> 2;
	x = x | m;
	
	m = x >> 4;
	x = x | m;
	
	m = x >> 8;
	x = x | m;
	
	m = x >> 16;
	x = x | m;
	
	return (x >> 1) + 1;	
}

unsigned log2z(unsigned x)
{
	/* 2^i = x => compute i */
	unsigned i = 0;
	while(x > 1) {
		x = x >> 1;
		i = i + 1;
	}
	return i;
}

/**************************************************************/


/* Compute (int) f.
 * If conversion causes overflow or f is NaN, return 0x80000000
 */
int float_f2i(float_bits f)
{
	 unsigned sign = f>>31 & 0x1;
	 unsigned exp = f>>23 & 0xFF;
	 unsigned frac = f & 0x7FFFFF;
	 
	 unsigned bias = 127;
	 int E = exp - bias;
	 
	 if (E < 0) {
		 /* Rounding to zero */
		 return 0;
	 } else if (E == 0) {
		 /* Rounding to 1 or -1 */
		 return (-1) * sign;
	 } else if (E <= 31 & sign == 0) {
		 /* f is positive */
		 unsigned M = frac + (1<<23);
		 /* Rounding to zero with right shits */		 
		 unsigned V = M>>(23-E);
		 return V;		 		 		 
	 } else if (E <= 32 & sign == 1) {
		 /* f is negative */
		 unsigned M = frac + (1<<23);
		 /* Rounding to zero with right shits */		 
		 int V = M>>(23-E);
		 return ~V+1; /* negate */
	 } else {
		 /* overflow or NaN */
		 return 0x80000000;
	 }
}
 
/* test */

void test_float_f2i()
{	
	int x = -4893;
	float_bits i2f = float_i2f(x);
	float_bits f2i = float_f2i(i2f);
	printf("\nx = %d ==> \n", x);
	printf("\ti2f = %x\n", i2f);
	printf("\tf2i = %x, %d\n", f2i, f2i);
	
	x = -56290;
	i2f = float_i2f(x);
	f2i = float_f2i(i2f);
	printf("\nx = %d ==> \n", x);
	printf("\ti2f = %x\n", i2f);
	printf("\tf2i = %x, %d\n", f2i, f2i);
	
	x = 56290;
	i2f = float_i2f(x);
	f2i = float_f2i(i2f);
	printf("\nx = %d ==> \n", x);
	printf("\ti2f = %x\n", i2f);
	printf("\tf2i = %x, %d\n", f2i, f2i);

	/* */
	x = -56290;
	i2f = float_i2f(x) | 0xF00; /* 修改bit patterns */
	f2i = float_f2i(i2f);
	printf("\nx = %d ==> \n", x);
	printf("\ti2f = %x\n", i2f);
	printf("\tf2i = %x, %d\n", f2i, f2i);
	
	x = 56290;
	i2f = float_i2f(x) | 0xF00; /* 修改bit patterns */
	f2i = float_f2i(i2f);
	printf("\nx = %d ==> \n", x);
	printf("\ti2f = %x\n", i2f);
	printf("\tf2i = %x, %d\n", f2i, f2i);
}
 
 int main()
 {
	 printf("\nCalling float_f2i...\n");
	 test_float_f2i();
	 return 0;
 }
