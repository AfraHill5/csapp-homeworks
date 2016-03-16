#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int signed_high_prod(int x, int y);
unsigned unsigned_high_prod(unsigned x, unsigned y);

int signed_high_prod(int x, int y)
{
	unsigned ux = (unsigned) x;
	unsigned uy = (unsigned) y;
	
	unsigned xs = (ux<<1) >> 1;
	unsigned ys = (uy<<1) >> 1;
	
	unsigned x_positive = !((unsigned) x >> (8*sizeof(int) - 1));
	unsigned y_positive = !((unsigned) y >> (8*sizeof(int) - 1));
	
	unsigned first_bit = (ux*uy)>>(w-1);
	
	int shp = (((unsigned_high_prod(x,y)<<1) + first_bit) - 2*x_positive*ys - 2*y_positive*xs) >>1;
	
	return shp;
}

unsigned unsigned_high_prod(unsigned x, unsigned y)
{
	
}