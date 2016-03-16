#include <stdio.h>

int print_arr(int *arr, int count) {
	for (int i = 0; i < count; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}