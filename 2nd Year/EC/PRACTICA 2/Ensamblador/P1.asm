.MODEL SMALL
.data 
      
CADENA   DB 5,0,0,0,0,0,0 ; (nummax+1)+num real caracteres tecleados+4 bits +cR 

PESO     DB 8,4,2,1             ;con db reservamos posiciones tipo byte

VALOR_B  DB 0    

VALOR_C1 DB 0    

SIGNO_C1 DB '+'





.code 
  
    
  MOV AX,SEG CADENA     ;inicializo el segmento de datos
  MOV DS,AX  
   
  MOV DX,OFFSET CADENA    ;indica la posicion de memoria a partir de la que se almacenara la cadena  
  MOV AH,0Ah               ;lee por teclado hasta pulsar intro 
  INT 21h
           
  
  SUB CADENA[2],48
  SUB CADENA[3],48   ;cambiamos caracter ascii por los numeros 48 es el codigo ascii del 0
  SUB CADENA[4],48
  SUB CADENA[5],48
     
  
  MOV AH,48              ;calculamos el valor decimal
  
  MOV AL,CADENA[2]
  MUL PESO[0]
  MOV BX,AX
  
  MOV AL,CADENA[3]
  MUL PESO[1]
  ADD BX,AX
  
  MOV AL,CADENA[4]
  MUL PESO[2]
  ADD BX,AX  
  
  MOV AL,CADENA[5]
  MUL PESO[3]
  ADD BX,AX  
  
  MOV VALOR_B,BL
  
  
  CMP CADENA[2],1  ;Calculamos el c1 pero vemos primero si es positivo o no con el cmp
  JE  ESNEG    ;je:salto si es equal
  JMP FINALIZA ;si no es neg finalizo 
  
  ESNEG:   ;si es negativo tengo que invertirlo 
  
  MOV AL,CADENA[3]
  NOT AL 
  AND AL,00000001b  
  MOV CADENA[3],AL  
  
  MOV AL,CADENA[4]
  NOT AL 
  AND AL,00000001b
  MOV CADENA[4],AL
  
  MOV AL,CADENA[5]
  NOT AL
  AND AL,00000001b
  MOV CADENA[5],AL 
  
  MOV SIGNO_C1,'-'  
  
  FINALIZA:
  
  MOV BX,0
  MOV AH,48
  MOV AL,CADENA[3]
  MUL PESO[1]
  ADD BX,AX
  
  MOV AH,48
  MOV AL,CADENA[4]
  MUL PESO[2]  
  ADD BX,AX
  
  MOV AH,48
  MOV AL,CADENA[5]
  MUL PESO[3]
  ADD BX,AX
  
  MOV VALOR_C1,BL 
  
   ; Mostramos por pantalla 
    ;Mover el segmento a la memoria de video
    MOV AX, 0B800h
    MOV ES, AX
    
    ;Fondo negro y letras rojas
    MOV AH, 00001100b
    
    ;Mostrar binario natural
    MOV AL, 'B'
    MOV ES:[160], AX     ;160 PRIMERA FILA 320 SEGUNDA...
    MOV AL, 'I'
    MOV ES:[162], AX
    MOV AL, 'N'
    MOV ES:[164], AX
    MOV AL, 'A'
    MOV ES:[166], AX     
    MOV AL, 'R'
    MOV ES:[168], AX     
    MOV AL, 'I'
    MOV ES:[170], AX  
    MOV AL, 'O'
    MOV ES:[172], AX 
    MOV AL, ':'
    MOV ES:[174], AX 

   
  
    ;Poner los digitos
    MOV AH, 0           ;PONGO AH A 0 Y METO EL VALOR 
                         ; EN BINARIO 
    MOV AL, VALOR_B
    MOV BL, 10d
    DIV BL
    ADD AL, 30h
    MOV ES:[176], AL      ;PRIMER DIGITO 
    ADD AH, 30h
    MOV ES:[178], AH     ;MUETSRA SEGUNDO DIGITO 
    
    ;Mostrar complemento a 1
    MOV AH, 110b
    MOV AL, 'C'
    MOV ES:[320], AX
    MOV AL, '1'
    MOV ES:[322], AX
    MOV AL, ':'
    MOV ES:[324], AX
    MOV AL, SIGNO_C1
    MOV ES:[328], AX
    MOV AL, VALOR_C1
    ADD AL, 30h
    MOV ES:[330], AX
    
    
                           
    ;Devolver el control al OS    
    MOV AX, 4C00h
    INT 21h  

 END