/* Practice Problem 3.17, p.230
 *
 */

int absdiff(int x, int y)
{
	int result;
	if (x < y)
		goto true_cond;
	result = x - y;
	goto d;

	true_cond:
		result = y - x;

	d:
		return result;
}
