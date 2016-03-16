/* Practice Problem 3.19, p.232
 *
 */

#include <stdio.h>

/* Determine whether multiplying arguments will cause overflow */
int tmul_ovf(int x, int y)
{
	return 0;
} 

int test_fact()
{
	int INT_MAX = (unsigned) ~0 >> 1;
	

	printf("%d\n", INT_MAX);
	
	int i = 0;
	long long int n = 1;
	do {
		i = i + 1;
		n = n * i;
		printf("%d! = %lld\n", i, n);
	} while (n <= INT_MAX);
	return i;
	
}


int main()
{
	int n = test_fact();
	printf("max value = %d\n", n);
	return 0;
}
