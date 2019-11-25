.MODEL SMALL
.STACK 100
.DATA
    NUM1 DB 4
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Warmup Ex 1-1, num1 + num1
    MOV AH, 02H
    MOV DL, NUM1
    ADD DL, DL
    ADD DL, '0'
    INT 21H
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN