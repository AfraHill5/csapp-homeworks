int var_prod_ele(int n, int A[n][n], int B[n][n], int i, int k)
{
	int j;
	int result = 0;

	for (j = 0; j < n; j++)
		result += A[i][j] * B[j][k];

	return result;
}
