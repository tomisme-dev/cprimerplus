	.file	"struct.c"
# GNU C11 (Ubuntu 7.5.0-3ubuntu1~18.04) version 7.5.0 (x86_64-linux-gnu)
#	compiled by GNU C version 7.5.0, GMP version 6.1.2, MPFR version 4.0.1, MPC version 1.1.0, isl version isl-0.19-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu struct.c -mtune=generic
# -march=x86-64 -fverbose-asm -fstack-protector-strong -Wformat
# -Wformat-security
# options enabled:  -fPIC -fPIE -faggressive-loop-optimizations
# -fasynchronous-unwind-tables -fauto-inc-dec -fchkp-check-incomplete-type
# -fchkp-check-read -fchkp-check-write -fchkp-instrument-calls
# -fchkp-narrow-bounds -fchkp-optimize -fchkp-store-bounds
# -fchkp-use-static-bounds -fchkp-use-static-const-bounds
# -fchkp-use-wrappers -fcommon -fdelete-null-pointer-checks
# -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
# -ffp-int-builtin-inexact -ffunction-cse -fgcse-lm -fgnu-runtime
# -fgnu-unique -fident -finline-atomics -fira-hoist-pressure
# -fira-share-save-slots -fira-share-spill-slots -fivopts
# -fkeep-static-consts -fleading-underscore -flifetime-dse
# -flto-odr-type-merging -fmath-errno -fmerge-debug-strings -fpeephole
# -fplt -fprefetch-loop-arrays -freg-struct-return
# -fsched-critical-path-heuristic -fsched-dep-count-heuristic
# -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
# -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
# -fsched-stalled-insns-dep -fschedule-fusion -fsemantic-interposition
# -fshow-column -fshrink-wrap-separate -fsigned-zeros
# -fsplit-ivs-in-unroller -fssa-backprop -fstack-protector-strong
# -fstdarg-opt -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math
# -ftree-cselim -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im
# -ftree-loop-ivcanon -ftree-loop-optimize -ftree-parallelize-loops=
# -ftree-phiprop -ftree-reassoc -ftree-scev-cprop -funit-at-a-time
# -funwind-tables -fverbose-asm -fzero-initialized-in-bss
# -m128bit-long-double -m64 -m80387 -malign-stringops
# -mavx256-split-unaligned-load -mavx256-split-unaligned-store
# -mfancy-math-387 -mfp-ret-in-387 -mfxsr -mglibc -mieee-fp
# -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone -msse -msse2
# -mstv -mtls-direct-seg-refs -mvzeroupper

	.text
	.section	.rodata
.LC0:
	.string	"%s, %d\n"
.LC1:
	.string	"%p, %p, %p\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$336, %rsp	#,
	movl	%edi, -324(%rbp)	# argc, argc
	movq	%rsi, -336(%rbp)	# argv, argv
# struct.c:12: {
	movq	%fs:40, %rax	#, tmp108
	movq	%rax, -8(%rbp)	# tmp108, D.2444
	xorl	%eax, %eax	# tmp108
# struct.c:14:     strcpy(s.name, "tome");
	leaq	-320(%rbp), %rax	#, tmp91
	movl	$1701670772, (%rax)	#, MEM[(void *)&s]
	movb	$0, 4(%rax)	#, MEM[(void *)&s]
# struct.c:15:     s.age = 12;
	movl	$12, -256(%rbp)	#, s.age
# struct.c:16:     printf("%s, %d\n", s.name, s.age);
	movl	-256(%rbp), %edx	# s.age, _1
	leaq	-320(%rbp), %rax	#, tmp92
	movq	%rax, %rsi	# tmp92,
	leaq	.LC0(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
# struct.c:18:     t_student s2 = {"jerry", 18};
	movabsq	$521611142506, %rax	#, tmp110
	movl	$0, %edx	#,
	movq	%rax, -240(%rbp)	# tmp110, s2.name
	movq	%rdx, -232(%rbp)	#, s2.name
	movq	$0, -224(%rbp)	#, s2.name
	movq	$0, -216(%rbp)	#, s2.name
	movq	$0, -208(%rbp)	#, s2.name
	movq	$0, -200(%rbp)	#, s2.name
	movq	$0, -192(%rbp)	#, s2.name
	movq	$0, -184(%rbp)	#, s2.name
	movl	$18, -176(%rbp)	#, s2.age
# struct.c:20:     t_student s4 = s2;
	movq	-240(%rbp), %rax	# s2, tmp93
	movq	-232(%rbp), %rdx	# s2,
	movq	%rax, -160(%rbp)	# tmp93, s4
	movq	%rdx, -152(%rbp)	#, s4
	movq	-224(%rbp), %rax	# s2, tmp94
	movq	-216(%rbp), %rdx	# s2,
	movq	%rax, -144(%rbp)	# tmp94, s4
	movq	%rdx, -136(%rbp)	#, s4
	movq	-208(%rbp), %rax	# s2, tmp95
	movq	-200(%rbp), %rdx	# s2,
	movq	%rax, -128(%rbp)	# tmp95, s4
	movq	%rdx, -120(%rbp)	#, s4
	movq	-192(%rbp), %rax	# s2, tmp96
	movq	-184(%rbp), %rdx	# s2,
	movq	%rax, -112(%rbp)	# tmp96, s4
	movq	%rdx, -104(%rbp)	#, s4
	movl	-176(%rbp), %eax	# s2, tmp97
	movl	%eax, -96(%rbp)	# tmp97, s4
# struct.c:21:     s4.age = 16;
	movl	$16, -96(%rbp)	#, s4.age
# struct.c:22:     printf("%s, %d\n", s2.name, s2.age);
	movl	-176(%rbp), %edx	# s2.age, _2
	leaq	-240(%rbp), %rax	#, tmp98
	movq	%rax, %rsi	# tmp98,
	leaq	.LC0(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
# struct.c:23:     printf("%p, %p, %p\n", &s, &s2, &s4);
	leaq	-160(%rbp), %rcx	#, tmp99
	leaq	-240(%rbp), %rdx	#, tmp100
	leaq	-320(%rbp), %rax	#, tmp101
	movq	%rax, %rsi	# tmp101,
	leaq	.LC1(%rip), %rdi	#,
	movl	$0, %eax	#,
	call	printf@PLT	#
# struct.c:26:     t_student s3 = {
	movabsq	$121382057112691, %rax	#, tmp111
	movl	$0, %edx	#,
	movq	%rax, -80(%rbp)	# tmp111, s3.name
	movq	%rdx, -72(%rbp)	#, s3.name
	movq	$0, -64(%rbp)	#, s3.name
	movq	$0, -56(%rbp)	#, s3.name
	movq	$0, -48(%rbp)	#, s3.name
	movq	$0, -40(%rbp)	#, s3.name
	movq	$0, -32(%rbp)	#, s3.name
	movq	$0, -24(%rbp)	#, s3.name
	movl	$12, -16(%rbp)	#, s3.age
# struct.c:31:     s3 = s2;
	movq	-240(%rbp), %rax	# s2, tmp102
	movq	-232(%rbp), %rdx	# s2,
	movq	%rax, -80(%rbp)	# tmp102, s3
	movq	%rdx, -72(%rbp)	#, s3
	movq	-224(%rbp), %rax	# s2, tmp103
	movq	-216(%rbp), %rdx	# s2,
	movq	%rax, -64(%rbp)	# tmp103, s3
	movq	%rdx, -56(%rbp)	#, s3
	movq	-208(%rbp), %rax	# s2, tmp104
	movq	-200(%rbp), %rdx	# s2,
	movq	%rax, -48(%rbp)	# tmp104, s3
	movq	%rdx, -40(%rbp)	#, s3
	movq	-192(%rbp), %rax	# s2, tmp105
	movq	-184(%rbp), %rdx	# s2,
	movq	%rax, -32(%rbp)	# tmp105, s3
	movq	%rdx, -24(%rbp)	#, s3
	movl	-176(%rbp), %eax	# s2, tmp106
	movl	%eax, -16(%rbp)	# tmp106, s3
# struct.c:33:     return 0;
	movl	$0, %eax	#, _16
# struct.c:34: }
	movq	-8(%rbp), %rcx	# D.2444, tmp109
	xorq	%fs:40, %rcx	#, tmp109
	je	.L3	#,
	call	__stack_chk_fail@PLT	#
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
