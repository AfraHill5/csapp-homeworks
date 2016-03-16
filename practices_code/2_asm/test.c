/* Practice Problem 3.18, p.230
 *
 */

 int test(int x, int y)
 {
 	int val = x;
 	if (val >= -3) {
 		if (val > 2)
 			val = y - val;
 		else
 			val = y ^ val;
 	} else if (val <= y) 
 		val = val + y;
 	return val;
 }
