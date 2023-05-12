#!/bin/guile
!#

(define (f e)
  (display e)
  (display "\n"))

(define a '(1 "hi" 2))

(map f a)

