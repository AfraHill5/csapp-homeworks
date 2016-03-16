/* Practice Problem 3.27, p.246
 */

#include <stdio.h>

#define N 4
typedef int fix_matrix[N][N];

void fix_set_diag_opt(fix_matrix A, int val)
{
	int *ptr = &A[0][0];
	int i;
	for (i = 0; i != N; i++) {
		*ptr = val;
		ptr += N + 1;
	}
}

void print_matrix(fix_matrix fm)
{
	for (int i = 0; i != N; i++) {
		for (int j = 0; j != N; j++) {
			printf("%d ", fm[i][j]);
		}
		printf("\n");
	}
}
	
int main()
{
	fix_matrix fm = {{0,1,2,3}, {4,5,6,7},{0,1,2,3}, {4,5,6,7}};
	int val = 9;
	
	printf("\nbefore:\n");
	print_matrix(fm);

	fix_set_diag_opt(fm, val);

	printf("\nafter:\n");
	print_matrix(fm);

	return 0;
}


