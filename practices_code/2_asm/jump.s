	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_jump
	.align	4, 0x90
_jump:                                  ## @jump
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
	cmpl	$9, %edi
	jg	LBB0_3
## BB#1:                                ## %.lr.ph.preheader
	movl	$10, %ebx
	subl	%edi, %ebx
	leaq	L_str(%rip), %r14
	.align	4, 0x90
LBB0_2:                                 ## %.lr.ph
                                        ## =>This Inner Loop Header: Depth=1
	movq	%r14, %rdi
	callq	_puts
	decl	%ebx
	jne	LBB0_2
LBB0_3:                                 ## %._crit_edge
	popq	%rbx
	popq	%r14
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"hello\n"

L_str:                                  ## @str
	.asciz	"hello"


.subsections_via_symbols
