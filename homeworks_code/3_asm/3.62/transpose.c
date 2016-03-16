#include <stdio.h>

#define M 8
void exchange(int*, int*);

void transpose_opt(int A[M][M])
{
	int *DiagPtr;
	int *ColPtr;
	int *RowPtr;

	int i, j;
	
	for (i = 0; i < M; i++) {
		DiagPtr = &A[0][0] + i * (M + 1);
		ColPtr = DiagPtr;
		RowPtr = DiagPtr;
		
		for (j = i; j < M; j++) {
			exchange(ColPtr, RowPtr);
			ColPtr += 1;
			RowPtr += M;
		}
	}
}

/* Helpers*/

void exchange(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void print_matrix(int m[M][M])
{
	int i, j;
	
	for(i = 0; i < M; i++) {
		for (j = 0; j < M; j++) {
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}


/* TEST */

void test_exchange()
{
	int a = 0;
	int b = 1;

	exchange(&a,&b);
	printf("%d, %d\n", a, b);
}
	
int main()
{
	int matrix[M][M] = {{0,1,2,3,4,5,6,7},
						{0,1,2,3,4,5,6,7},
						{0,1,2,3,4,5,6,7},
						{0,1,2,3,4,5,6,7},
						{0,1,2,3,4,5,6,7},
						{0,1,2,3,4,5,6,7},						
						{0,1,2,3,4,5,6,7},
						{0,1,2,3,4,5,6,7}};

	printf("Before:\n");
	print_matrix(matrix);

	transpose_opt(matrix);

	printf("After:\n");	
	print_matrix(matrix);
	
	return 0;
}
