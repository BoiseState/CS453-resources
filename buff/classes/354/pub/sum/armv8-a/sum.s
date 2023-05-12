.macro zero r:req
 	mov	\r,0
.endm
.macro inc r:req
 	add	\r,\r,1
.endm
.macro dec r:req
 	sub	\r,\r,1
.endm
.macro push
 	str     lr,[sp,-16]!
.endm
.macro pop
 	ldr     lr,[sp],16
.endm
	
	.text
	.globl	_start
_start:
 	adr	x0,stack
 	mov	sp,x0
	
	ldr	x2,=n	        // number of ints to sum
	adr	x1,seqbeg	// ints to sum
	bl	sum		// x0=sum([x1],x2)
	adr	x1,bufend	// addr of newline
	bl	itoa		// [x1]=itoa(x0,[x1])
	bl	puts		// puts([x1)

	zero	x0		// exit code
	mov	x8,93		// exit()
	svc	0
	
# x0=sum([x1],x2), uses x3
sum:	push
	zero	x0		// result
1:	cbz	x2,2f		// done?
	dec	x2		// count
	ldr	x3,[x1],8	// next int
	add	x0,x0,x3	// add to result
	b	1b		// repeat
	pop
2:	ret

# [x1]=itoa(x0,[x1]), uses x2, x3
itoa:	push
1:	mov	x3,10		// div/rem by ten
	udiv	x2,x0,x3	// x2=x0/x3 (quotient)
	msub	x3,x2,x3,x0	// x3=x0-x2*x3 (remainder)
	add	x3,x3,'0	// ascii-fy remainder
	strb	w3,[x1,-1]! 	// *--x1=x3
	mov	x0,x2
	cbnz	x0,1b		// quotient==0?
	pop
	ret
	
# puts([x1])
puts:	push
	bl	strlen		// x2=strlen([x1])
	mov	x0,1		// stdout
	mov	x8,64		// write()
	svc	0
	pop
	ret
	
# x2=strlen([x1]), uses x0, x3
strlen: push
	zero	x2
	mov	x3,x1
1:	ldrb	w0,[x3],1
	cbz	w0,2f
	inc	x2
	b	1b
2:	pop
	ret

	.data
	.align 4
seqbeg:	.quad	5,6,1,8,3,7     	// ints to sum
seqend:	
bufbeg:	.space  19			// biggest 64-bit decimal number
bufend: .string	"\n"			// newline
	.set	n,(seqend-seqbeg)/8   	// number of ints to sum

	.align 4
	.space 1024
stack:
