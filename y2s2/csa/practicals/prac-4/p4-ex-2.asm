; Ex 2, allow user to enter 1-3, output the square

.MODEL SMALL
.STACK 100
.DATA
    txt DB "Enter a digit: $"
    val DB 2
    NL  DB 13, 10, "$"
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH, 09H
    LEA DX, txt
    INT 21H
    
    ; Accept input
    MOV AH, 01H
    INT 21H
    
    ; Multiply
    SUB AL, "0"
    MUL AL
    
    MOV BL, AL
    
    ; Display
    ; Newline
    MOV AH, 09H
    LEA DX, NL
    INT 21H
    
    ADD BL, "0"
    MOV DL, BL
    MOV AH, 02H
    INT 21H
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN