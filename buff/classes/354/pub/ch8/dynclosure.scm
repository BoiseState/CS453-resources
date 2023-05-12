#!/bin/guile
!#

(define (g f)
    (f))

(define (main)
  (let ((flu (make-fluid 1)))          ; early/deep

    (define (f)
      (display (fluid-ref flu))
      (newline))

    (with-fluids ((flu 2))
		 (g f))                ; late/shallow
    (g f)))

(main)
