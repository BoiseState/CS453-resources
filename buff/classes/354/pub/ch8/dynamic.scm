#!/bin/guile
!#

(define (main)
  (let ((flu (make-fluid 1)))

    (define (f)
      (display (fluid-ref flu))
      (newline))

    (f)
    (with-fluids ((flu 2))
		 (f))
    (f)))

(main)


