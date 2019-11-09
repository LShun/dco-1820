.MODEL SMALL
.STACK 100
.DATA
    UPPER DB 'A'
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH, 02H
    MOV DL, UPPER
    INT 21H
    
    MOV DL, ','
    INT 21H
    
    MOV DL, UPPER
    ADD DL, 20H
    INT 21H
    
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN