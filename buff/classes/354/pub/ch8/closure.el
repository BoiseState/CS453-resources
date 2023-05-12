; -*- lexical-binding: nil -*-
; (load "~/ws/354/pub/ch8/closure.el")
; (load "~/classes/354/pub/ch8/closure.el")

(defun g (f)
  (let ((i 2))				; late/shallow
    (f)))

(defun main ()
  (let ((i 1))				; early/deep
    (defun f ()
      (message "%d" i)
      (sleep-for 3))
    (g 'f)))

(main)
