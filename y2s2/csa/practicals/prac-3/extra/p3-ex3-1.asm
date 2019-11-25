; Add num1 and num2 together, then display total

.MODEL SMALL
.STACK 100
.DATA
   num1 DB 3
   num2 DB 5
   total DB "The total is $" 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Print title
    MOV AH, 09H
    LEA DX, total
    INT 21H
    
    MOV AH, 02H
    MOV DL, num1
    ADD DL, num2
    ADD DL, "0"
    INT 21H
    
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN