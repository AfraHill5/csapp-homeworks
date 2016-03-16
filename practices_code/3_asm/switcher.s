	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_switcher
	.align	4, 0x90
_switcher:                              ## @switcher
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movl	-4(%rbp), %edx
	movl	%edx, %eax
	movq	%rax, %rcx
	subq	$7, %rcx
	movq	%rax, -24(%rbp)         ## 8-byte Spill
	movq	%rcx, -32(%rbp)         ## 8-byte Spill
	ja	LBB0_5
## BB#7:
	leaq	LJTI0_0(%rip), %rax
	movq	-24(%rbp), %rcx         ## 8-byte Reload
	movslq	(%rax,%rcx,4), %rdx
	addq	%rax, %rdx
	jmpq	*%rdx
LBB0_1:
	movl	-8(%rbp), %eax
	xorl	$15, %eax
	movl	%eax, -12(%rbp)
LBB0_2:
	movl	-12(%rbp), %eax
	addl	$112, %eax
	movl	%eax, -16(%rbp)
	jmp	LBB0_6
LBB0_3:
	movl	$2, %eax
	movl	-8(%rbp), %ecx
	addl	-12(%rbp), %ecx
                                        ## kill: CL<def> ECX<kill>
	shll	%cl, %eax
	movl	%eax, -16(%rbp)
	jmp	LBB0_6
LBB0_4:
	movl	$4, -16(%rbp)
	jmp	LBB0_6
LBB0_5:
	movl	-8(%rbp), %eax
	movl	%eax, -16(%rbp)
LBB0_6:
	movl	-16(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc
	.align	2, 0x90
L0_0_set_2 = LBB0_2-LJTI0_0
L0_0_set_5 = LBB0_5-LJTI0_0
L0_0_set_3 = LBB0_3-LJTI0_0
L0_0_set_4 = LBB0_4-LJTI0_0
L0_0_set_1 = LBB0_1-LJTI0_0
LJTI0_0:
	.long	L0_0_set_2
	.long	L0_0_set_5
	.long	L0_0_set_3
	.long	L0_0_set_5
	.long	L0_0_set_4
	.long	L0_0_set_1
	.long	L0_0_set_5
	.long	L0_0_set_3


.subsections_via_symbols
