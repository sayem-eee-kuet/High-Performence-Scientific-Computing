	.file	"parfor-fixed.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"Thread %d working on component %d\n"
.LC1:
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
	subq	$72, %rsp
	.cfi_offset 13, -24
	.cfi_offset 12, -32
	.cfi_offset 3, -40
	movq	%fs:40, %rax
	movq	%rax, -40(%rbp)
	xorl	%eax, %eax
	movq	%rsp, %rax
	movq	%rax, %rbx
	movl	$10, -88(%rbp)
	movl	-88(%rbp), %eax
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -72(%rbp)
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
	movq	%rax, -64(%rbp)
	movl	-88(%rbp), %eax
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -56(%rbp)
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
	movq	%rax, -48(%rbp)
	movl	$0, -76(%rbp)
	jmp	.L2
.L3:
	movl	-76(%rbp), %eax
	addl	$1, %eax
	cvtsi2ss	%eax, %xmm0
	movq	-64(%rbp), %rax
	movl	-76(%rbp), %edx
	movslq	%edx, %rdx
	movss	%xmm0, (%rax,%rdx,4)
	addl	$1, -76(%rbp)
.L2:
	movl	-76(%rbp), %eax
	cmpl	-88(%rbp), %eax
	jl	.L3
	movl	$0, -80(%rbp)
	jmp	.L4
.L5:
	call	omp_get_thread_num@PLT
	movl	%eax, %ecx
	movl	-80(%rbp), %eax
	movl	%eax, %edx
	movl	%ecx, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-64(%rbp), %rax
	movl	-80(%rbp), %edx
	movslq	%edx, %rdx
	movss	(%rax,%rdx,4), %xmm0
	cvtss2sd	%xmm0, %xmm0
	call	sqrt@PLT
	cvtsd2ss	%xmm0, %xmm0
	movq	-48(%rbp), %rax
	movl	-80(%rbp), %edx
	movslq	%edx, %rdx
	movss	%xmm0, (%rax,%rdx,4)
	addl	$1, -80(%rbp)
.L4:
	movl	-80(%rbp), %eax
	cmpl	-88(%rbp), %eax
	jl	.L5
	movl	$0, -84(%rbp)
	jmp	.L6
.L7:
	movq	-48(%rbp), %rax
	movl	-84(%rbp), %edx
	movslq	%edx, %rdx
	movss	(%rax,%rdx,4), %xmm0
	cvtss2sd	%xmm0, %xmm1
	movq	-64(%rbp), %rax
	movl	-84(%rbp), %edx
	movslq	%edx, %rdx
	movss	(%rax,%rdx,4), %xmm0
	cvtss2sd	%xmm0, %xmm0
	leaq	.LC1(%rip), %rdi
	movl	$2, %eax
	call	printf@PLT
	addl	$1, -84(%rbp)
.L6:
	movl	-84(%rbp), %eax
	cmpl	-88(%rbp), %eax
	jl	.L7
	movl	$0, %eax
	movq	%rbx, %rsp
	movq	-40(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L9
	call	__stack_chk_fail@PLT
.L9:
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
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
