(deftemplate Palabra
  	(multifield Caracter1)
  	(multifield Caracter2)
  	(multifield Caracter3)
	(multifield Caracter4))


(deffacts Sustituir
 	 (Palabra
    		(Caracter1 B)
    		(Caracter2 C)
    		(Caracter3 D)
		(Caracter4 Z)))


;Reglas

(defrule Cambiar1
  ?indice <- (Palabra (Caracter2 ?Caracter2))
  =>
  (modify ?indice (Caracter2 D L))
  (printout t " Con la regla 1 se ha modificado " ?Caracter2 " por D L quedando el vector como B D L D Z"  crlf))


(defrule Cambiar2
  ?indice <- (Palabra (Caracter2 ?Caracter2))
  =>
  (modify ?indice (Caracter2 B M))
  (printout t " Con la regla 2 se ha modificado " ?Caracter2 " por B M quedando el vector como B B M D Z"  crlf))


(defrule Cambiar3
  ?indice <- (Palabra (Caracter1 ?Caracter1))
  =>
  (modify ?indice (Caracter1 M M))
  (printout t " Con la regla 3 se ha modificado " ?Caracter1 " por M M quedando el vector como M M C D Z"  crlf))


(defrule Cambiar4
  ?indice <- (Palabra (Caracter4 ?Caracter4))
  =>
  (modify ?indice (Caracter4 B B M))
  (printout t " Con la regla 2 se ha modificado " ?Caracter4 " por B B M quedando el vector como B C D B B M"  crlf))
