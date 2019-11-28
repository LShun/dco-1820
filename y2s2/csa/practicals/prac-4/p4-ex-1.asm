; Ex 1: Output result = val * val * val
; Use val DB 2

.MODEL SMALL
.STACK 100
.DATA
    val DB 2
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Put the rest of your code here
    MOV AL, val
    MUL val
    MUL val
    
    MOV DL, AL
    MOV AH, 02H
    ADD DL, "0"
    INT 21H
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN