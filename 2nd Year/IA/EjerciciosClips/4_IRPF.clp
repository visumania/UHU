(deftemplate Persona
    (field Nombre)
    (field Edad)
    (field NombreConyuge)
    (field PosicionEconomica)
    (field Salario))

;Hechos

(deffacts VariosHechos
	(Persona
		(Nombre Ricardo)
		(Edad 23)
		(NombreConyuge Maria)
		(PosicionEconomica Desahogada)
		(Salario 1000)))

(deffacts VariosHechos2
	(Persona
		(Nombre Ana)
		(Edad 40)
		(NombreConyuge Jose)
		(PosicionEconomica Desahogada)
		(Salario 12000)))

(deffacts VariosHechos3
	(Persona
		(Nombre Maria)
		(Edad 39)
		(NombreConyuge Marcos)
		(PosicionEconomica Dificultad)
		(Salario 1000)))

(deffacts VariosHechos4
	(Persona
		(Nombre Alberto)
		(Edad 60)
		(NombreConyuge Miriam)
		(PosicionEconomica Desahogada)
		(Salario 10400)))

(deffacts VariosHechos5
	(Persona
		(Nombre Paco)
		(Edad 60)
		(NombreConyuge Maria)
		(PosicionEconomica Dificultad)
		(Salario 1000)))


(deffacts VariosHechos6
	(Persona
		(Nombre Manolo)
		(Edad 80)
		(NombreConyuge Josefina)
		(PosicionEconomica Desahogada)
		(Salario 10060)))

;REGLAS

;APARTADO A

(defrule PersonaEdad
	(Persona
  		(Nombre ?Nombre)
		(Edad 60))
		=>
		(printout t ?Nombre " tiene 60 años" crlf ))


;APARTADO B

(defrule PersonaEdadSalario
	(Persona
  		(Nombre ?Nombre)
		(Edad 40)
		(Salario ?Salario))
		=>
		(printout t ?Nombre " tiene 40 años y un salario de " ?Salario crlf ))


;APARTADO C

(defrule PersonaDatos
	(Persona
  		(Nombre ?Nombre)
		(Edad ?Edad)
		(NombreConyuge ?NombreConyuge)
		(PosicionEconomica ?PosicionEconomica)
		(Salario ?Salario))
		=>
		(printout t ?Nombre " tiene " ?Edad ", esta casado con " ?NombreConyuge " con una posicion economica " ?PosicionEconomica " y salario de " ?Salario  crlf ))


;APARTADO D

(defrule PersonaEconomia
	(Persona
  		(Nombre ?Nombre)
		(NombreConyuge ?NombreConyuge)
		(PosicionEconomica Desahogada))
		=>
		(printout t ?Nombre " está casado con " ?NombreConyuge " y tiene una posicion economica desahogada " crlf ))


;APARTADO E

(defrule PersonaConyuge
	(Persona
  		(Nombre ?Nombre)
		(NombreConyuge ?NombreConyuge)
		(PosicionEconomica Desahogada))
		=>
		(assert(DatosFiscales ?Nombre ConyugeDesahogado)))


;APARTADO F

(defrule BorrarDatos
    (Persona
        (Nombre ?Nombre)
        (PosicionEconomica Desahogada))
    ?PE <- (Persona (PosicionEconomica Desahogada))
    =>
    (retract ?PE)
  (printout t ?Nombre " ha sido eliminado" crlf))


;APARTADO G

(defrule BorrarDatos2
    (Persona
        (Nombre ?Nombre)
(PosicionEconomica Desahogada))
    ?PE <- (Persona (PosicionEconomica Desahogada))
    =>
    (retract ?PE)
    (printout t ?Nombre " eliminado" crlf))


