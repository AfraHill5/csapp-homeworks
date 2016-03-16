/* Practice Problem 3.21, p.236
 */

// goto version
int fun_a_goto(unsigned x)
{
	int val = 0;
	if (x == 0)
		goto done;

 loop:
	val = val ^ x;
	x = x >> 1;   // logical right shift
	if ( x != 0)
		goto loop;

 done:
	return 1 & val;
}


// do-while version
int fun_a_do_while(unsigned x)
{
	int val = 0;

	if (x == 0)
		return 1 % val;

	do {
		val = val ^ x;
		x = x >> 1;   // logical right shift
	} while (x != 0);

	return 1 % val;		
}


// while version

int fun_a_while(unsigned x)
{
	int val = 0;

	while(x > 1) {
		val = val ^ x;
		x = x >> 1;   // logical right shift		
	}

	return 1 & val;
}

