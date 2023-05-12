(read) (+ 1 2)

(eval (read) (interaction-environment)) (+ 1 2)

(write (eval (read) (interaction-environment))) (+ 1 2)
