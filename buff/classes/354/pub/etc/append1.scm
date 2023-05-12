#!/bin/guile
!#

; this is just a stub
(define (copy x) x)

(define (append a b)
  (if (null? a)
      (copy b)
    (cons (car a) (append (cdr a) (copy b)))))

(display (append '(a b c) '(x y z)))
(display "\n")
