	.arch armv8-a
	.file	"sum.c"
	.text
	.align	2
	.type	sum, %function
sum:
	sub	sp, sp, #32
	str	x0, [sp, 8]
	str	w1, [sp, 4]
	str	wzr, [sp, 24]
	str	wzr, [sp, 28]
	b	.L2
.L3:
	ldrsw	x0, [sp, 28]
	lsl	x0, x0, 2
	ldr	x1, [sp, 8]
	add	x0, x1, x0
	ldr	w0, [x0]
	ldr	w1, [sp, 24]
	add	w0, w1, w0
	str	w0, [sp, 24]
	ldr	w0, [sp, 28]
	add	w0, w0, 1
	str	w0, [sp, 28]
.L2:
	ldr	w1, [sp, 28]
	ldr	w0, [sp, 4]
	cmp	w1, w0
	blt	.L3
	ldr	w0, [sp, 24]
	add	sp, sp, 32
	ret
	.size	sum, .-sum
	.section	.rodata
	.align	3
.LC1:
	.string	"%d\n"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	stp	x29, x30, [sp, -64]!
	add	x29, sp, 0
	adrp	x0, :got:__stack_chk_guard
	ldr	x0, [x0, #:got_lo12:__stack_chk_guard]
	ldr	x1, [x0]
	str	x1, [x29, 56]
	mov	x1,0
	mov	w0, 6
	str	w0, [x29, 28]
	adrp	x0, .LC0
	add	x0, x0, :lo12:.LC0
	add	x2, x29, 32
	mov	x3, x0
	ldp	x0, x1, [x3]
	stp	x0, x1, [x2]
	ldr	x0, [x3, 16]
	str	x0, [x2, 16]
	add	x0, x29, 32
	ldr	w1, [x29, 28]
	bl	sum
	mov	w1, w0
	adrp	x0, .LC1
	add	x0, x0, :lo12:.LC1
	bl	printf
	mov	w0, 0
	adrp	x1, :got:__stack_chk_guard
	ldr	x1, [x1, #:got_lo12:__stack_chk_guard]
	ldr	x2, [x29, 56]
	ldr	x1, [x1]
	eor	x1, x2, x1
	cmp	x1, 0
	beq	.L7
	bl	__stack_chk_fail
.L7:
	ldp	x29, x30, [sp], 64
	ret
	.size	main, .-main
	.section	.rodata
	.align	3
.LC0:
	.word	5
	.word	6
	.word	1
	.word	8
	.word	3
	.word	7
	.text
	.ident	"GCC: (Ubuntu/Linaro 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
