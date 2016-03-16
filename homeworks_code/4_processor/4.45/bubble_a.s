	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_bubble_a
	.align	4, 0x90
_bubble_a:                              ## @bubble_a
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	cmpl	$2, 12(%ebp)
	jl	LBB0_6
## BB#1:
	movl	8(%ebp), %ecx
	movl	$1, %edx
	.align	4, 0x90
LBB0_2:                                 ## %.lr.ph
                                        ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_3 Depth 2
	movl	%edx, %esi
	.align	4, 0x90
LBB0_3:                                 ##   Parent Loop BB0_2 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	leal	-1(%esi), %edi
	movl	(%ecx,%esi,4), %ebx
	movl	-4(%ecx,%esi,4), %eax
	cmpl	%eax, %ebx
	jge	LBB0_4
## BB#7:                                ##   in Loop: Header=BB0_3 Depth=2
	movl	%eax, (%ecx,%esi,4)
	movl	%ebx, -4(%ecx,%esi,4)
LBB0_4:                                 ## %.backedge
                                        ##   in Loop: Header=BB0_3 Depth=2
	testl	%edi, %edi
	movl	%edi, %esi
	jg	LBB0_3
## BB#5:                                ## %._crit_edge
                                        ##   in Loop: Header=BB0_2 Depth=1
	incl	%edx
	cmpl	12(%ebp), %edx
	jne	LBB0_2
LBB0_6:                                 ## %._crit_edge5
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	retl


.subsections_via_symbols
