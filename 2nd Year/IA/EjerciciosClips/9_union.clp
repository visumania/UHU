(deffacts datos-iniciales
	(cadena1 B C A D E E B C E)
	(cadena2 E E B F D E))

(defrule calcula-union
	=>
	(assert (union)))

(defrule union-base
	?union <- (union $?u)
	?cadena1 <- (cadena1 $?e-1)
	?cadena2 <- (cadena2)
	=>
	(retract ?cadena1 ?cadena2 ?union)
	(assert (union ?e-1 ?u))
	(assert (escribe-solucion)))

(defrule escribe-solucion
	(escribe-solucion)
	(union $?u)
	=>
	(printout t "La union es " ?u crlf))

(defrule union-con-primero-compartido
	?cadena2 <- (cadena2 ?e $?r-2)
	(cadena1 $? ?e $?)
	=>
	(retract ?cadena2)
	(assert (cadena2 ?r-2)))

(defrule union-con-primero-no-compartido
	?union <- (union $?u)
	?cadena2 <- (cadena2 ?e $?r-2)
	(not (conjunto-1 $? ?e $?))
	=>
	(retract ?cadena2 ?union)
	(assert (cadena2 ?r-2)
	(union ?u ?e)))