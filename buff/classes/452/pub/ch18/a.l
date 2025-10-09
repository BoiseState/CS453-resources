   1              		.file	"a.c"
   2              	# GNU C17 (GCC) version 14.3.1 20250523 (Red Hat 14.3.1-1) (x86_64-redhat-linux)
   3              	#	compiled by GNU C version 14.3.1 20250523 (Red Hat 14.3.1-1), GMP version 6.3.0, MPFR version 4.2
   4              	# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
   5              	# options passed: -mtune=generic -march=x86-64
   6              		.text
   7              		.globl	i
   8              		.bss
   9              		.align 4
  12              	i:
  13 0000 00000000 		.zero	4
  14              		.globl	a
  15 0004 00000000 		.align 32
  15      00000000 
  15      00000000 
  15      00000000 
  15      00000000 
  18              	a:
  19 0020 00000000 		.zero	40
  19      00000000 
  19      00000000 
  19      00000000 
  19      00000000 
  20              		.text
  21              		.globl	main
  23              	main:
  24              	.LFB0:
  25              		.cfi_startproc
  26 0000 55       		pushq	%rbp	#
  27              		.cfi_def_cfa_offset 16
  28              		.cfi_offset 6, -16
  29 0001 4889E5   		movq	%rsp, %rbp	#,
  30              		.cfi_def_cfa_register 6
  31              	# a.c:8:   for (i=0; i<10; i++)
  32 0004 C7050000 		movl	$0, i(%rip)	#, i
  32      00000000 
  32      0000
  33              	# a.c:8:   for (i=0; i<10; i++)
  34 000e EB22     		jmp	.L2	#
  35              	.L3:
  36              	# a.c:9:     a[i]=0;
  37 0010 8B050000 		movl	i(%rip), %eax	# i, i.0_1
  37      0000
  38              	# a.c:9:     a[i]=0;
  39 0016 4898     		cltq
  40 0018 C7048500 		movl	$0, a(,%rax,4)	#, a[i.0_1]
  40      00000000 
  40      000000
  41              	# a.c:8:   for (i=0; i<10; i++)
  42 0023 8B050000 		movl	i(%rip), %eax	# i, i.1_2
  42      0000
  43 0029 83C001   		addl	$1, %eax	#, _3
  44 002c 89050000 		movl	%eax, i(%rip)	# _3, i
  44      0000
  45              	.L2:
  46              	# a.c:8:   for (i=0; i<10; i++)
  47 0032 8B050000 		movl	i(%rip), %eax	# i, i.2_4
  47      0000
  48 0038 83F809   		cmpl	$9, %eax	#, i.2_4
  49 003b 7ED3     		jle	.L3	#,
  50 003d B8000000 		movl	$0, %eax	#, _8
  50      00
  51              	# a.c:10: }
  52 0042 5D       		popq	%rbp	#
  53              		.cfi_def_cfa 7, 8
  54 0043 C3       		ret	
  55              		.cfi_endproc
  56              	.LFE0:
  58              		.ident	"GCC: (GNU) 14.3.1 20250523 (Red Hat 14.3.1-1)"
  59              		.section	.note.GNU-stack,"",@progbits
DEFINED SYMBOLS
                            *ABS*:0000000000000000 a.c
     /tmp/ccp4sDgB.s:12     .bss:0000000000000000 i
     /tmp/ccp4sDgB.s:18     .bss:0000000000000020 a
     /tmp/ccp4sDgB.s:23     .text:0000000000000000 main

NO UNDEFINED SYMBOLS
