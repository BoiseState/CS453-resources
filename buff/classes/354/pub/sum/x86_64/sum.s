	.text
	.globl	_start
_start:
	mov	$n,%rbx	        # number of ints to sum
	mov	$seqbeg,%rsi	# ints to sum
	call	sum		# %rax=sum(%rsi,%rbx)
	mov	$bufend,%rsi	# addr of newline
	call	itoa		# %rsi=itoa(%rax,%rsi)
	call	puts		# puts(%rsi)
	mov	$0,%rdi		# exit code
	mov	$60,%rax	# exit()
	syscall

############################################################1

# %rax=sum(%rsi,%rbx)
sum:	mov	$0,%rax
1:	cmp	$0,%rbx
	je	2f
	dec	%rbx
	add	(%rsi),%rax
	add	$8,%rsi
	jmp	1b
2:	ret

# %rsi=itoa(%rax,%rsi)
itoa:
1:	mov	$10,%rbx	# div/rem by ten
	call	divide		# %rax,%rdx=divide(%rax,%rbx)
	add	$'0,%dl		# ascii-fy digit
	dec	%rsi
	mov	%dl,(%rsi)
	cmp	$0,%rax
	jne	1b
	ret
	
# %rax,%rdx=divide(%rax,%rbx)
divide:
	mov	%rax,%rdx
	shr	$32,%rdx	# %rdl=%rdh, %rdh=0
	mov	%eax,%eax	# %rah=0 (tricky!)
	div	%ebx		# %eax,%edx=[%edx:%eax]/%ebx
	ret
	
# puts(%rsi)
puts:	call	strlen		# %rdx=strlen(%rsi)
	mov	$1,%rdi		# stdout
	mov	$1,%rax		# write()
	syscall
	ret
	
# %rdx=strlen(%rsi)
strlen: mov	$0,%rdx
1:	mov	(%rsi,%rdx),%al
	cmp	$0,%al
	je	2f
	inc	%rdx
	jmp	1b
2:	ret

	.data
seqbeg:	.quad	5,6,1,8,3,7     	# ints to sum
seqend:	
bufbeg:	.space  19			# biggest 64-bit decimal number
bufend: .string	"\n"			# newline
	.set	n,(seqend-seqbeg)/8   	# number of ints to sum
