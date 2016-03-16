/* Practice Problem 3.45, p.298
 */

#include <stdio.h>
#include <string.h>

int len(char *s) {
	return strlen(s);
}

void iptoa(char *s, int *p)
{
	int val = *p;
	sprintf(s, "%d", val);
}

int intlen(int x)
{
	int v;
	char buf[12];
	v = x;
	iptoa(buf, &v);
	return len(buf);
}

int main()
{
	int x;

	x = 1234;
	printf("%d -> %d\n", x, intlen(x));

	x = 1234567;
	printf("%d -> %d\n", x, intlen(x));	

	return 0;
}
