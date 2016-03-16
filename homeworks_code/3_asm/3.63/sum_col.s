	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_sum_col
	.align	4, 0x90
_sum_col:                               ## @sum_col
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	movl	8(%ebp), %esi
	xorl	%eax, %eax
	testl	%esi, %esi
	jle	LBB0_3
## BB#1:                                ## %.lr.ph.preheader
	movl	16(%ebp), %eax
	movl	12(%ebp), %edx
	leal	(%esi,%esi,2), %ecx
	leal	(%edx,%eax,4), %edx
	leal	-4(,%esi,8), %esi
	xorl	%eax, %eax
	xorl	%edi, %edi
	.align	4, 0x90
LBB0_2:                                 ## %.lr.ph
                                        ## =>This Inner Loop Header: Depth=1
	addl	(%edx), %eax
	incl	%edi
	addl	%esi, %edx
	cmpl	%ecx, %edi
	jl	LBB0_2
LBB0_3:                                 ## %._crit_edge
	popl	%esi
	popl	%edi
	popl	%ebp
	retl


.subsections_via_symbols
