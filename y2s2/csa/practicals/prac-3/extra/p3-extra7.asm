.MODEL SMALL
.STACK 100
.DATA
    CHAR DB ? 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Input
    MOV AH, 01H
    INT 21H
    
    MOV CHAR, AL
    
    ; Display
    MOV AH, 02H
    MOV DL, CHAR
    INT 21H
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN