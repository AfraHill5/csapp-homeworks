	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_loop_while_goto
	.align	4, 0x90
_loop_while_goto:                       ## @loop_while_goto
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
	movl	$1, -12(%rbp)
	movl	-4(%rbp), %esi
	cmpl	-8(%rbp), %esi
	jl	LBB0_2
## BB#1:
	jmp	LBB0_6
LBB0_2:
	movl	-4(%rbp), %eax
	addl	-8(%rbp), %eax
	movl	%eax, -16(%rbp)
LBB0_3:                                 ## =>This Inner Loop Header: Depth=1
	movl	-16(%rbp), %eax
	movl	-12(%rbp), %ecx
	imull	%eax, %ecx
	movl	%ecx, -12(%rbp)
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -16(%rbp)
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jge	LBB0_5
## BB#4:                                ##   in Loop: Header=BB0_3 Depth=1
	jmp	LBB0_3
LBB0_5:
	jmp	LBB0_6
LBB0_6:
	movl	-12(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
