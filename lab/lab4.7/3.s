	.file	"3.c"
	.text
	.globl	myfunc
	.def	myfunc;	.scl	2;	.type	32;	.endef
	.seh_proc	myfunc
myfunc:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	$0, -4(%rbp)
	movl	$1, -8(%rbp)
	jmp	.L2
.L3:
	movl	-8(%rbp), %eax
	imull	-8(%rbp), %eax
	addl	%eax, -4(%rbp)
	addl	$1, -8(%rbp)
.L2:
	movl	-8(%rbp), %eax
	cmpl	%eax, 16(%rbp)
	jnb	.L3
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "%d,%d,%d,%d\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$72, %rsp
	.seh_stackalloc	72
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	call	__main
	leaq	myfunc(%rip), %rax
	movq	%rax, -72(%rbp)
	leaq	myfunc(%rip), %rax
	movq	%rax, -80(%rbp)

	movq	-80(%rbp), %rax
	movl	$10, %ecx
	call	*%rax
	movl	%eax, %ebx

	movq	-80(%rbp), %rax
	movl	$10, %ecx
	call	*%rax
	movl	%eax, %edi

	movq	-72(%rbp), %rax
	movl	$10, %ecx
	call	*%rax
	movl	%eax, %esi

	movq	-72(%rbp), %rax
	movl	$10, %ecx
	call	*%rax
	movl	%ebx, 32(%rsp)
	
	movl	%edi, %r9d
	movl	%esi, %r8d
	movl	%eax, %edx
	leaq	.LC0(%rip), %rcx
	call	printf
	movl	$0, %eax
	addq	$72, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	printf;	.scl	2;	.type	32;	.endef
