(defrule Forrado
	(declare (salience 100))
	(Articulo 
		(Nombre ?Nm)
		(Tipo ?T) 
		(Forrado No) 
		(Empaquetado No)
		(Dimension ?D)
	)
	?art <- (Articulo (Nombre ?Nm)(Tipo ?T) (Forrado No) (Empaquetado No)(Dimension ?D))
	=>
	(retract ?art)
	(printout t "Se forra el articulo cuyo nombre es : " ?Nm " y su tipo: " ?T crlf)
	(assert (Articulo (Nombre ?Nm)(Tipo ?T) (Forrado Si) (Empaquetado No)(Dimension ?D)))
)
	
(defrule Empaquetado
	(declare (salience 99))
	(Articulo 
		(Nombre ?Nm)
		(Tipo ?T) 
		(Forrado Si) 
		(Empaquetado No)
		(Dimension ?D)
	)
	?art <- (Articulo (Nombre ?Nm)(Tipo ?T) (Forrado Si) (Empaquetado No)(Dimension ?D))
	(Caja
		(IdCaja ?I)
		(Abierta Si)
		(Empezada ?E)
		(TipoContenido ?T)
		(EspacioLibre ?L)
	)
	?caj <- (Caja (IdCaja ?I)(Abierta Si)(Empezada ?E)(TipoContenido ?T)(EspacioLibre ?L))
	(test (< ?D ?L))
	=>
	(retract ?art ?caj)
	(printout t "Se empaqueta el articulo cuyo nombre es : " ?Nm " y su tipo: " ?T  " en la caja " ?I crlf)
	(assert (Articulo (Nombre ?Nm)(Tipo ?T) (Forrado Si) (Empaquetado Si)(Dimension ?D)))
	(bind ?L (- ?L ?D))
	(assert(Caja (IdCaja ?I)(Abierta Si)(Empezada Si)(TipoContenido ?T)(EspacioLibre ?L)))
	if (= ?L 0)
	then (printout t "La caja " ?I " esta llena" crlf)
)





