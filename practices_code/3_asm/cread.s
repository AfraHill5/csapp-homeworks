	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_cread
	.align	4, 0x90
_cread:                                 ## @cread
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
	movl	%esi, %eax
	subl	%edi, %eax
	subl	%esi, %edi
	cmovgel	%eax, %edi
	movl	%edi, %eax
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
