/* Practice Problem 3.27, p.246
 */

int test(int x, int y)
{
	int val = x + y;
	if (y > 0) {
		if (x < y) {
			val = y - x;
		} else {
			val = x ^ y;
		}
	} else if (y >= -2) {
		val = 4 * y;
	}
	return val;
}

/*
int test_2(int x, int y)
{
	int val;
	if (y > 0) {
		if (x < y) {
			val = y - x;
		} else {
			val = x ^ y;
		}
	} else if (y >= -2) {
		val = 4 * y;
	} else {
		val = x + y;
	}
	return val;
}


int test_3(int x, int y)
{
	int val;
	if (y > 0) {
		val = (x < y ? y - x : x ^ y);
	} else {
		val = (y >= -2 ? 4 * y : x + y);
	}
	return val;
}


int test_4(int x, int y)
{
	return (y > 0
			? (x < y ? y - x : x ^ y)
			: (y >= -2 ? 4 * y : x + y));
}

*/
