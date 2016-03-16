	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_incrprob
	.align	4, 0x90
_incrprob:                              ## @incrprob
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
	movslq	%edi, %rax
	addq	(%rdx), %rax
	movq	%rax, (%rdx)
	addq	%rax, (%rsi)
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
