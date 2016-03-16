	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_arith
	.align	4, 0x90
_arith:                                 ## @arith
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
	cmpl	$0, -4(%rbp)
	jge	LBB0_2
## BB#1:
	movl	-4(%rbp), %eax
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	jmp	LBB0_3
LBB0_2:
	movl	$4, %eax
	movl	-4(%rbp), %ecx
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	cltd
	movl	-12(%rbp), %ecx         ## 4-byte Reload
	idivl	%ecx
	movl	%eax, -8(%rbp)          ## 4-byte Spill
LBB0_3:
	movl	-8(%rbp), %eax          ## 4-byte Reload
	popq	%rbp
	retq
	.cfi_endproc

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
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
	subq	$16, %rsp
	movl	$32, %edi
	movl	$0, -4(%rbp)
	callq	_arith
	leaq	L_.str(%rip), %rdi
	movl	$32, %esi
	movl	%eax, %edx
	movb	$0, %al
	callq	_printf
	xorl	%edx, %edx
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	movl	%edx, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d -> %d \n"


.subsections_via_symbols
