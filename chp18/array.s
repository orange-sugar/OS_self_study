	.text
	.file	"array.c"
	.globl	test                            # -- Begin function test
	.p2align	4, 0x90
	.type	test,@function
test:                                   # @test
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$3888, %rsp                     # imm = 0xF30
	movl	$0, -4004(%rbp)
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	cmpl	$1000, -4004(%rbp)              # imm = 0x3E8
	jge	.LBB0_4
# %bb.2:                                #   in Loop: Header=BB0_1 Depth=1
	movslq	-4004(%rbp), %rax
	movl	$0, -4000(%rbp,%rax,4)
# %bb.3:                                #   in Loop: Header=BB0_1 Depth=1
	movl	-4004(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4004(%rbp)
	jmp	.LBB0_1
.LBB0_4:
	addq	$3888, %rsp                     # imm = 0xF30
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	test, .Lfunc_end0-test
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 12.0.0-3ubuntu1~20.04.4"
	.section	".note.GNU-stack","",@progbits
	.addrsig
