.MODEL SMALL

.CODE  

	org 100h 
	
Programa_Int:   

;DECLARAMOS VARIABLES:

	JMP Reside
	RELOJ dB '00:00'
	CONTADOR DB 0  
	

Rutina_Servicio PROC
	
	CLI;no permitimos las interupciones
	    
    INC CONTADOR ;PRIMERO LO INCREMENTO 

	CMP CONTADOR,18 ;compara si el contador vale 18
	     
    JE VALE18 ;si vale 18 salta al conjunto de instrucciones con etiqueta VALE18
    JMP FIN ; si no vale 18 salta al conjunto de instrucciones con etiqueta FIN
     
    VALE18: 
    
    MOV CONTADOR,0   
    MOV AX,0B800h
    MOV ES,AX
    MOV  AH,00001111b
    MOV SI,0
    MOV DI,148
    
    
    RELOJ2: 
    
    MOV AL,RELOJ[SI]
    MOV ES:[DI],AX
    ADD DI,2
    ADD SI,1 
    CMP SI,4
    JBE RELOJ2   ;salta si es igual
     

     

;Controlamos el reloj:

    CMP RELOJ[4],'9'
    JNE PRINCIPIO 

	MOV RELOJ[4],'0'
    INC RELOJ[3]
	

     
     	
    CMP RELOJ[3],'6'
        JNE FIN
	    
	MOV RELOJ[3],'0'
	INC RELOJ[1]
	
      
	CMP RELOJ[1],'9'
	JNE FIN
      	
    MOV RELOJ[1],'0' 
    
	INC RELOJ[0]
	
	 
	PRINCIPIO: 

	INC RELOJ[4]
         
    FIN:
         
    STI        ;Volvemos a activar las interupciones
    IRET       ;Recupera el valor de los registros implicados en la rutina
    ENDP
      
        
                     


Reside: ;Etiqueta para determinar la direccion siguiente a la ultima de la rutina que debe quedar residente
        
	MOV DX, offset Rutina_Servicio ;Empezamos rutina de atencion a interupcion 
	MOV AX, 0
	MOV ES, AX
	MOV SI, 1Ch*4 ;Desplazamiento
	CLI;Desactivamos interupciones
	MOV ES:[SI], DX;Nos dirigimos a la primera direccion( la que va a buscar cpu cd se produzca 1ch)
	MOV ES:[SI+2], CS;Son dos porque empezo en 1ch*4 y se guarda el desplazamiento ahi y en la 1ch*4+1
	                 ; y las dos siguientes la direccion base
	STI;Volvemos a activar las interrupciones
	MOV DX, offset Reside;Paso a DX la direccion siguiente a la ultima que tengo residente
	INT 27h;Devuelve el control al sistema operativo dejando el programa residente  
	
END Programa_Int