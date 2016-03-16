/* Homeworks 3.54, p.328 
 * compile to IA32: clang -O1 -S -m32 decode2.c
 */


int decode2(int x, int y, int z)
{
	z = z - y;

	int result = z;
	result = result << 15;
	result = result >> 15;

	z = x ^ z;

	return z * result;
}
