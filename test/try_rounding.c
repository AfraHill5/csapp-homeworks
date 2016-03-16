#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	float A = 1e10;
	float pi = 3.14;
	printf("%f\n", A);
	printf("%f, %f\n", pi+A-A, pi+(A-A));
	
	
	printf("%f, %f\n", pi+A-A, pi+(A-A));
	
	printf("%d\n", sizeof(float));
	return 0;
}