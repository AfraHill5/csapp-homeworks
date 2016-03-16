/* Practice Problem 3.27, p.246
 */

int switcher(int a, int b, int c)
{
	int answer;
	switch(a) {
	case 5:     /* Case A */
		/* .L6 */
		c = b ^ 15;
		/* Fall through */
	case 0:     /* Case B */
		/* .L3 */
		answer = c + 112;
		break;
	case 2:     /* Case C */
	case 7:     /* Case D */
		/* .L4 */
		answer = (b + c) << 2;
		break;
	case 4:     /* Case E */
		/* .L5 */
		answer = 4;
		break;
	default:
		/* .L2 */
		answer = b;
	}
	return answer;
}
