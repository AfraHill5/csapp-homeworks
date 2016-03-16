	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_rSum
	.align	4, 0x90
_rSum:                                  ## @rSum
## BB#0:
	pushl	%ebp
	rrmovl	%esp, %ebp
	mrmovl	12(%ebp), %ecx
	xorl	%eax, %eax
	andl	%ecx, %ecx
	jle	LBB0_3

	mrmovl	8(%ebp), %edx
	irmovl  $1, %ebx
	addl	%ebx, %ecx
	xorl	%eax, %eax
	.align	4, 0x90
LBB0_2:                                 ## %tailrecurse
                                        ## =>This Inner Loop Header: Depth=1
	mrmovl  (%edx), %ebx
	addl	%ebx, %eax
	irmovl  $4, %esi
	addl	%esi, %edx
	subl	%1, %ecx
	rrmovl  %ecx, %esi
	subl	$1, %esi
	jg	LBB0_2
LBB0_3:                                 ## %tailrecurse._crit_edge
	popl	%ebp
	retl


.subsections_via_symbols
