; Add num1 and num2 together, then display the operands & total

.MODEL SMALL
.STACK 100
.DATA
   num1 DB 3
   num2 DB 5
   plus DB " plus $"
   equals DB " equals to $"
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; print num1
    MOV AH, 02H
    MOV DL, num1
    ADD DL, "0"
    INT 21H
    
    ; Print plus
    MOV AH, 09H
    LEA DX, plus
    INT 21H
    
    ; print num2
    MOV AH, 02H
    MOV DL, num2
    ADD DL, "0"
    INT 21H
    
    ; print equals
    MOV AH, 09H
    LEA DX, equals
    INT 21H
    
    ; print final figure
    MOV AH, 02H
    MOV DL, num1
    ADD DL, num2
    ADD DL, "0"
    INT 21H
    
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN