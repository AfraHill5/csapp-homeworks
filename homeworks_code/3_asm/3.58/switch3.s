	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_switch3
	.align	4, 0x90
_switch3:                               ## @switch3
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	xorl	%eax, %eax
	movl	16(%ebp), %esi
	cmpl	$4, %esi
	ja	LBB0_7
## BB#1:
	calll	L0$pb
L0$pb:
	popl	%eax
	movl	12(%ebp), %ecx
	movl	8(%ebp), %edx
Ltmp0 = LJTI0_0-L0$pb
	addl	Ltmp0(%eax,%esi,4), %eax
	jmpl	*%eax
LBB0_2:
	movl	(%edx), %eax
	movl	(%ecx), %ecx
	movl	%ecx, (%edx)
	jmp	LBB0_7
LBB0_3:
	movl	(%ecx), %eax
	addl	(%edx), %eax
	movl	%eax, (%ecx)
	jmp	LBB0_7
LBB0_4:
	movl	$15, (%ecx)
	movl	(%edx), %eax
	jmp	LBB0_7
LBB0_5:
	movl	(%edx), %eax
	movl	%eax, (%ecx)
LBB0_6:
	movl	$17, %eax
LBB0_7:
	popl	%esi
	popl	%ebp
	retl
	.align	2, 0x90
L0_0_set_2 = LBB0_2-L0$pb
L0_0_set_3 = LBB0_3-L0$pb
L0_0_set_4 = LBB0_4-L0$pb
L0_0_set_5 = LBB0_5-L0$pb
L0_0_set_6 = LBB0_6-L0$pb
LJTI0_0:
	.long	L0_0_set_2
	.long	L0_0_set_3
	.long	L0_0_set_4
	.long	L0_0_set_5
	.long	L0_0_set_6


.subsections_via_symbols
