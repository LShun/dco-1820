; 13-ex-1-2.asm
; display element in LISTA using loop, in all
; lowercase.

.MODEL SMALL
.STACK 100
.DATA
    
    LISTA DB "TRAVEL"
    

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    ; DIRECT OFFSET
    MOV SI, 0 ; SI/DI/BX TO CHOOSE
    
    MOV CX, 6
    L1:
        MOV AH, 02H
        MOV DL, LISTA[SI]
        ADD DL, 32
        INT 21H
        INC SI
    LOOP L1
    
    ; INDIRECT OFFSET
    LEA SI, LISTA ; SI/DI/BX TO CHOOSE
    
    MOV CX, 6
    L2:
        MOV AH, 02H
        MOV DL, [SI]
        ADD DL, 32
        INT 21H
        INC SI
    LOOP L2
    
        
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN