; result = val1 + (val2 * val3)
; display 2 digits

.MODEL SMALL
.STACK 100
.DATA
    val1 DB 7
    val2 DB 9
    val3 DB 4
    result DB ?
    TEN DB 10
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Operations
    MOV AL, val2
    MUL val3
    ADD AL, val1
    MOV result, AL
    
    
    ; Display
    MOV AL, result
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