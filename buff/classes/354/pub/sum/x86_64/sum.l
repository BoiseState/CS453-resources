   1              		.file	"sum.c"
   2              	# GNU C17 (GCC) version 8.3.1 20190223 (Red Hat 8.3.1-2) (x86_64-redhat-linux)
   3              	#	compiled by GNU C version 8.3.1 20190223 (Red Hat 8.3.1-2), GMP version 6.1.2, MPFR version 3.1.6
   4              	# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
   5              	# options passed:  sum.c -mtune=generic -march=x86-64 -fverbose-asm
   6              	# options enabled:  -faggressive-loop-optimizations
   7              	# -fasynchronous-unwind-tables -fauto-inc-dec -fchkp-check-incomplete-type
   8              	# -fchkp-check-read -fchkp-check-write -fchkp-instrument-calls
   9              	# -fchkp-narrow-bounds -fchkp-optimize -fchkp-store-bounds
  10              	# -fchkp-use-static-bounds -fchkp-use-static-const-bounds
  11              	# -fchkp-use-wrappers -fcommon -fdelete-null-pointer-checks
  12              	# -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
  13              	# -ffp-int-builtin-inexact -ffunction-cse -fgcse-lm -fgnu-runtime
  14              	# -fgnu-unique -fident -finline-atomics -fira-hoist-pressure
  15              	# -fira-share-save-slots -fira-share-spill-slots -fivopts
  16              	# -fkeep-static-consts -fleading-underscore -flifetime-dse
  17              	# -flto-odr-type-merging -fmath-errno -fmerge-debug-strings -fpeephole
  18              	# -fplt -fprefetch-loop-arrays -freg-struct-return
  19              	# -fsched-critical-path-heuristic -fsched-dep-count-heuristic
  20              	# -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
  21              	# -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
  22              	# -fsched-stalled-insns-dep -fschedule-fusion -fsemantic-interposition
  23              	# -fshow-column -fshrink-wrap-separate -fsigned-zeros
  24              	# -fsplit-ivs-in-unroller -fssa-backprop -fstdarg-opt
  25              	# -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math -ftree-cselim
  26              	# -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
  27              	# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop
  28              	# -ftree-reassoc -ftree-scev-cprop -funit-at-a-time -funwind-tables
  29              	# -fverbose-asm -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387
  30              	# -malign-stringops -mavx256-split-unaligned-load
  31              	# -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387 -mfxsr
  32              	# -mglibc -mieee-fp -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone
  33              	# -msse -msse2 -mstv -mtls-direct-seg-refs -mvzeroupper
  34              	
  35              		.text
  37              	sum:
  38              	.LFB0:
  39              		.cfi_startproc
  40 0000 55       		pushq	%rbp	#
  41              		.cfi_def_cfa_offset 16
  42              		.cfi_offset 6, -16
  43 0001 4889E5   		movq	%rsp, %rbp	#,
  44              		.cfi_def_cfa_register 6
  45 0004 48897DE8 		movq	%rdi, -24(%rbp)	# seq, seq
  46 0008 8975E4   		movl	%esi, -28(%rbp)	# n, n
  47              	# sum.c:6:   int s=0;
  48 000b C745FC00 		movl	$0, -4(%rbp)	#, s
  48      000000
  49              	# sum.c:8:   for (i=0; i<n; i++)
  50 0012 C745F800 		movl	$0, -8(%rbp)	#, i
  50      000000
  51              	# sum.c:8:   for (i=0; i<n; i++)
  52 0019 EB1D     		jmp	.L2	#
  53              	.L3:
  54              	# sum.c:9:     s+=seq[i];
  55 001b 8B45F8   		movl	-8(%rbp), %eax	# i, tmp93
  56 001e 4898     		cltq
  57 0020 488D1485 		leaq	0(,%rax,4), %rdx	#, _2
  57      00000000 
  58 0028 488B45E8 		movq	-24(%rbp), %rax	# seq, tmp94
  59 002c 4801D0   		addq	%rdx, %rax	# _2, _3
  60 002f 8B00     		movl	(%rax), %eax	# *_3, _4
  61              	# sum.c:9:     s+=seq[i];
  62 0031 0145FC   		addl	%eax, -4(%rbp)	# _4, s
  63              	# sum.c:8:   for (i=0; i<n; i++)
  64 0034 8345F801 		addl	$1, -8(%rbp)	#, i
  65              	.L2:
  66              	# sum.c:8:   for (i=0; i<n; i++)
  67 0038 8B45F8   		movl	-8(%rbp), %eax	# i, tmp95
  68 003b 3B45E4   		cmpl	-28(%rbp), %eax	# n, tmp95
  69 003e 7CDB     		jl	.L3	#,
  70              	# sum.c:10:   return s;
  71 0040 8B45FC   		movl	-4(%rbp), %eax	# s, _14
  72              	# sum.c:11: }
  73 0043 5D       		popq	%rbp	#
  74              		.cfi_def_cfa 7, 8
  75 0044 C3       		ret	
  76              		.cfi_endproc
  77              	.LFE0:
  79              		.section	.rodata
  80              	.LC0:
  81 0000 25640A00 		.string	"%d\n"
  82              		.text
  83              		.globl	main
  85              	main:
  86              	.LFB1:
  87              		.cfi_startproc
  88 0045 55       		pushq	%rbp	#
  89              		.cfi_def_cfa_offset 16
  90              		.cfi_offset 6, -16
  91 0046 4889E5   		movq	%rsp, %rbp	#,
  92              		.cfi_def_cfa_register 6
  93 0049 4883EC20 		subq	$32, %rsp	#,
  94              	# sum.c:14:   const int n=6;
  95 004d C745FC06 		movl	$6, -4(%rbp)	#, n
  95      000000
  96              	# sum.c:15:   int seq[]={5,6,1,8,3,7};
  97 0054 C745E005 		movl	$5, -32(%rbp)	#, seq
  97      000000
  98 005b C745E406 		movl	$6, -28(%rbp)	#, seq
  98      000000
  99 0062 C745E801 		movl	$1, -24(%rbp)	#, seq
  99      000000
 100 0069 C745EC08 		movl	$8, -20(%rbp)	#, seq
 100      000000
 101 0070 C745F003 		movl	$3, -16(%rbp)	#, seq
 101      000000
 102 0077 C745F407 		movl	$7, -12(%rbp)	#, seq
 102      000000
 103              	# sum.c:16:   printf("%d\n",sum(seq,n));
 104 007e 8B55FC   		movl	-4(%rbp), %edx	# n, tmp90
 105 0081 488D45E0 		leaq	-32(%rbp), %rax	#, tmp91
 106 0085 89D6     		movl	%edx, %esi	# tmp90,
 107 0087 4889C7   		movq	%rax, %rdi	# tmp91,
 108 008a E871FFFF 		call	sum	#
 108      FF
 109 008f 89C6     		movl	%eax, %esi	# _1,
 110 0091 BF000000 		movl	$.LC0, %edi	#,
 110      00
 111 0096 B8000000 		movl	$0, %eax	#,
 111      00
 112 009b E8000000 		call	printf	#
 112      00
 113              	# sum.c:17:   return 0;
 114 00a0 B8000000 		movl	$0, %eax	#, _12
 114      00
 115              	# sum.c:18: }
 116 00a5 C9       		leave	
 117              		.cfi_def_cfa 7, 8
 118 00a6 C3       		ret	
 119              		.cfi_endproc
 120              	.LFE1:
 122              		.ident	"GCC: (GNU) 8.3.1 20190223 (Red Hat 8.3.1-2)"
 123              		.section	.note.GNU-stack,"",@progbits
DEFINED SYMBOLS
                            *ABS*:0000000000000000 sum.c
     /tmp/ccL4rKgN.s:37     .text:0000000000000000 sum
     /tmp/ccL4rKgN.s:85     .text:0000000000000045 main

UNDEFINED SYMBOLS
printf
