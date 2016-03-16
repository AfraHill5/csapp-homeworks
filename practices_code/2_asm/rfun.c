/* Practice Problem 3.27, p.246
 */

#include <stdio.h>

/* Add bits to a integer */
int rfun(unsigned x)
{
	if (x == 0)
		return 0;

	unsigned nx = x >> 1;
	int rv = rfun(nx);
	
	return (x & 1) + rv;
}

int rfun_2(unsigned x)
{
	if (x == 0)
		return 0;

	unsigned nx = x >> 1;
	int rv = rfun(nx);
	
	return (x & 1) ^ rv;
}

int main()
{
	unsigned x;

	x = 10;
	printf("%d\n", rfun(x));

    x = 7;
	printf("%d\n", rfun(x));

	x = 15;
	printf("%d\n", rfun(x));	

	return 0;
}
