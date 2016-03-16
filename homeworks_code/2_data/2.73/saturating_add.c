#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TMin = 1 << (8*sizeof(int) - 1);
int TMax = ((unsigned) 1 << (8*sizeof(int) - 1)) - 1;

int saturating_add(int x, int y)
{
	size_t size = 8*sizeof(int);

	/* TODO: remove the castings */
	int x_sign = (unsigned) x >> (size - 1); // obtain the first bit of x
	int y_sign = (unsigned) y >> (size - 1); // obtain the first bit of y
	int x_main = (unsigned) (x << 1) >> 1; // reminder of x
	int y_main = (unsigned) (y << 1) >> 1; // reminder of y
	unsigned promote = (x_main + y_main) >> (size - 1);
	
	/* 下面的设计很不错，有进步 */
	unsigned same_sign = !(x_sign ^ y_sign); // x_sign与y_sign一致
	unsigned normal = same_sign && !(x_sign ^ promote);   // sign一致，且sign与promote一致
	unsigned negative = same_sign && (x_sign == 1);       // sign一致，且sign为负

	/* x + y = a * (x + y) + b * TMin + c * TMax
	 * a, b, c = 0 or 1
	 */
	unsigned a = (!same_sign) || normal;       // normal
	unsigned b = !normal && negative;          // underflow
	unsigned c = !normal && !negative;         // overflow

	return a * (x + y) + b * TMin + c * TMax;
}

int saturating_add_a(int x, int y)
{
	size_t size = 8*sizeof(int);

	int x_sign = (unsigned) x >> (size - 1); // obtain the first bit of x
	int y_sign = (unsigned) y >> (size - 1); // obtain the first bit of y
	int xs = (unsigned) (x << 1) >> 1; // reminder of x
	int ys = (unsigned) (y << 1) >> 1; // reminder of y
	unsigned p = (xs + ys) >> (size - 1); 

	
	/* 下面的设计很不错，有进步 */
	unsigned same_sign = !(x_sign ^ y_sign);
	unsigned promote = !(x_sign ^ p);
	unsigned negative = (x_sign == 1);

	/* x + y = a * (x + y) + b * TMin + c * TMax
	 * a, b, c = 0 or 1
	 */
	unsigned a = (!same_sign) || (same_sign && promote);
	unsigned b = same_sign && !promote && negative;
	unsigned c = same_sign && !promote && !negative;
	
	return a * (x + y) + b * TMin + c * TMax;
}


/* This version violate the coding rules on p.154. It is more simple and understandable.*/
int saturating_add_b(int x, int y)
{
	int x1; // contains first bit of x
	int y1; // contains first bit of y
	int xs; // middle part of x
	int ys; // middle part of y
	 
	if ((x1 ^ y1) == 0) {
		if (~(xs ^ ys) != 0) {
			if (x1 == 1) {
				return TMin;
			} else {
				return TMax;
			}
		} else {
			return x + y;
		}
	} else {
		return x + y;
	}
}

void test_saturating_add()
{
	printf("TMin = %x; TMax = %x\n", TMin, TMax);
	
	int x, y;
	
	// underflow
	x = 0x87654321;
	y = 0x87654321;
	printf("%x + %x = %x\n", x, y, saturating_add(x,y));
	
	// overflow
	x = 0x77654321;
	y = 0x77654321;
	printf("%x + %x = %x\n", x, y, saturating_add(x,y));

	x = 0x57654321;
	y = 0x77654321;
	printf("%x + %x = %x\n", x, y, saturating_add(x,y));	

	// normal	
	x = 0x07654321;
	y = 0x07654321;
	printf("%x + %x = %x\n", x, y, saturating_add(x,y));
}


void test_saturating_add_a()
{
	printf("TMin = %x; TMax = %x\n", TMin, TMax);
	
	int x, y;
	
	// underflow
	x = 0x87654321;
	y = 0x87654321;
	printf("%x + %x = %x\n", x, y, saturating_add_a(x,y));
	
	// overflow
	x = 0x77654321;
	y = 0x77654321;
	printf("%x + %x = %x\n", x, y, saturating_add_a(x,y));

	x = 0x57654321;
	y = 0x77654321;
	printf("%x + %x = %x\n", x, y, saturating_add_a(x,y));	

	// normal	
	x = 0x07654321;
	y = 0x07654321;
	printf("%x + %x = %x\n", x, y, saturating_add_a(x,y));
}

int main()
{
	test_saturating_add();
	test_saturating_add_a();
	return 0;
}

