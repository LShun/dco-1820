; Ex 2, allow user to enter 2 digit, diplay product
; Note: prod must less than 10

.MODEL SMALL
.STACK 100
.DATA
    txt1 DB "Enter 1st digit: $"
    txt2 DB "Enter 2nd digit: $"
    NL  DB 13, 10, "$"
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    
    
    ; Accept input
    MOV AH, 09H
    LEA DX, txt1
    INT 21H
    
    MOV AH, 01H
    INT 21H
    
    ; Store in BL
    SUB AL, "0"
    MOV BL, AL
    
    ; Newline
    MOV AH, 09H
    LEA DX, NL
    INT 21H
    
    ; Accept input
    MOV AH, 09H
    LEA DX, txt2
    INT 21H
    
    MOV AH, 01H
    INT 21H
    
    SUB AL, "0"
    
    ; Multiply
    MUL BL
    
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