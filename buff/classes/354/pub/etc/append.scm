#!/bin/guile
!#

; Both s and t are assumed to be lists.

(define (append s t)
  (if (pair? s)
      (cons (car s) (append (cdr s) t))
      t))

(display (append '() '(4 5 6)))
(newline)
(display (append '(1 2 3) '()))
(newline)
(display (append '(1 2 3) '(4 5 6)))
(newline)
