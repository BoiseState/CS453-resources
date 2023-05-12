; A function definition with abbreviation.
(define (f x) (+ 1 x))
(f 123)
f
(display f) (newline)

; A variable, define style.
; Formal parameters and let variables are preferred.
(define f (+ 1 123))
f
(display f) (newline)

; A function definition without abbreviation.
(define f (lambda (x) (+ 1 x)))
(f 123)
f
(display f) (newline)

; An unnamed function.
((lambda (x) (+ 1 x)) 123)
