Sum:
.LFB0:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	mrmovl	12(%esp), %ebx
	mrmovl	16(%esp), %ecx
	andl	%ecx, %ecx
	je	.L6
	irmovl	$0, %eax
.L5:
	mrmovl	(%ebx), %edx
	andl 	%edx, %edx
	jl		.L7
	addl    %edx, %eax
	jmp		.L8
	
.L7:
	subl	%edx, %eax
	jmp		.L8	
	
.L8:
	irmovl  $4, %esi
	addl	%esi, %ebx
	irmovl  $1, %esi
	subl	%esi, %ecx
	jne	.L5
	jmp	.L2

.L6:
	irmovl	$0, %eax
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
