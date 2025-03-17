	.file	"1.c"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$80, %rsp
	.seh_stackalloc	80
	.seh_endprologue
	call	__main
	movb	$97, -33(%rbp)
	movw	$1, -36(%rbp)
	movl	$1, -40(%rbp)
	movl	$1, -44(%rbp)
	leaq	-33(%rbp), %rax
	movq	%rax, -8(%rbp)
	leaq	-36(%rbp), %rax
	movq	%rax, -16(%rbp)
	leaq	-40(%rbp), %rax
	movq	%rax, -24(%rbp)
	leaq	-44(%rbp), %rax
	movq	%rax, -32(%rbp)
	movl	$0, %eax
	addq	$80, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
