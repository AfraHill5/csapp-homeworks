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