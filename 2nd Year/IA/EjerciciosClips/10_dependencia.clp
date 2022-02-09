(deftemplate Producto
	(field CodigoVendedor)
	(field CodigoProducto)
	(field PVPProducto)
)
(defrule comprobacion_positiva
	(Producto
		(CodigoVendedor ?cv1)
		(CodigoProducto ?cp1)
		(PVPProducto ?pvp1)
	)
	(Producto
		(CodigoVendedor ?cv2)
		(CodigoProducto ?cp2)
		(PVPProducto ?pvp2)
	)
	(test(<> ?cv1 ?cv2))
	(test(= ?cp1 ?cp2))
	(test(= ?pvp1 ?pvp2))
	=>
	(assert (confirmado ?cv1 ?cv2 ?cp1 ?cp2 ?pvp1 ?pvp2))
)
(defrule comprobacion_negativa
	(Producto
		(CodigoVendedor ?cv1)
		(CodigoProducto ?cp1)
		(PVPProducto ?pvp1)
	)
	(Producto
		(CodigoVendedor ?cv2)
		(CodigoProducto ?cp2)
		(PVPProducto ?pvp2)
	)
	(test(<> ?cv1 ?cv2))
	(test(= ?cp1 ?cp2))
	(test(<> ?pvp1 ?pvp2))
	=>
	(assert (negativo ?cv1 ?cv2 ?cp1 ?cp2 ?pvp1 ?pvp2))
)
(defrule mostrar_positivos
	(confirmado ?c_cv1 ?c_cv2 ?c_cp1 ?c_cp2 ?c_pvp1 ?c_pvp2)
	?caso <-(confirmado ?c_cv2 ?c_cv1 ?c_cp1 ?c_cp2 ?c_pvp1 ?c_pvp2)
	=>
	(retract ?caso)
	(printout t "Los vendedores " ?c_cv1 " y " ?c_cv2 " cumplen la regla con CodigoProducto(" ?c_cp1 ")" crlf)
)
(defrule mostrar_negativos
	(negativo ?n_cv1 ?n_cv2 ?n_cp1 ?n_cp2 ?n_pvp1 ?n_pvp2)
	?caso <-(negativo ?n_cv2 ?n_cv1 ?n_cp1 ?n_cp2 ?n_pvp2 ?n_pvp1)
	=>
	(retract ?caso)
	(printout t "Los vendedores " ?n_cv1 " y " ?n_cv2 " no cumplen la regla con CodigoProducto(" ?n_cp1 ")" crlf)
)