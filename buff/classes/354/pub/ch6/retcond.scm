#!/bin/guile
!#

(define (f x)
  (cond ((eq? x 1) "foo")
	((eq? x 2) "bar")
	(else "zap")))

(display (f 2))
(display "\n")
