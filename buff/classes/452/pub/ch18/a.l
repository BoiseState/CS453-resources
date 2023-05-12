   1              		.file	"a.c"
   2              	# GNU C17 (GCC) version 10.3.1 20210422 (Red Hat 10.3.1-1) (x86_64-redhat-linux)
   3              	#	compiled by GNU C version 10.3.1 20210422 (Red Hat 10.3.1-1), GMP version 6.1.2, MPFR version 4.0
   4              	# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
   5              	# options passed:  a.c -mtune=generic -march=x86-64 -fverbose-asm
   6              	# options enabled:  -faggressive-loop-optimizations -fallocation-dce
   7              	# -fasynchronous-unwind-tables -fauto-inc-dec -fdelete-null-pointer-checks
   8              	# -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-symbols
   9              	# -feliminate-unused-debug-types -ffp-int-builtin-inexact -ffunction-cse
  10              	# -fgcse-lm -fgnu-unique -fident -finline-atomics -fipa-stack-alignment
  11              	# -fira-hoist-pressure -fira-share-save-slots -fira-share-spill-slots
  12              	# -fivopts -fkeep-static-consts -fleading-underscore -flifetime-dse
  13              	# -fmath-errno -fmerge-debug-strings -fpeephole -fplt
  14              	# -fprefetch-loop-arrays -freg-struct-return
  15              	# -fsched-critical-path-heuristic -fsched-dep-count-heuristic
  16              	# -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
  17              	# -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
  18              	# -fsched-stalled-insns-dep -fschedule-fusion -fsemantic-interposition
  19              	# -fshow-column -fshrink-wrap-separate -fsigned-zeros
  20              	# -fsplit-ivs-in-unroller -fssa-backprop -fstdarg-opt
  21              	# -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math -ftree-cselim
  22              	# -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
  23              	# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop
  24              	# -ftree-reassoc -ftree-scev-cprop -funit-at-a-time -funwind-tables
  25              	# -fverbose-asm -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387
  26              	# -malign-stringops -mavx256-split-unaligned-load
  27              	# -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387 -mfxsr
  28              	# -mglibc -mieee-fp -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone
  29              	# -msse -msse2 -mstv -mtls-direct-seg-refs -mvzeroupper
  30              	
  31              		.text
  32              		.globl	i
  33              		.bss
  34              		.align 4
  37              	i:
  38 0000 00000000 		.zero	4
  39              		.globl	a
  40 0004 00000000 		.align 32
  40      00000000 
  40      00000000 
  40      00000000 
  40      00000000 
  43              	a:
  44 0020 00000000 		.zero	40
  44      00000000 
  44      00000000 
  44      00000000 
  44      00000000 
  45              		.text
  46              		.globl	main
  48              	main:
  49              	.LFB0:
  50              		.cfi_startproc
  51 0000 55       		pushq	%rbp	#
  52              		.cfi_def_cfa_offset 16
  53              		.cfi_offset 6, -16
  54 0001 4889E5   		movq	%rsp, %rbp	#,
  55              		.cfi_def_cfa_register 6
  56              	# a.c:6:   for (i=0; i<10; i++)
  57 0004 C7050000 		movl	$0, i(%rip)	#, i
  57      00000000 
  57      0000
  58              	# a.c:6:   for (i=0; i<10; i++)
  59 000e EB22     		jmp	.L2	#
  60              	.L3:
  61              	# a.c:7:     a[i]=0;
  62 0010 8B050000 		movl	i(%rip), %eax	# i, i.0_1
  62      0000
  63              	# a.c:7:     a[i]=0;
  64 0016 4898     		cltq
  65 0018 C7048500 		movl	$0, a(,%rax,4)	#, a[i.0_1]
  65      00000000 
  65      000000
  66              	# a.c:6:   for (i=0; i<10; i++)
  67 0023 8B050000 		movl	i(%rip), %eax	# i, i.1_2
  67      0000
  68 0029 83C001   		addl	$1, %eax	#, _3
  69 002c 89050000 		movl	%eax, i(%rip)	# _3, i
  69      0000
  70              	.L2:
  71              	# a.c:6:   for (i=0; i<10; i++)
  72 0032 8B050000 		movl	i(%rip), %eax	# i, i.2_4
  72      0000
  73              	# a.c:6:   for (i=0; i<10; i++)
  74 0038 83F809   		cmpl	$9, %eax	#, i.2_4
  75 003b 7ED3     		jle	.L3	#,
  76 003d B8000000 		movl	$0, %eax	#, _8
  76      00
  77              	# a.c:8: }
  78 0042 5D       		popq	%rbp	#
  79              		.cfi_def_cfa 7, 8
  80 0043 C3       		ret	
  81              		.cfi_endproc
  82              	.LFE0:
  84              		.ident	"GCC: (GNU) 10.3.1 20210422 (Red Hat 10.3.1-1)"
  85              		.section	.note.GNU-stack,"",@progbits
DEFINED SYMBOLS
                            *ABS*:0000000000000000 a.c
     /tmp/ccPVB4pi.s:37     .bss:0000000000000000 i
     /tmp/ccPVB4pi.s:43     .bss:0000000000000020 a
     /tmp/ccPVB4pi.s:48     .text:0000000000000000 main

NO UNDEFINED SYMBOLS
