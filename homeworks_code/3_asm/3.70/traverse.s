	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_traverse
	.align	4, 0x90
_traverse:                              ## @traverse
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
	pushq	%r14
	pushq	%rbx
Ltmp3:
	.cfi_offset %rbx, -32
Ltmp4:
	.cfi_offset %r14, -24
	movq	%rdi, %rbx
	testq	%rbx, %rbx
	je	LBB0_2
## BB#1:
	movq	(%rbx), %rdi
	callq	_traverse
	movq	%rax, %r14
	movq	8(%rbx), %rdi
	callq	_traverse
	cmpq	%rax, %r14
	cmovleq	%r14, %rax
	movq	16(%rbx), %rcx
	cmpq	%rcx, %rax
	cmovgq	%rcx, %rax
	jmp	LBB0_3
LBB0_2:
	movabsq	$9223372036854775807, %rax ## imm = 0x7FFFFFFFFFFFFFFF
LBB0_3:
	popq	%rbx
	popq	%r14
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
