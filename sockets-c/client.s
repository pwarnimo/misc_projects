	.file	"client.c"
	.section	.rodata
.LC0:
	.string	"\nUsage: %s <ip of server>\n"
	.align 8
.LC1:
	.string	"\nError: Could not create socket!\n"
	.align 8
.LC2:
	.string	"\nError: inet_pton() error occured!\n"
	.align 8
.LC3:
	.string	"\nError: connect() has failed!\n"
	.align 8
.LC4:
	.string	"\nError: fputs() error occured!\n"
.LC5:
	.string	"\nError: read error!\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$1088, %rsp
	movl	%edi, -1076(%rbp)
	movq	%rsi, -1088(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -1064(%rbp)
	movl	$0, -1060(%rbp)
	cmpl	$2, -1076(%rbp)
	je	.L2
	movq	-1088(%rbp), %rax
	movq	(%rax), %rdx
	movq	stderr(%rip), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	$1, %edi
	call	exit
.L2:
	leaq	-1040(%rbp), %rax
	movl	$1024, %edx
	movl	$48, %esi
	movq	%rax, %rdi
	call	memset
	movl	$0, %edx
	movl	$1, %esi
	movl	$2, %edi
	call	socket
	movl	%eax, -1064(%rbp)
	cmpl	$0, -1064(%rbp)
	jns	.L3
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$33, %edx
	movl	$1, %esi
	movl	$.LC1, %edi
	call	fwrite
	movl	$1, %edi
	call	exit
.L3:
	leaq	-1056(%rbp), %rax
	movl	$16, %edx
	movl	$48, %esi
	movq	%rax, %rdi
	call	memset
	movw	$2, -1056(%rbp)
	movl	$5000, %edi
	call	htons
	movw	%ax, -1054(%rbp)
	movq	-1088(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	leaq	-1056(%rbp), %rdx
	addq	$4, %rdx
	movq	%rax, %rsi
	movl	$2, %edi
	call	inet_pton
	testl	%eax, %eax
	jg	.L4
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$35, %edx
	movl	$1, %esi
	movl	$.LC2, %edi
	call	fwrite
	movl	$1, %edi
	call	exit
.L4:
	leaq	-1056(%rbp), %rcx
	movl	-1064(%rbp), %eax
	movl	$16, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	connect
	testl	%eax, %eax
	jns	.L5
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$30, %edx
	movl	$1, %esi
	movl	$.LC3, %edi
	call	fwrite
	movl	$1, %edi
	call	exit
.L5:
	jmp	.L6
.L7:
	movl	-1060(%rbp), %eax
	cltq
	movb	$0, -1040(%rbp,%rax)
	movq	stdout(%rip), %rdx
	leaq	-1040(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	fputs
	cmpl	$-1, %eax
	jne	.L6
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$31, %edx
	movl	$1, %esi
	movl	$.LC4, %edi
	call	fwrite
.L6:
	leaq	-1040(%rbp), %rcx
	movl	-1064(%rbp), %eax
	movl	$1023, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read
	movl	%eax, -1060(%rbp)
	cmpl	$0, -1060(%rbp)
	jg	.L7
	cmpl	$0, -1060(%rbp)
	jns	.L8
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$20, %edx
	movl	$1, %esi
	movl	$.LC5, %edi
	call	fwrite
.L8:
	movl	$0, %edi
	call	exit
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Gentoo 4.9.3 p1.5, pie-0.6.4) 4.9.3"
	.section	.note.GNU-stack,"",@progbits
