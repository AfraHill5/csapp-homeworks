	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_simple_l
	.align	4, 0x90
_simple_l:                              ## @simple_l
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %ecx
	movl	(%ecx), %eax
	addl	12(%ebp), %eax
	movl	%eax, (%ecx)
	popl	%ebp
	retl


.subsections_via_symbols
