	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_rSum
	.align	4, 0x90
_rSum:                                  ## @rSum
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	movl	12(%ebp), %ecx
	xorl	%eax, %eax
	testl	%ecx, %ecx
	je	LBB0_3
## BB#1:
	movl	8(%ebp), %edx
	.align	4, 0x90
LBB0_2:                                 ## %.lr.ph
                                        ## =>This Inner Loop Header: Depth=1
	addl	(%edx), %eax
	addl	$4, %edx
	decl	%ecx
	jne	LBB0_2
LBB0_3:                                 ## %._crit_edge
	popl	%ebp
	retl


.subsections_via_symbols
