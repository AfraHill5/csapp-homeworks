/* Practice Problem 3.33, p.262
 */

#include <stdio.h>

int proc(void)
{
	int x, y;
	scanf("%x %x", &y, &x);
	return x - y;
}

int main()
{
	printf("%x\n", proc());
	return 0;
}
