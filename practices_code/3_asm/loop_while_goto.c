/* Practice Problem 3.21, p.236
 */

int loop_while_goto(int a, int b)
{
	int result = 1;
	if(a >= b)
		goto done;
	int c = a + b;

 loop:
	result *= c;
	a += 1;
	c += 1;
	if (a < b)
		goto loop;
	
 done:
	return result;
}
