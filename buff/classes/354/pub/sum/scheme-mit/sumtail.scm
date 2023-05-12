; Scheme sum program

(define (sum seq)
  (define (sum seq res)
    (if (null? seq)
	res
	(sum (cdr seq) (+ res (car seq)))))
  (sum seq 0))

(display (sum '(5 6 1 8 3 7)))
(display "\n")
