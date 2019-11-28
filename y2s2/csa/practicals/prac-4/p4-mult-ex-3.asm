; result = input(0-9) * input(0-9)
; display 2 digits

.MODEL SMALL
.STACK 100
.DATA
    txt DB "Please enter 1st digit: $"
    txt2 DB "Please enter 2nd digit: $"
    txtt DB "Total = $"
    NL DB 13, 10, "$"
    TEN DB 10
    TWO DB 2
    usr DB ?
    usr2 DB ?
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Input
    MOV AH, 09H
    LEA DX, txt
    INT 21H
    
    MOV AH, 01H
    INT 21H
    
    SUB AL, "0"
    MOV usr, AL
    
    MOV AH, 09H
    LEA DX, NL
    INT 21H
    
    ; Input 2
    MOV AH, 09H
    LEA DX, txt2
    INT 21H
    
    MOV AH, 01H
    INT 21H
    
    SUB AL, "0"
    MOV usr2, AL
    
    MOV AH, 09H
    LEA DX, NL
    INT 21H
    
    
    ; Label
    MOV AH, 09H
    LEA DX, txtt
    INT 21H
    
    ; Operations
    MOV AL, usr
    MUL usr2

    ; Display
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