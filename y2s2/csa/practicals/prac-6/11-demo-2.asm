; 11-demo-2
; array demo (direct & indir method)

.MODEL SMALL
.STACK 100
.DATA
    
    LIST DB 7,2,4,6
    NL DB 10, 13, "$"
    

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    ; DIRECT OFFSET
    MOV SI, 0 ; SI/DI/BX TO CHOOSE
    
    MOV CX, 4
    L1:
        MOV AH, 02H
        MOV DL, LIST[SI]
        ADD DL, '0'
        INT 21H
        INC SI
    LOOP L1
    
    ; INDIRECT OFFSET
    LEA SI, LIST ; SI/DI/BX TO CHOOSE
    
    MOV CX, 4
    L2:
        MOV AH, 02H
        MOV DL, [SI]
        ADD DL, '0'
        INT 21H
        INC SI
    LOOP L2
    
        
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN