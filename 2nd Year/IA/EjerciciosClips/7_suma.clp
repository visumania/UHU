(deftemplate Suma
	(field elem1)
	(field elem2)
	(field elem3))
	
(deffacts SumaElementos
	(Suma
		(elem1 3)
  		(elem2 6)
  		(elem3 26)))

(defrule SumaVector
	(Suma
		(elem1 ?elem1)
		(elem2 ?elem2)
		(elem3 ?elem3))
		=>
(bind ?Total (+ ?elem1 ?elem2 ?elem3))
(printout t "La suma de los elementos es = " ?Total crlf))