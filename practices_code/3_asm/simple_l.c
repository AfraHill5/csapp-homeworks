/* p.305
 */

long int simple_l(long int *xp, long int y)
{
	long int t = *xp + y;
	*xp = t;
	return t;
}
