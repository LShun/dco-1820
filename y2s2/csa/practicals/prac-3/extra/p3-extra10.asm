; Ask user for two digits, and add them (total cannot > 9)
; Display answer in: a + b = c
;                    a - b = d

.MODEL SMALL
.STACK 100
.DATA
    INP1 DB "Enter 1st digit: $"
    INP2 DB "Enter 2nd digit: $"
    DIG1 DB ?
    DIG2 DB ?
    NL  DB 13, 10, "$" 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Ask for input
    MOV AH, 09H
    LEA DX, INP1
    INT 21H
    
    ; Input
    MOV AH, 01H
    INT 21H
    
    SUB AL, "0"
    MOV DIG1, AL
    
    ; Newline
    MOV AH, 09H
    LEA DX, NL
    INT 21H
    
    ; Ask for input
    MOV AH, 09H
    LEA DX, INP2
    INT 21H
    
    ; Input
    MOV AH, 01H
    INT 21H
    
    SUB AL, "0"
    MOV DIG2, AL
    
    ; Newline
    MOV AH, 09H
    LEA DX, NL
    INT 21H
    
    ; Display addition total
    
    ; Display operands
    MOV AH, 02H
    MOV DL, DIG1
    ADD DL, "0"
    INT 21H
    
    MOV AH, 02H
    MOV DL, "+"
    INT 21H
    
    MOV AH, 02H
    MOV DL, DIG2
    ADD DL, "0"
    INT 21H
    
    MOV AH, 02H
    MOV DL, "="
    INT 21H
    
    ; display addition results
    MOV AH, 02H
    MOV DL, DIG1
    ADD DL, DIG2
    ADD DL, "0"
    INT 21H
    
    ; Newline
    MOV AH, 09H
    LEA DX, NL
    INT 21H
    
    ; Display operands
    MOV AH, 02H
    MOV DL, DIG1
    ADD DL, "0"
    INT 21H
    
    MOV AH, 02H
    MOV DL, "-"
    INT 21H
    
    MOV AH, 02H
    MOV DL, DIG2
    ADD DL, "0"
    INT 21H
    
    MOV AH, 02H
    MOV DL, "="
    INT 21H
    
    ; Display subtraction total
    MOV AH, 02H
    MOV DL, DIG1
    SUB DL, DIG2
    ADD DL, "0"
    INT 21H
    
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN