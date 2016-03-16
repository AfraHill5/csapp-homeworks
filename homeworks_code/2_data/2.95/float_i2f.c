#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*   */

typedef unsigned char *byte_pointer;

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

/*   */

typedef unsigned float_bits;
unsigned roundz(unsigned x, unsigned k);
unsigned absz(int i);
unsigned leftmost_one(unsigned x);
unsigned log2_inverse(unsigned x);

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
		unsigned order = log2_inverse(leftmost_one(abs_i)); 
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

unsigned log2_inverse(unsigned x)
{
	/* 2^i = x => compute i */
	unsigned i = 0;
	while(x > 1) {
		x = x >> 1;
		i = i + 1;
	}
	return i;
}

void test_log2_inverse()
{
	unsigned x = 0x00100000;
	printf("%x -> %u\n", x, log2_inverse(x));
	
	x = 0x0010000;
	printf("%x -> %u\n", x, log2_inverse(x));
	
	x = 0x00800000;
	printf("%x -> %u\n", x, log2_inverse(x));
	
	x = 0x020FE92;
	unsigned LMO = leftmost_one(x);
	printf("x = %x, LMO = %x, order = %d\n", x, LMO, log2_inverse(LMO)); 
	
	x = 0x0D0FE92;
	LMO = leftmost_one(x);
	printf("x = %x, LMO = %x, order = %d\n", x, LMO, log2_inverse(LMO)); 
}

void test_absz()
{
	int i = -2;
	printf("|%d| = %u\n", i, abs(i));
	
	i = 3;
	printf("|%d| = %u\n", i, abs(i));
	
	i = -1024;
	printf("|%d| = %u\n", i, abs(i));
	
	i = 1234;
	printf("|%d| = %u\n", i, abs(i));
}

void test_float_i2f()
{
	printf("\nCalling float_i2f...\n");
	
	int x = 1024;
	printf("\n%d:\n", x);
	printf("Builtin: ");
	show_float((float) x);
	printf("float_i2f: %x\n", float_i2f(x));
	
	x = -1024;
	printf("\n%d:\n", x);
	printf("Builtin: ");
	show_float((float) x);
	printf("float_i2f: %x\n", float_i2f(x));
	
	x = 54675;
	printf("\n%d:\n", x);
	printf("Builtin: ");
	show_float((float) x);
	printf("float_i2f: %x\n", float_i2f(x));
	
	x = 80239;
	printf("\n%d:\n", x);
	printf("Builtin: ");
	show_float((float) x);
	printf("float_i2f: %x\n", float_i2f(x));
	
	x = -56290;
	printf("\n%d:\n", x);
	printf("Builtin: ");
	show_float((float) x);
	printf("float_i2f: %x\n", float_i2f(x));
}

int main()
{
	test_log2_inverse();
	test_absz();
	test_float_i2f();
	
	return 0;
}