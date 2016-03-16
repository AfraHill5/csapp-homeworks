	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_decode2
	.align	4, 0x90
_decode2:                               ## @decode2
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	movl	16(%ebp), %eax
	subl	12(%ebp), %eax
	movl	%eax, %ecx
	shll	$15, %ecx
	sarl	$15, %ecx
	xorl	8(%ebp), %eax
	imull	%ecx, %eax
	popl	%ebp
	retl


.subsections_via_symbols
