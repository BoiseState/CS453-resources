#!/usr/local/bin/guile
!#

(define (gcd a b)
  (cond ((= a b) a)
	((> a b) (gcd (- a b) b))
	(else (gcd (- b a) a))))

(display "(gcd 15 25)=")
(display (gcd 15 25))
(display "\n")
