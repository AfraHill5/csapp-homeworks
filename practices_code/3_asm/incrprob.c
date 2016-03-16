/* Practice Problem 3.50, p.318
 */


void incrprob(int x, long int* q, int* t)
{

	*t += x;
	*q += *t;
}

void incrprob_4(unsigned int x, long int* q, int* t)
{

	*t += x;
	*q += *t;
}

void incrprob_1(int x, unsigned long int* q, int* t)
{
	*t += x;
	*q += *t;
}

void incrprob_5(unsigned int x, unsigned long int* q, int* t)
{
	*t += x;
	*q += *t;
}
