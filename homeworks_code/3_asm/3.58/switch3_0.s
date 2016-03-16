	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_switch3
	.align	4, 0x90
_switch3:                               ## @switch3
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	subl	$28, %esp
	calll	L0$pb
L0$pb:
	popl	%eax
	movl	16(%ebp), %ecx
	movl	12(%ebp), %edx
	movl	8(%ebp), %esi
	movl	%esi, -8(%ebp)
	movl	%edx, -12(%ebp)
	movl	%ecx, -16(%ebp)
	movl	$0, -20(%ebp)
	movl	-16(%ebp), %ecx
	movl	%ecx, %edx
	subl	$4, %edx
	movl	%eax, -24(%ebp)         ## 4-byte Spill
	movl	%ecx, -28(%ebp)         ## 4-byte Spill
	movl	%edx, -32(%ebp)         ## 4-byte Spill
	ja	LBB0_6
## BB#8:
	movl	-24(%ebp), %eax         ## 4-byte Reload
	movl	-28(%ebp), %ecx         ## 4-byte Reload
Ltmp0 = LJTI0_0-L0$pb
	movl	Ltmp0(%eax,%ecx,4), %edx
	addl	%eax, %edx
	jmpl	*%edx
LBB0_1:
	movl	-8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -20(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	-8(%ebp), %ecx
	movl	%eax, (%ecx)
	jmp	LBB0_7
LBB0_2:
	movl	-8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %ecx
	addl	(%ecx), %eax
	movl	%eax, -20(%ebp)
	movl	-20(%ebp), %eax
	movl	-12(%ebp), %ecx
	movl	%eax, (%ecx)
	jmp	LBB0_7
LBB0_3:
	movl	-12(%ebp), %eax
	movl	$15, (%eax)
	movl	-8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -20(%ebp)
	jmp	LBB0_7
LBB0_4:
	movl	-8(%ebp), %eax
	movl	(%eax), %eax
	movl	-12(%ebp), %ecx
	movl	%eax, (%ecx)
	movl	$17, -20(%ebp)
	jmp	LBB0_7
LBB0_5:
	movl	$17, -20(%ebp)
	jmp	LBB0_7
LBB0_6:
	jmp	LBB0_7
LBB0_7:
	movl	-20(%ebp), %eax
	addl	$28, %esp
	popl	%esi
	popl	%ebp
	retl
	.align	2, 0x90
L0_0_set_1 = LBB0_1-L0$pb
L0_0_set_2 = LBB0_2-L0$pb
L0_0_set_3 = LBB0_3-L0$pb
L0_0_set_4 = LBB0_4-L0$pb
L0_0_set_5 = LBB0_5-L0$pb
LJTI0_0:
	.long	L0_0_set_1
	.long	L0_0_set_2
	.long	L0_0_set_3
	.long	L0_0_set_4
	.long	L0_0_set_5


.subsections_via_symbols
