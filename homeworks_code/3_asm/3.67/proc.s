	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_proc
	.align	4, 0x90
_proc:                                  ## @proc
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	movl	4(%eax), %ecx
	movl	(%ecx), %edx
	movl	(%edx), %edx
	subl	(%eax), %edx
	movl	%edx, 4(%ecx)
	popl	%ebp
	retl


.subsections_via_symbols
