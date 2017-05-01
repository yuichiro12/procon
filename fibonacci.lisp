(defparameter *fibo* (make-hash-table))

(defun main ()
  (setf n (read))
  (fibonacci n))

(defun fibonacci (n)
  (if (> n 2)
	  (+ (or (gethash (- n 1) *fibo*)
			 (setf (gethash (- n 1) *fibo*) (fibonacci (- n 1))))
		 (or (gethash (- n 2) *fibo*)
			 (setf (gethash (- n 2) *fibo*) (fibonacci (- n 2)))))
	  1))

(defun fibonacci2 (n)
  (loop
	 with a1 = 1
	 and a2 = 1
	 for i from 3 to n
	 do (progn (setf tmp (+ a1 a2))
			   (setf a1 a2)
			   (setf a2 tmp))
	 finally (return a2)))
