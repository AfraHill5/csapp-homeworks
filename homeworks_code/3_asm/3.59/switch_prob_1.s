	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_switch_prob
	.align	4, 0x90
_switch_prob:                           ## @switch_prob
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	calll	L0$pb
L0$pb:
	popl	%eax
	movl	12(%ebp), %ecx
	movl	8(%ebp), %edx
	movl	%edx, -4(%ebp)
	movl	%ecx, -8(%ebp)
	movl	-4(%ebp), %ecx
	movl	%ecx, -12(%ebp)
	movl	-8(%ebp), %ecx
	addl	$-28, %ecx
	movl	%ecx, %edx
	subl	$5, %edx
	movl	%eax, -16(%ebp)         ## 4-byte Spill
	movl	%ecx, -20(%ebp)         ## 4-byte Spill
	movl	%edx, -24(%ebp)         ## 4-byte Spill
	ja	LBB0_6
## BB#8:
	movl	-16(%ebp), %eax         ## 4-byte Reload
	movl	-20(%ebp), %ecx         ## 4-byte Reload
Ltmp0 = LJTI0_0-L0$pb
	movl	Ltmp0(%eax,%ecx,4), %edx
	addl	%eax, %edx
	jmpl	*%edx
LBB0_1:
	movl	-12(%ebp), %eax
	shll	$3, %eax
	movl	%eax, -12(%ebp)
	jmp	LBB0_7
LBB0_2:
	movl	-12(%ebp), %eax
	shll	$3, %eax
	movl	%eax, -12(%ebp)
	jmp	LBB0_7
LBB0_3:
	movl	-12(%ebp), %eax
	sarl	$3, %eax
	movl	%eax, -12(%ebp)
	jmp	LBB0_7
LBB0_4:
	movl	-4(%ebp), %eax
	shll	$3, %eax
	subl	-4(%ebp), %eax
	movl	-4(%ebp), %ecx
	shll	$3, %ecx
	subl	-4(%ebp), %ecx
	imull	%ecx, %eax
	addl	$17, %eax
	movl	%eax, -12(%ebp)
	jmp	LBB0_7
LBB0_5:
	movl	-4(%ebp), %eax
	imull	-4(%ebp), %eax
	addl	$17, %eax
	movl	%eax, -12(%ebp)
	jmp	LBB0_7
LBB0_6:
	movl	-12(%ebp), %eax
	addl	$17, %eax
	movl	%eax, -12(%ebp)
LBB0_7:
	movl	-12(%ebp), %eax
	addl	$24, %esp
	popl	%ebp
	retl
	.align	2, 0x90
L0_0_set_1 = LBB0_1-L0$pb
L0_0_set_6 = LBB0_6-L0$pb
L0_0_set_2 = LBB0_2-L0$pb
L0_0_set_3 = LBB0_3-L0$pb
L0_0_set_4 = LBB0_4-L0$pb
L0_0_set_5 = LBB0_5-L0$pb
LJTI0_0:
	.long	L0_0_set_1
	.long	L0_0_set_6
	.long	L0_0_set_2
	.long	L0_0_set_3
	.long	L0_0_set_4
	.long	L0_0_set_5


.subsections_via_symbols
