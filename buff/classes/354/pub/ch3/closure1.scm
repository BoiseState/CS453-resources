#!/bin/guile
!#

(define (g f)
  (let ((i 2))				;late/shallow
    (f)))

(define (closure)
  (let ((i 1))				;early/deep
    (define (f)
      (display i)
      (display "\n"))
    (g f)))

(closure)
