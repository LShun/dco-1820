.MODEL SMALL
.STACK 100
.DATA                                                 
    askTxt DB "Enter TWO odd integer values (0 to 9): $"
    outTxt DB "The average of the input values is: $"
    outDec DB ".0$"
    inOne  DB ?
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Accept 2 ODD integers (display comma after first)
    MOV AH, 09H
    LEA DX, askTxt
    INT 21H
    
    MOV AH, 01H
    INT 21H
    SUB AL, "0"
    MOV inOne, AL
    
    MOV AH, 02H
    MOV DL, ','
    INT 21H
    
    MOV AH, 01H
    INT 21H
    SUB AL, "0"
    ADD inOne, AL
    
    CALL newline
    
    ; ODD + ODD Always = EVEN, thus, decimal is always 0
    
    ; Calculate average of numbers (input1 + input2 / 2)
    MOV AX, inOne
    MOV BL, 2
    DIV BL
    
    MOV inOne, AL
    ADD inOne, "0"
    
    ; display the average in 1 decimal place
    MOV AH, 09H
    LEA DX, outTxt
    INT 21H
    MOV AH, 02H
    MOV DX, inOne
    INT 21H
    MOV AH, 09H
    LEA DX, outDec
    INT 21H
    
    MOV AX,4C00H
    INT 21H
    
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