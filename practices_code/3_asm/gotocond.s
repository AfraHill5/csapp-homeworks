	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_gotocond
	.align	4, 0x90
_gotocond:                              ## @gotocond
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
	movq	%rsi, -16(%rbp)
	cmpq	$0, -16(%rbp)
	jne	LBB0_2
## BB#1:
	jmp	LBB0_5
LBB0_2:
	cmpl	$0, -4(%rbp)
	jg	LBB0_4
## BB#3:
	jmp	LBB0_5
LBB0_4:
	movq	-16(%rbp), %rax
	movl	(%rax), %ecx
	addl	-4(%rbp), %ecx
	movq	-16(%rbp), %rax
	movl	%ecx, (%rax)
LBB0_5:
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
