#!/bin/guile
!#

(define (proper? list)
  (cond ((list? list)
	 (or (null? list)
	     (and (proper? (car list))
		  (proper? (cdr list)))))
	((pair? list) #f)
	(else #t)))

(define (pr v) (display v) (display "\n"))

(pr (proper? 123))
(pr (proper? '()))
(pr (proper? '(a b)))
(pr (proper? '(a . b)))
(pr (proper? '((((a . b))) c)))
