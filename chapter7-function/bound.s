	.file	"bound.c"
# GNU C11 (Ubuntu 7.5.0-3ubuntu1~18.04) version 7.5.0 (x86_64-linux-gnu)
#	compiled by GNU C version 7.5.0, GMP version 6.1.2, MPFR version 4.0.1, MPC version 1.1.0, isl version isl-0.19-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu bound.c -mtune=generic
# -march=x86-64 -Og -fverbose-asm -fstack-protector-strong -Wformat
# -Wformat-security
# options enabled:  -fPIC -fPIE -faggressive-loop-optimizations
# -fasynchronous-unwind-tables -fauto-inc-dec -fchkp-check-incomplete-type
# -fchkp-check-read -fchkp-check-write -fchkp-instrument-calls
# -fchkp-narrow-bounds -fchkp-optimize -fchkp-store-bounds
# -fchkp-use-static-bounds -fchkp-use-static-const-bounds
# -fchkp-use-wrappers -fcombine-stack-adjustments -fcommon -fcompare-elim
# -fcprop-registers -fdefer-pop -fdelete-null-pointer-checks
# -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
# -fforward-propagate -ffp-int-builtin-inexact -ffunction-cse -fgcse-lm
# -fgnu-runtime -fgnu-unique -fguess-branch-probability -fident -finline
# -finline-atomics -fipa-profile -fipa-pure-const -fipa-reference
# -fira-hoist-pressure -fira-share-save-slots -fira-share-spill-slots
# -fivopts -fkeep-static-consts -fleading-underscore -flifetime-dse
# -flto-odr-type-merging -fmath-errno -fmerge-constants
# -fmerge-debug-strings -fomit-frame-pointer -fpeephole -fplt
# -fprefetch-loop-arrays -freg-struct-return -freorder-blocks
# -fsched-critical-path-heuristic -fsched-dep-count-heuristic
# -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
# -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
# -fsched-stalled-insns-dep -fschedule-fusion -fsemantic-interposition
# -fshow-column -fshrink-wrap -fshrink-wrap-separate -fsigned-zeros
# -fsplit-ivs-in-unroller -fsplit-wide-types -fssa-backprop
# -fstack-protector-strong -fstdarg-opt -fstrict-volatile-bitfields
# -fsync-libcalls -ftoplevel-reorder -ftrapping-math
# -ftree-builtin-call-dce -ftree-ccp -ftree-ch -ftree-coalesce-vars
# -ftree-copy-prop -ftree-cselim -ftree-dce -ftree-dominator-opts
# -ftree-dse -ftree-forwprop -ftree-fre -ftree-loop-if-convert
# -ftree-loop-im -ftree-loop-ivcanon -ftree-loop-optimize
# -ftree-parallelize-loops= -ftree-phiprop -ftree-reassoc -ftree-scev-cprop
# -ftree-sink -ftree-slsr -ftree-ter -funit-at-a-time -funwind-tables
# -fverbose-asm -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387
# -malign-stringops -mavx256-split-unaligned-load
# -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387 -mfxsr
# -mglibc -mieee-fp -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone
# -msse -msse2 -mstv -mtls-direct-seg-refs -mvzeroupper

	.text
	.globl	main
	.type	main, @function
main:
.LFB23:
	.cfi_startproc
# bound.c:20: }
	movl	$0, %eax	#,
	ret
	.cfi_endproc
.LFE23:
	.size	main, .-main
	.globl	f
	.type	f, @function
f:
.LFB24:
	.cfi_startproc
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
# bound.c:23: void f(unsigned int size) {
	movq	%fs:40, %rax	#, tmp106
	movq	%rax, -8(%rbp)	# tmp106, D.2470
	xorl	%eax, %eax	# tmp106
# bound.c:24:     int arr[size];
	movl	%edi, %edi	# size, size
	leaq	18(,%rdi,4), %rax	#, tmp95
	shrq	$4, %rax	#, tmp97
	salq	$4, %rax	#, tmp99 ; ax = 4k
	subq	%rax, %rsp	# tmp99, ; sp = sp0 - 4k
	leaq	3(%rsp), %rax	#, tmp101 ; ax = sp0 - 4k + 3
	shrq	$2, %rax	#, tmp102 ; ax = (sp0 - 4k + 3) / 4
# bound.c:25:     arr[1] = 99;
	movl	$99, 4(,%rax,4)	#, *arr.1_8
# bound.c:26: }
	movq	-8(%rbp), %rax	# D.2470, tmp107
	xorq	%fs:40, %rax	#, tmp107
	jne	.L5	#,
	leave
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.L5:
	.cfi_restore_state
	call	__stack_chk_fail@PLT	#
	.cfi_endproc
.LFE24:
	.size	f, .-f
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
