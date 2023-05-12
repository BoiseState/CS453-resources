#!/bin/guile
!#

(define (f a b c)
  (and a b c))

(define (g a b c)
  (or a b c))

(display (f #t #t "foo"))
(display "\n")

(display (g #f "bar" #t))
(display "\n")
