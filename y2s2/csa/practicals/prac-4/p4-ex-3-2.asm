; Ex 2, allow user to enter 2 digit, diplay product, sum, and diff
; Note: prod must less than 10

.MODEL SMALL
.STACK 100
.DATA
    txt1 DB "Enter 1st digit: $"
    txt2 DB "Enter 2nd digit: $"
    prod DB "Product is $"
    sum DB "Sum is $"
    diff DB "Difference is $"
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
    
    CALL NEWLINE
    
    ; Accept input
    MOV AH, 09H
    LEA DX, txt2
    INT 21H
    
    MOV AH, 01H
    INT 21H
    
    ; Store in BH
    SUB AL, "0"
    MOV BH, AL
    
    ; Multiply
    MOV AL, BL
    MUL BH
    
    MOV BL, AL
    
    ; Display
    
    CALL NEWLINE
    
    ; Label
    MOV AH, 09H
    LEA DX, prod
    INT 21H
    
    ; Figure
    
    MOV DL, BL
    ADD DL, "0"
    MOV AH, 02H
    INT 21H
    
    CALL NEWLINE  
    
    ; Sum
    
    
    ; Label
    MOV AH, 09H
    LEA DX, sum
    INT 21H
    
    MOV DL, BL
    ADD DL, BH
    
    MOV AH, 02H
    ADD DL, "0"
    INT 21H
    
    CALL NEWLINE 
    
    ; Difference
    
    ; Label
    MOV AH, 09H
    LEA DX, diff
    INT 21H
    
    MOV DL, BL
    SUB DL, BH

    MOV AH, 02H
    ADD DL, "0"
    INT 21H
    
    CALL NEWLINE 
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP

NEWLINE PROC
   ; Newline
    MOV AH, 09H
    LEA DX, NL
    INT 21H
    RET
NEWLINE ENDP

END MAIN