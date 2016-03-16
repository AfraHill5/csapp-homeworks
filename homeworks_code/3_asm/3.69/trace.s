	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_trace_iter
	.align	4, 0x90
_trace_iter:                            ## @trace_iter
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
	xorl	%eax, %eax
	testq	%rdi, %rdi
	je	LBB0_3
	.align	4, 0x90
LBB0_1:                                 ## %.lr.ph
                                        ## =>This Inner Loop Header: Depth=1
	movq	%rdi, %rax
	movq	(%rax), %rdi
	testq	%rdi, %rdi
	jne	LBB0_1
## BB#2:                                ## %._crit_edge
	movq	16(%rax), %rax
LBB0_3:
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
