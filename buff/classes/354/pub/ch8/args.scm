#!/bin/guile
!#

(define (sum . seq)
  (define (sum1 seq)
    (if (null? seq)
      0
      (+ (car seq) (sum1 (cdr seq)))))
  (sum1 seq))

(display (sum 5 6 1 8 3 7))
(display "\n")
