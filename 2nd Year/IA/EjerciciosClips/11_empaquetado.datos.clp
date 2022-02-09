(deftemplate Articulo
 (field Nombre)
 (field Tipo)   ; Valores permitidos: fragil, pesado
 (field Forrado)    ; Valores permitidos Si - No
 (field Empaquetado)  ; Valores permitidos Si - No
 (field Dimension)  ; Valor numérico de 0 a 200
)

(deftemplate Caja
 (field IdCaja)
 (field Abierta)   ; Valores permitidos Si - No
 (field Empezada)   ; Valores permitidos Si - No
 (field TipoContenido)  ; Valores permitidos: fragil, pesado 
 (field EspacioLibre)  ; Valor numérico que indica
     ; el espacio que todavía queda libre.
     ; Al principio, contiene la dimensión
     ; de la caja. Viene en las mismas 
     ; unidades que el field dimensión 
; del template Articulo.
)


(deffacts Inventario
	(Articulo
		(Nombre camara)
		(Tipo fragil)
		(Forrado No)
		(Empaquetado No)
		(Dimension 10))

	(Articulo
		(Nombre spinner)
		(Tipo pesado)
		(Forrado No)
		(Empaquetado No)
		(Dimension 5))

	(Articulo
		(Nombre movil)
		(Tipo fragil)
		(Forrado No)
		(Empaquetado No)
		(Dimension 10)))

(deffacts MisCajas
	(Caja
		(IdCaja 1)
		(Abierta Si)
		(Empezada No)
		(TipoContenido fragil)
		(EspacioLibre 6))

	(Caja
		(IdCaja 2)
		(Abierta Si)
		(Empezada No)
		(TipoContenido pesado)
		(EspacioLibre 11))

	(Caja
		(IdCaja 3)
		(Abierta No)
		(Empezada No)
		(TipoContenido fragil)
		(EspacioLibre 5)))