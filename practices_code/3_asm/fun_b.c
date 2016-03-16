/* Practice Problem 3.23, p.239
 */

// goto version
int  fun_b_goto(unsigned x)
{
	int val = 0;
	int i;

	// init-expr
	i = 0;
	// test-expr
	bool t = x < 32;
	if (!t)
		goto done;

 loop:
	// body-statement
	int y = 2 * val;
	val = x;
	val = 1 & val;
	val = y | val;
	x = x >> 1;

	// update-expr
	i++;
	if (t < 32)
		goto loop;
	
 done:
	return val;
}	

// goto version v2
int  fun_b_goto_v2(unsigned x)
{
	int val = 0;
	int i;

	// init-expr
	i = 0;
	// test-expr
	bool t = x < 32;
	if (!t)
		goto done;

 loop:
	// body-statement
	val = (val << 1) | (1 & x);	
	x = x >> 1;
	// update-expr
	i++;
	if (t < 32)
		goto loop;
	
 done:
	return val;
}	

/* 从以上loop-statement可以看出，该函数的作用是reverse x的bit位。
 */

// for-loop
int fun_b_for(unsigned x)
{
	int val = 0;
	int i;

	for (i = 0; i < 32; i++) {
		val = (val << 1) | (1 & x);
		x = x >> 1;
	}
	return val;
}

/* 虽然以上几个函数有一样的执行结果，但是后者在表述上更清晰。 
 */
