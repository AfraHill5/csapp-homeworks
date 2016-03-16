	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_var_prod_ele
	.align	4, 0x90
_var_prod_ele:                          ## @var_prod_ele
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	movl	8(%ebp), %ecx
	xorl	%eax, %eax
	testl	%ecx, %ecx
	jle	LBB0_3
## BB#1:                                ## %.lr.ph
	movl	24(%ebp), %eax
	movl	16(%ebp), %edx
	movl	12(%ebp), %esi
	movl	20(%ebp), %edi
	imull	%ecx, %edi
	leal	(%edx,%eax,4), %edx
	leal	(%esi,%edi,4), %esi
	xorl	%eax, %eax
	leal	(,%ecx,4), %edi
	.align	4, 0x90
LBB0_2:                                 ## =>This Inner Loop Header: Depth=1
	movl	(%edx), %ebx
	imull	(%esi), %ebx
	addl	%ebx, %eax
	addl	%edi, %edx
	addl	$4, %esi
	decl	%ecx
	jne	LBB0_2
LBB0_3:                                 ## %._crit_edge
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	retl


.subsections_via_symbols
