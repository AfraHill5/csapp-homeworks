	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_test
	.align	4, 0x90
_test:                                  ## @test
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	movl	12(%ebp), %eax
	movl	116(%eax), %ecx
	addl	(%eax), %ecx
	imull	$28, 8(%ebp), %edx
	leal	(%eax,%edx), %esi
	movl	4(%eax,%edx), %eax
	movl	%ecx, 8(%esi,%eax,4)
	popl	%esi
	popl	%ebp
	retl


.subsections_via_symbols
