int Sum(int *Start, int Count)
{
	int sum = 0;
	while (Count) {
		if (*Start < 0)
			sum = sum - *Start;
		else
			sum = sum + *Start;
		Start++;
		Count--;
	}
	return sum;
}
