	.file	"obj.c"
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
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	call	__main
	movl	$3, -4(%rbp)
	movss	.LC0(%rip), %xmm0
	movss	%xmm0, -8(%rbp)
	cvtsi2ss	-4(%rbp), %xmm0
	addss	-8(%rbp), %xmm0
	cvttss2si	%xmm0, %eax
	movl	%eax, -12(%rbp)
	cvtsi2ss	-4(%rbp), %xmm0
	subss	-8(%rbp), %xmm0
	cvttss2si	%xmm0, %eax
	movl	%eax, -16(%rbp)
	cvtsi2ss	-4(%rbp), %xmm0
	mulss	-8(%rbp), %xmm0
	cvttss2si	%xmm0, %eax
	movl	%eax, -20(%rbp)
	cvtsi2ss	-4(%rbp), %xmm0
	divss	-8(%rbp), %xmm0
	cvttss2si	%xmm0, %eax
	movl	%eax, -24(%rbp)
	movl	$0, %eax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 4
.LC0:
	.long	1073741824
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
