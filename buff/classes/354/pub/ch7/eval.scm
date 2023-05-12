#!/bin/guile
!#

(let ((prog (cons 'display (cons "Hi!" '()))))
  (display "\n")
  (display prog)
  (display "\n")
  (eval prog (interaction-environment))
  (display "\n"))
