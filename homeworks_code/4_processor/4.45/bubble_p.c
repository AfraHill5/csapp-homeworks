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
	int b[5] = {9,6,8,7};

	bubble_p(b, 4);

	return 0;
}