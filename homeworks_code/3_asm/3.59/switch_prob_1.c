int switch_prob(int x, int n)
{
	int result = x;

	switch(n) {
	case 0x2d:
		// asm:3a
		result *= x ;
		result += 0x11;	
		break;

	case 0x28:
	case 0x2a:
		// asm:42
		result = result << 3;
		break;
		
	case 0x2b:
		// asm:4a
		result = result >> 3;
		break;

	case 0x2c:
		// asm:52
		result *= 7;
		result *= result;
				
	default:
		// asm:35	
		result += 0x11;
	}
	return result;
}
