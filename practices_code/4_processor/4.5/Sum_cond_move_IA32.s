	.file	"Sum_cond_jump.c"
	.text
	.globl	Sum
	.type	Sum, @function
Sum:
.LFB0:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	12(%esp), %ebx
	movl	16(%esp), %ecx
	testl	%ecx, %ecx
	je	.L6
	movl	$0, %eax
.L5:
	movl	(%ebx), %edx
	movl	%eax, %esi
	subl	%edx, %esi
	addl	%edx, %eax
	testl	%edx, %edx
	cmovs	%esi, %eax
	addl	$4, %ebx
	subl	$1, %ecx
	jne	.L5
	jmp	.L2
.L6:
	movl	$0, %eax
.L2:
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE0:
	.size	Sum, .-Sum
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
