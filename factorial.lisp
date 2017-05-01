(defun main ()
  (setq n (read))
  (factorial n))

(defun factorial (n)
  (if (> n 0)
	  (* n (factorial (- n 1)))
	  1))
