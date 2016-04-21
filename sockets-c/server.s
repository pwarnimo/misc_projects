	.file	"server.c"
	.section	.rodata
.LC0:
	.string	"%.24s\r\n"
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
	movl	$0, -1072(%rbp)
	movl	$0, -1068(%rbp)
	movl	$0, %edx
	movl	$1, %esi
	movl	$2, %edi
	call	socket
	movl	%eax, -1072(%rbp)
	leaq	-1056(%rbp), %rax
	movl	$16, %edx
	movl	$48, %esi
	movq	%rax, %rdi
	call	memset
	leaq	-1040(%rbp), %rax
	movl	$1025, %edx
	movl	$48, %esi
	movq	%rax, %rdi
	call	memset
	movw	$2, -1056(%rbp)
	movl	$0, %edi
	call	htonl
	movl	%eax, -1052(%rbp)
	movl	$5000, %edi
	call	htons
	movw	%ax, -1054(%rbp)
	leaq	-1056(%rbp), %rcx
	movl	-1072(%rbp), %eax
	movl	$16, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	bind
	movl	-1072(%rbp), %eax
	movl	$10, %esi
	movl	%eax, %edi
	call	listen
.L2:
	movl	-1072(%rbp), %eax
	movl	$0, %edx
	movl	$0, %esi
	movl	%eax, %edi
	call	accept
	movl	%eax, -1068(%rbp)
	movl	$0, %edi
	call	time
	movq	%rax, -1064(%rbp)
	leaq	-1064(%rbp), %rax
	movq	%rax, %rdi
	call	ctime
	movq	%rax, %rdx
	leaq	-1040(%rbp), %rax
	movq	%rdx, %rcx
	movl	$.LC0, %edx
	movl	$1025, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf
	leaq	-1040(%rbp), %rax
	movq	%rax, %rdi
	call	strlen
	movq	%rax, %rdx
	leaq	-1040(%rbp), %rcx
	movl	-1068(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	write
	movl	-1068(%rbp), %eax
	movl	%eax, %edi
	call	close
	movl	$1, %edi
	call	sleep
	jmp	.L2
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Gentoo 4.9.3 p1.5, pie-0.6.4) 4.9.3"
	.section	.note.GNU-stack,"",@progbits
