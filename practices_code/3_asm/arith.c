/* Practice Problem 3.26, p.246
 */

#include <stdio.h>

#define OP < 0 ? x : x /

int arith(int x)
{
	return x OP 4;
}

int main()
{
	printf("%d -> %d \n", 32, arith(32));
	return 0;
}
