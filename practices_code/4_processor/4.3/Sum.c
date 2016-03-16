int rSum(int *Start, int Count)
{
	int sum = 0;
	while (Count) {
		sum += *Start;
		Start++;
		Count--;
	}
	return sum;
}
