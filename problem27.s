	.file	"problem27.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"When a = %d and b = %d there are %d consecutive primes. The answer is %d \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	movl	$0, -12(%rbp)
	movl	$1000, -20(%rbp)
	movq	$0, -32(%rbp)
	movl	$0, -36(%rbp)
	movl	$0, -40(%rbp)
	movl	$0, -64(%rbp)
	movl	$0, -60(%rbp)
	movl	$0, -56(%rbp)
	movl	$0, -52(%rbp)
	movl	$0, -64(%rbp)
	movl	$-999, -4(%rbp)
	jmp	.L2
.L9:
	movl	$-1000, -8(%rbp)
	jmp	.L3
.L8:
	movl	$0, -12(%rbp)
	movl	$0, -16(%rbp)
.L7:
	movl	-16(%rbp), %eax
	imull	%eax, %eax
	movl	%eax, %edx
	movl	-4(%rbp), %eax
	imull	-16(%rbp), %eax
	addl	%eax, %edx
	movl	-8(%rbp), %eax
	addl	%edx, %eax
	cltq
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	primecheck
	cmpl	$1, %eax
	je	.L12
	addl	$1, -12(%rbp)
	movl	-64(%rbp), %eax
	cmpl	%eax, -12(%rbp)
	jle	.L6
	movl	-12(%rbp), %eax
	movl	%eax, -64(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, -60(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, -56(%rbp)
	movl	-4(%rbp), %eax
	imull	-8(%rbp), %eax
	movl	%eax, -52(%rbp)
.L6:
	addl	$1, -16(%rbp)
	jmp	.L7
.L12:
	nop
	addl	$1, -8(%rbp)
.L3:
	movl	-8(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jle	.L8
	addl	$1, -4(%rbp)
.L2:
	movl	-4(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl	.L9
	movl	-52(%rbp), %esi
	movl	-64(%rbp), %ecx
	movl	-56(%rbp), %edx
	movl	-60(%rbp), %eax
	movl	%esi, %r8d
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	primecheck
	.type	primecheck, @function
primecheck:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)
	movq	$0, -16(%rbp)
	cmpq	$0, -40(%rbp)
	jns	.L14
	movq	-40(%rbp), %rax
	movq	%rax, %rdx
	shrq	$63, %rdx
	addq	%rdx, %rax
	sarq	%rax
	subq	$1, %rax
	movq	%rax, -8(%rbp)
	jmp	.L15
.L18:
	movq	-40(%rbp), %rax
	cqto
	idivq	-8(%rbp)
	movq	%rdx, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L16
	movq	$1, -16(%rbp)
	jmp	.L19
.L16:
	addq	$1, -8(%rbp)
.L15:
	cmpq	$-1, -8(%rbp)
	jl	.L18
	jmp	.L19
.L14:
	movq	-40(%rbp), %rax
	movq	%rax, %rdx
	shrq	$63, %rdx
	addq	%rdx, %rax
	sarq	%rax
	addq	$1, %rax
	movq	%rax, -8(%rbp)
	jmp	.L20
.L22:
	movq	-40(%rbp), %rax
	cqto
	idivq	-8(%rbp)
	movq	%rdx, -24(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L21
	movq	$1, -16(%rbp)
	jmp	.L19
.L21:
	subq	$1, -8(%rbp)
.L20:
	cmpq	$1, -8(%rbp)
	jg	.L22
.L19:
	movq	-16(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	primecheck, .-primecheck
	.ident	"GCC: (Debian 12.2.0-14+deb12u1) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
