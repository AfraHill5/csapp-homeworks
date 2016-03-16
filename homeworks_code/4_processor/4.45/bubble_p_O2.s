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

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	subl	$28, %esp
	calll	L1$pb
L1$pb:
	popl	%eax
	movl	L___stack_chk_guard$non_lazy_ptr-L1$pb(%eax), %ecx
	movl	%ecx, -40(%ebp)         ## 4-byte Spill
	movl	(%ecx), %ecx
	movl	%ecx, -16(%ebp)
	movl	(l_main.b-L1$pb)+16(%eax), %ecx
	movl	%ecx, -20(%ebp)
	movsd	(l_main.b-L1$pb)+8(%eax), %xmm0
	movsd	%xmm0, -28(%ebp)
	movsd	l_main.b-L1$pb(%eax), %xmm0
	movsd	%xmm0, -36(%ebp)
	leal	-36(%ebp), %edx
	leal	-32(%ebp), %esi
	movl	%edx, %edi
	.align	4, 0x90
LBB1_2:                                 ## %.preheader.i
                                        ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_3 Depth 2
	cmpl	%edx, %edi
	movl	%edi, %ebx
	jb	LBB1_1
	.align	4, 0x90
LBB1_3:                                 ## %.lr.ph.i
                                        ##   Parent Loop BB1_2 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	(%ebx), %ecx
	movl	4(%ebx), %eax
	cmpl	%ecx, %eax
	jge	LBB1_5
## BB#4:                                ##   in Loop: Header=BB1_3 Depth=2
	movl	%ecx, 4(%ebx)
	movl	%eax, (%ebx)
LBB1_5:                                 ##   in Loop: Header=BB1_3 Depth=2
	addl	$-4, %ebx
	cmpl	%edx, %ebx
	jae	LBB1_3
LBB1_1:                                 ## %.loopexit.i
                                        ##   in Loop: Header=BB1_2 Depth=1
	movl	%edi, %eax
	addl	$8, %eax
	leal	-20(%ebp), %ecx
	cmpl	%ecx, %eax
	movl	%esi, %edi
	movl	%eax, %esi
	jb	LBB1_2
## BB#6:                                ## %bubble_p.exit
	movl	-40(%ebp), %eax         ## 4-byte Reload
	movl	(%eax), %eax
	cmpl	-16(%ebp), %eax
	jne	LBB1_8
## BB#7:                                ## %bubble_p.exit
	xorl	%eax, %eax
	addl	$28, %esp
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	retl
LBB1_8:                                 ## %bubble_p.exit
	calll	___stack_chk_fail

	.section	__TEXT,__const
	.align	2                       ## @main.b
l_main.b:
	.long	9                       ## 0x9
	.long	6                       ## 0x6
	.long	8                       ## 0x8
	.long	7                       ## 0x7
	.long	0                       ## 0x0


	.section	__IMPORT,__pointers,non_lazy_symbol_pointers
L___stack_chk_guard$non_lazy_ptr:
	.indirect_symbol	___stack_chk_guard
	.long	0

.subsections_via_symbols
