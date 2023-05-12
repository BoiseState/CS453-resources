(defun g (f)
  (let ((i 2))				;late/shallow
    (funcall f)))

(defun closure ()
  (let ((i 1))				;early/deep
    (defun f ()
      (print i))
    (g (function f))))

(closure)
