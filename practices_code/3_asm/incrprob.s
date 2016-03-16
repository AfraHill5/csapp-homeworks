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
	addl	(%rdx), %edi
	movl	%edi, (%rdx)
	movslq	%edi, %rax
	addq	%rax, (%rsi)
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_incrprob_4
	.align	4, 0x90
_incrprob_4:                            ## @incrprob_4
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	addl	(%rdx), %edi
	movl	%edi, (%rdx)
	movslq	%edi, %rax
	addq	%rax, (%rsi)
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_incrprob_1
	.align	4, 0x90
_incrprob_1:                            ## @incrprob_1
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp6:
	.cfi_def_cfa_offset 16
Ltmp7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp8:
	.cfi_def_cfa_register %rbp
	addl	(%rdx), %edi
	movl	%edi, (%rdx)
	movslq	%edi, %rax
	addq	%rax, (%rsi)
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_incrprob_5
	.align	4, 0x90
_incrprob_5:                            ## @incrprob_5
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp9:
	.cfi_def_cfa_offset 16
Ltmp10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp11:
	.cfi_def_cfa_register %rbp
	addl	(%rdx), %edi
	movl	%edi, (%rdx)
	movslq	%edi, %rax
	addq	%rax, (%rsi)
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
