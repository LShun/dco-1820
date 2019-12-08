; 14-ex-1-3.asm
; display element in LISTA using loop, in all
; lowercase, in reverse order.

.MODEL SMALL
.STACK 100
.DATA
    
    LISTA DB "TRAVEL"
    

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    ; DIRECT OFFSET
    MOV SI, 5 ; SI/DI/BX TO CHOOSE
    
    MOV CX, 6
    L1:
        MOV AH, 02H
        MOV DL, LISTA[SI]
        ADD DL, 32
        INT 21H
        DEC SI
    LOOP L1
    
    ; INDIRECT OFFSET
    LEA SI, LISTA+5 ; SI/DI/BX TO CHOOSE
    
    MOV CX, 6
    L2:
        MOV AH, 02H
        MOV DL, [SI]
        ADD DL, 32
        INT 21H
        DEC SI
    LOOP L2
    
        
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN