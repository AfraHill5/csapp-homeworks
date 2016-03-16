	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_bubble_p
	.align	4, 0x90
_bubble_p:                              ## @bubble_p
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	pushl	%eax
	movl	12(%ebp), %ecx
	cmpl	$2, %ecx
	jl	LBB0_7
## BB#1:                                ## %.preheader.lr.ph
	movl	8(%ebp), %eax
	leal	(%eax,%ecx,4), %ecx
	movl	%ecx, -16(%ebp)         ## 4-byte Spill
	leal	4(%eax), %edx
	movl	%eax, %esi
	.align	4, 0x90
LBB0_3:                                 ## %.preheader
                                        ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_4 Depth 2
	cmpl	%eax, %esi
	movl	%esi, %edi
	jb	LBB0_2
	.align	4, 0x90
LBB0_4:                                 ## %.lr.ph
                                        ##   Parent Loop BB0_3 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	(%edi), %ecx
	movl	4(%edi), %ebx
	cmpl	%ecx, %ebx
	jge	LBB0_6
## BB#5:                                ##   in Loop: Header=BB0_4 Depth=2
	movl	%ecx, 4(%edi)
	movl	%ebx, (%edi)
LBB0_6:                                 ##   in Loop: Header=BB0_4 Depth=2
	addl	$-4, %edi
	cmpl	%eax, %edi
	jae	LBB0_4
LBB0_2:                                 ## %.loopexit
                                        ##   in Loop: Header=BB0_3 Depth=1
	movl	%esi, %ecx
	addl	$8, %ecx
	cmpl	-16(%ebp), %ecx         ## 4-byte Folded Reload
	movl	%edx, %esi
	movl	%ecx, %edx
	jb	LBB0_3
LBB0_7:                                 ## %._crit_edge
	addl	$4, %esp
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	retl


.subsections_via_symbols
