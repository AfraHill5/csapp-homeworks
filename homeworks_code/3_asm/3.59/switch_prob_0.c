int switch_prob(int x, int n)
{
	int result = x;

	switch(n) {
	case 28:
		// asm:42
		result = result << 3;
		break;
		
	case 29:
		// asm:35
		result += 0x11;
		break;

	case 30:
		// asm:42
		result = result << 3;
		break;
		
	case 31:
		// asm:4a
		result = result >> 3;
		break;

	case 32:
		// asm:52
		result = (((x << 3) - x) * ((x << 3) - x)) + 0x11;
		break;
		
	case 33:
		// asm:3a
		result = x * x + 0x11;
		break;
		
	default:
		result += 0x11;
	}
	return result;
}
