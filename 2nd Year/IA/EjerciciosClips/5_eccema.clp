(deftemplate FichaPaciente
	(field Nombre)
	(field Casado)
	(field Direccion))

(deftemplate DatosExploracion
	(field Nombre)
	(multifield Sintomas)
	(field GravedadAfeccion))

(deftemplate Diagnostico
	(field Nombre)
	(field Resultado)
	(field ProximaRevision))

(deftemplate DiagnosticoPersonas
	(field Nombre)
	(field Edad)
	(field Tipo))

(deftemplate Terapia
	(field Nombre)
	(field PrincipioActivo)
	(field Posologia))

(deftemplate Terapia2
	(field Nombre)
	(field Posologia))


;REGLAS

;APARTADO A

(defrule DiagnosticoEccema
	(DatosExploracion
		(Nombre ?N)
		(Sintomas $? picor $? vesiculas $?))
	(FichaPaciente
		(Nombre ?N))
	=>
(printout t "Posible diagn�stico para el paciente " ?N ": Eccema " crlf))


;APARTADO B

(defrule DiagnosticoGeneral
	(Diagnostico
		(Nombre ?Nombre)
		(Resultado ?Resultado)
		(ProximaRevision ?ProximaRevision))
		=>
		(printout t ?Nombre " tiene un resultado " ?Resultado " y su proxima revision es en " ?ProximaRevision crlf))


;APARTADO C

(defrule DiagnosticoEdad
	(DiagnosticoPersonas
		(Nombre ?Nombre)
		(Edad ?Edad)
		(Tipo ?Tipo))
		(test (< ?Edad 2))
		=>
		(printout t ?Nombre " tiene menos de dos a�o " ?Tipo crlf)) 


;APARTADO D

(defrule DiagnosticoTerapia
	(Terapia
		(Nombre ?Nombre)
		(PrincipioActivo ?PrincipioActivo)
		(Posologia ?Posologia))
		=>
		(printout t ?Nombre " es " ?PrincipioActivo " se le administrara " ?Posologia crlf))


;APARTADO E

(defrule TerapiaRecomendable
	(Terapia2
		(Nombre ?Nombre)
		(Posologia ?Posologia))
		=>
		(printout t "Es aconsejable para " ?Nombre " usar " ?Posologia crlf))
