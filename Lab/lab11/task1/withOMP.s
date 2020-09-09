	.file	"parfor-fixed.c"
	.text
	.section	.rodata
.LC0:
	.string	"square root of %f is = %f\n"
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
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$88, %rsp
	.cfi_offset 13, -24
	.cfi_offset 12, -32
	.cfi_offset 3, -40
	movq	%fs:40, %rax
	movq	%rax, -40(%rbp)
	xorl	%eax, %eax
	movq	%rsp, %rax
	movq	%rax, %rbx
	movl	$10, -108(%rbp)
	movl	-108(%rbp), %eax
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -96(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, %r12
	movl	$0, %r13d
	movslq	%eax, %rdx
	movq	%rdx, %r10
	movl	$0, %r11d
	cltq
	salq	$2, %rax
	leaq	3(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %ecx
	movl	$0, %edx
	divq	%rcx
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -88(%rbp)
	movl	-108(%rbp), %eax
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -80(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, %r8
	movl	$0, %r9d
	movslq	%eax, %rdx
	movq	%rdx, %rsi
	movl	$0, %edi
	cltq
	salq	$2, %rax
	leaq	3(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %edi
	movl	$0, %edx
	divq	%rdi
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -72(%rbp)
	movl	$0, -100(%rbp)
	jmp	.L2
.L3:
	movl	-100(%rbp), %eax
	addl	$1, %eax
	cvtsi2ss	%eax, %xmm0
	movq	-88(%rbp), %rax
	movl	-100(%rbp), %edx
	movslq	%edx, %rdx
	movss	%xmm0, (%rax,%rdx,4)
	addl	$1, -100(%rbp)
.L2:
	movl	-100(%rbp), %eax
	cmpl	-108(%rbp), %eax
	jl	.L3
	movq	-72(%rbp), %rax
	movq	%rax, -56(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, -64(%rbp)
	movl	-108(%rbp), %eax
	movl	%eax, -48(%rbp)
	leaq	-64(%rbp), %rax
	movl	$0, %ecx
	movl	$0, %edx
	movq	%rax, %rsi
	leaq	main._omp_fn.0(%rip), %rdi
	call	GOMP_parallel@PLT
	movl	$0, -104(%rbp)
	jmp	.L4
.L5:
	movq	-72(%rbp), %rax
	movl	-104(%rbp), %edx
	movslq	%edx, %rdx
	movss	(%rax,%rdx,4), %xmm0
	cvtss2sd	%xmm0, %xmm1
	movq	-88(%rbp), %rax
	movl	-104(%rbp), %edx
	movslq	%edx, %rdx
	movss	(%rax,%rdx,4), %xmm0
	cvtss2sd	%xmm0, %xmm0
	leaq	.LC0(%rip), %rdi
	movl	$2, %eax
	call	printf@PLT
	addl	$1, -104(%rbp)
.L4:
	movl	-104(%rbp), %eax
	cmpl	-108(%rbp), %eax
	jl	.L5
	movl	$0, %eax
	movq	%rbx, %rsp
	movq	-40(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L7
	call	__stack_chk_fail@PLT
.L7:
	leaq	-24(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC1:
	.string	"Thread %d working on component %d\n"
	.text
	.type	main._omp_fn.0, @function
main._omp_fn.0:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$48, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%rdi, -56(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-56(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -40(%rbp)
	movq	-56(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -32(%rbp)
	movq	-56(%rbp), %rax
	movl	16(%rax), %eax
	movl	%eax, -44(%rbp)
	movl	-44(%rbp), %ebx
	call	omp_get_num_threads@PLT
	movl	%eax, %r12d
	call	omp_get_thread_num@PLT
	movl	%eax, %esi
	movl	%ebx, %eax
	cltd
	idivl	%r12d
	movl	%eax, %ecx
	movl	%ebx, %eax
	cltd
	idivl	%r12d
	movl	%edx, %eax
	cmpl	%eax, %esi
	jl	.L9
.L12:
	imull	%ecx, %esi
	movl	%esi, %edx
	addl	%edx, %eax
	leal	(%rax,%rcx), %ebx
	cmpl	%ebx, %eax
	jge	.L10
	movl	%eax, -48(%rbp)
.L11:
	call	omp_get_thread_num@PLT
	movl	%eax, %ecx
	movl	-48(%rbp), %eax
	movl	%eax, %edx
	movl	%ecx, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-32(%rbp), %rax
	movl	-48(%rbp), %edx
	movslq	%edx, %rdx
	movss	(%rax,%rdx,4), %xmm0
	cvtss2sd	%xmm0, %xmm0
	call	sqrt@PLT
	cvtsd2ss	%xmm0, %xmm0
	movq	-40(%rbp), %rax
	movl	-48(%rbp), %edx
	movslq	%edx, %rdx
	movss	%xmm0, (%rax,%rdx,4)
	addl	$1, -48(%rbp)
	cmpl	%ebx, -48(%rbp)
	jl	.L11
.L10:
	call	GOMP_barrier@PLT
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L13
	jmp	.L14
.L9:
	movl	$0, %eax
	addl	$1, %ecx
	jmp	.L12
.L14:
	call	__stack_chk_fail@PLT
.L13:
	addq	$48, %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main._omp_fn.0, .-main._omp_fn.0
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
