.MODEL SMALL
.STACK 100
.DATA
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV CX, 10
    L1:
        MOV AH, 02H
        MOV DL, "@"
        INT 21H
    LOOP L1
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN