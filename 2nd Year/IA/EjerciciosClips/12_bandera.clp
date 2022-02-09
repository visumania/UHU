(deftemplate bandera
	(field Pais)
	(multifield Bandera))



(defrule pedir_color
	?fase <- (fase pedir_color)
	=>
	(retract ?fase)
	(printout t "Introduzca un color: ")
	(assert (color (read)))
	(assert (fase pedir_respuesta)))

(defrule pedir_respuesta
	?fase <- (fase pedir_respuesta)
	=>
	(retract ?fase)
	(printout t "¿Quiere introducir otro color? (s/n) ")
	(assert (respuesta (read))
	(fase comprobar_respuesta)))

(defrule respuesta_no
	?fase <- (fase comprobar_respuesta)
	?respuesta <- (respuesta n)
	=>
	(retract ?fase ?respuesta)
	(assert (fase calcular)))

(defrule respuesta_si
	?fase <- (fase comprobar_respuesta)
	?respuesta <- (respuesta s)
	=>
	(retract ?fase ?respuesta)
	(assert (fase pedir_color)))

(defrule respuesta_incorrecta
	?fase <- (fase comprobar_respuesta)
	?respuesta <- (respuesta ~s&~n)
	=>
	(retract ?fase ?respuesta)
	(assert (fase pedir_respuesta))
	(printout t "Responda 's' o 'n'" crlf))

(defrule banderas_colores
	(fase calcular)
	(bandera (Pais ?Pais))
	(forall (color ?color)
		(bandera (Pais ?Pais) (Bandera $? ?color $?)))
	=>
	(printout t ?Pais crlf))