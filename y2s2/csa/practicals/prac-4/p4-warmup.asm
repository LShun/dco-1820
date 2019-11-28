; Write program to subtract first with second digit, display result

.MODEL SMALL
.STACK 100
.DATA
   D1 DB ?
   D2 DB ?
   txt1 DB "Enter 1st digit: $"
   txt2 DB "Enter 2nd digit: $"
   NL DB 13, 10, "$" 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Put the rest of your code here
    ; first digit
    MOV AH, 09H
    LEA DX, txt1
    INT 21H
    
    MOV AH, 01H
    INT 21H
    
    SUB AL, "0"
    MOV D1, AL
    
    MOV AH, 09H
    LEA DX, NL
    INT 21H
    
    ; 2nd digit
    MOV AH, 09H
    LEA DX, txt2
    INT 21H
    
    MOV AH, 01H
    INT 21H
    
    SUB AL, "0"
    MOV D2, AL
    
    MOV AH, 09H
    LEA DX, NL
    INT 21H
    
    ; Subtract
    MOV BL, D1
    SUB BL, D2
    
    ; Add to ASCII
    ADD BL, "0"
    
    ; Display
    MOV AH, 02H
    MOV DL, BL
    INT 21H
    
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN