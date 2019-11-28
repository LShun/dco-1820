; Multi-digit display

.MODEL SMALL
.STACK 100
.DATA
    NUM DB 25
    TEN DB 10
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; 25/10 -> AL = 2, AH = 5
    MOV AL, NUM
    MOV AH, 0
    DIV TEN
    
    MOV BX, AX
    
    MOV AH, 02H
    MOV DL, BL
    ADD DL, "0"
    INT 21H
    MOV DL, BH
    ADD DL, "0"
    INT 21H
    
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN