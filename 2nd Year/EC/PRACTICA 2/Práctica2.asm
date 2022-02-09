.MODEL SMALL

.CODE
    
        .org 100h   

Programa_Int:

    JMP Reside ;Salto incondicional a la posicion de memoria que tenga asociada el nombre Reside
    ;;;;;Declaracion de variables
    
Rutina_Servicio PROC
    
    CLI
    ;Salvar el contenido de los registros implicados en la rutina
    ;.......
    ;.......
    ;.......
    ;Recupera el valor de los registros implicados en la rutina
    STI
    IRET
    
ENDP

Reside: ;Etiqueta para determinar la direccion siguiente a la ultima de la rutina que debe quedar residente

    MOV DX,OFFSET Rutina_Servicio
    MOV AX,0
    MOV ES,AX   
    MOV SI, Codigo_Int*4
    CLI
    MOV ES:[SI],DX
    MOV ES:[SI+2],CS
    STI
    MOV DX, OFFSET Reside
    INT 24h
    
END Programa_Int    
    
            
        
        