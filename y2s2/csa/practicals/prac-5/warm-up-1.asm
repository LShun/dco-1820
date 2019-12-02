; Write program, acepts digit, multiply itself, display result

.MODEL SMALL
.STACK 100
.DATA
    pr DB "Enter a digit: $"
    dig DB ?
    num1 DB ?
    num2 DB ?
    TEN DB 10
    NL DB 13, 10, "$"
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Accept digit
    MOV AH, 09H
    LEA DX, pr
    INT 21H
    
    MOV AH, 01H
    INT 21H
    
    ; Multiply
    SUB AL, "0"
    MUL AL
    
    MOV dig, AL
    
    ; Output it
    
    ; Divide first
    DIV TEN
    
    MOV num1, AL
    MOV num2, AH
    
    ADD num1, "0"
    ADD num2, "0"
    
    ; Display both digits
    MOV AH, 09H
    LEA DX, NL
    INT 21H
    
    MOV AH, 02H
    MOV DL, num1
    INT 21H
    MOV DL, num2
    INT 21H
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN