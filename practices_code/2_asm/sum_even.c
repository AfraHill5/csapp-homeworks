/* Practice Problem 3.24, p.240
 */

// for-loop
int sum_even_for()
{
	int sum = 0;
	int i;
	for(i = 0; i < 10; i++) {
		if (i & 1)
			continue;
		sum += i;
	}
}

// while

int sum_even_while()
{
	int sum = 0;
	int i;

	i = 0;
 loop:
	while(i < 10) {
		if (i & 1)
			goto update;
		sum += i;
	}

 update:
	i++;
	goto loop;
	
}


		
		
