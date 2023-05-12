(defun f ()
  (message "%d" i)
  (sleep-for 3))

(defun g ()
  (let ((i 2))
    (f)))

(let ((i 1))
  (f)
  (g))

