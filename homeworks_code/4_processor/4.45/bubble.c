#include <stdio.h>

int print_arr(int *arr, int count) {
	for (int i = 0; i < count; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}


/* Bubble sort: Array version */
void bubble_a(int *data, int count) {
	int i, next;
	for (next = 1; next < count; next++) {
		for (i = next-1; i >= 0; i--) {
			if (data[i+1] < data[i]) {
				int t = data[i+1];
				data[i+1] = data[i];
				data[i] = t;
			}
		}
	}
}

void bubble_p(int *data, int count) {
	int *beg = data;
	int *end = data + count;

	int *i, *next;
	for (next = beg+1; next < end; next++) {
		for (i = next-1; i >= beg; i--) {
			if (*(i+1) < *(i)) {
				int t = *(i+1);
				*(i+1) = *(i);
				*(i) = t;
			}
		}
	}
}

int main()
{
	int a[5] = {5,2,4,3,1};

	printf("::bubble_a::\n");
	printf("before:\n");
	print_arr(a, 5);

	bubble_a(a, 5);

	printf("after:\n");
	print_arr(a, 5);

	int b[5] = {9,6,8,7,5};

	printf("::bubble_b::\n");
	printf("before:\n");
	print_arr(b, 5);

	bubble_p(b, 5);

	printf("after:\n");
	print_arr(b, 5);

}
