	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_decode1
	.align	4, 0x90
_decode1:                               ## @decode1
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
	movl	(%rdi), %r8d
	movl	(%rsi), %ecx
	movl	(%rdx), %eax
	movl	%ecx, (%rdi)
	movl	%eax, (%rsi)
	movl	%r8d, (%rdx)
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
