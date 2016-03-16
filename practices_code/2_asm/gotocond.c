/* Practice Problem 3.16, p.229
 *
 */

void gotocond(int a, int *p)
{
	if (!p)
		goto done;
	if (a <= 0)
		goto done;
	*p = *p + a;
 done:
	;
}
