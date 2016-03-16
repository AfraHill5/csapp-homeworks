void decode1(int *xp, int *yp, int *zp)
{
	int x = *xp;
	int y = *yp;
	int z = *zp;

	*xp = y;
	*yp = z;
	*zp = x;
}
