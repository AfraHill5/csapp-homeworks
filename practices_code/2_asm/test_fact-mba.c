/* Practice Problem 3.19, p.232
 *
 */

/* Determine whether multiplying arguments will cause overflow */
int tmul_ovf(int x, int y)
{
	return 0;
} 

int test_fact()
{
	unsigned x = ~0 >> 1;
	int INT_MAX = (int) x;

	int i = 1;
	long long int n = 1;
	do {
		n = n * i;
		i = i + 1;
	} while (n <= INT_MAX);

	return n;
}


int main()
{
	int n = test_fact();
	printf("max value = %d\n", n);
	return 0;
}
