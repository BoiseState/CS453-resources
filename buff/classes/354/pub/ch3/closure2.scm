#!/bin/guile
!#

(define v 0)				;"global" variable: ugh!

(define (g f)
  (set! v f))				;assignment "statement": ugh!

(define (closure)
  (let ((i 1))				;early/deep
    (define (f)
      (display i)
      (display "\n"))
    (g f)))

(closure)
(let ((i 2))				;late/shallow
  (v))
(v)
