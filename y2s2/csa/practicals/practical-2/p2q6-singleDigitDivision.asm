; p2q6-singleDigitDivision.asm
; Calc and displays the quotient and remainder of 1-digit div
                     
.MODEL SMALL
.STACK 100
.DATA
    dividTxt DB "Dividend: $"
    divisTxt DB "Divisor: $"
    quoTxt   DB "Quotient: $"
    remTxt   DB "Remainder: $"
    dividend DB 8
    divisor  DB 5
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    ; print dividend
    MOV AH, 09H
    LEA DX, dividTxt
    INT 21H
    
    
    MOV AH, 02H
    MOV DX, dividend
    ADD DX, "0"
    INT 21H
    
    CALL newline
    
    ; print divisor
    MOV AH, 09H
    LEA DX, divisTxt
    INT 21H
    
    MOV AH, 02H
    MOV DX, divisor
    ADD DX, "0"
    INT 21H
    
    CALL newline
   
    ; calculate quotient and remainder
    MOV AL, dividend
    MOV AH, 0
    MOV BL, divisor
    DIV BL
    
    MOV BL, AL
    MOV BH, AH
    
    ; print quotient
    MOV AH, 09H
    LEA DX, quoTxt
    INT 21H
     
    MOV AH, 02H
    MOV DX, BL
    ADD DX, "0"
    INT 21H
    
    CALL newline
    
    ; print remainder
    MOV AH, 09H
    LEA DX, remTxt
    INT 21H
      
    MOV AH, 02H
    MOV DX, BH
    ADD DX, "0"
    INT 21H
    
    MOV AX, 4C00H
    INT 21H
    
    CALL newline

MAIN ENDP


newline PROC
    MOV AH, 02H
    MOV DL, 0DH
    INT 21H
    MOV DL, 0AH
    INT 21H
    RET
newline ENDP

END MAIN