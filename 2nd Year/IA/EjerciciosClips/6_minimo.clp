(deffacts Minimo
	(elemento 3)
  	(elemento 6)
  	(elemento 26)
  	(elemento 36)
  	(elemento 60)
  	(elemento 66))

(defrule ElementoMinimo
(elemento $? ?x $?)
(not (elemento $? ?y&:(< ?y ?x) $?))
=>
(printout t "El minimo es "?x crlf))