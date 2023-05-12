#!/bin/guile
!#

; The Y-Combinator: repetition without recursion or iteration.

(define (fact f n)
  (if (zero? n)
      1
    (* n (f f (- n 1)))))

(define (Y f n)
  (f f n))

(display (Y fact 5))
(newline)
