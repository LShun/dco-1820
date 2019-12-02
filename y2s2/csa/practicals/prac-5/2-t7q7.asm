; Prompt & accept 2 ODD integers, display comma automatically.
; Calculate average number (num1+num2)/2 
; Display with 1 d.p. (Note: this one can just print cause 
; divide 2 odd numbers always even)

.MODEL SMALL
.STACK 100
.DATA
   prompt1 DB "Enter TWO odd integers values (0 to 9): $"
   comma   DB ","
   prompt2 DB 13,10,"The average of the input values is: $"
   val1    DB ?
   val2    DB ?
   avg     DB ?
   pzero   DB ".0$"
   TWO     DB 2 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; ask for input
    MOV AH, 09H
    LEA DX, prompt1
    INT 21H
    
    MOV AH, 01H
    INT 21H
    
    SUB AL, "0"
    MOV val1, AL
    
    MOV AH, 02H
    MOV DL, comma
    INT 21H
    
    MOV AH, 01H
    INT 21H
    
    SUB AL, "0"
    MOV val2, AL
    
    ; divide
    MOV BL, val1
    ADD BL, val2
    
    MOV AL, BL
    MOV AH, 0
    DIV TWO
    
    MOV avg, AL
    
    ; output
    MOV AH, 09H
    LEA DX, prompt2
    INT 21H
    
    MOV AH, 02H
    MOV DL, avg
    ADD DL, "0"
    INT 21H
    
    MOV AH, 09H
    LEA DX, pzero
    INT 21H
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN