
int switch_prob(int x, int n)
{
	int result = x;

	switch(n) {
	case 28:
		// 42
		result = result << 3;
		break;
		
	case 29:
		// 35
		result += 0x11;
		break;

	case 30:
		// 42
		result = result << 3;
		break;
		
	case 31:
		// 4a
		result = result >> 3;
		break;

	case 32:
		// 52
		result = (((x << 3) - x) * ((x << 3) - x)) + 0x11;
		break;
		
	case 33:
		// 3a
		result = x * x + 0x11;
		break;
		
	default:
		;
	}
	return result;
}


int switch_prob_goto(int x, int n)
{
	static void *jt[5] = {
		&&loc_A, &&loc_def, &&loc_A,
		&&loc_D, &&loc_E
	}

	unsigned index = x - 0x28;
	int result = x;

	if (index > 0x5)
		goto &&loc_def;

	goto *jt[index];

 loc_def:
	result = result + 0x11;
	goto done;

 loc_D:
	reuslt = result * result + 0x11;
	goto done;

 loc_A:
	result = result << 3;
	goto done;

 loc_E:
	result = result >> 3;
	goto done;
	
 done:
	return result;
}
