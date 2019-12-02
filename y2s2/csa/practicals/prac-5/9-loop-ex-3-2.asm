; Allow user to enter 1 char, 1 num, display it num times

.MODEL SMALL
.STACK 100
.DATA
   CHAR DB ?
   COUNT DB ?
   pro DB "Enter a character: $"
   pro2 DB "Enter a number: $"
   NL DB 13,10,"$" 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH, 09H
    LEA DX, pro
    INT 21H
    
    MOV AH, 01H
    INT 21H
    
    MOV CHAR, AL
    
    MOV AH, 09H
    LEA DX, NL
    INT 21H
    
    MOV AH, 09H
    LEA DX, pro2
    INT 21H
    
    MOV AH, 01H
    INT 21H
    SUB AL, "0"
    MOV COUNT, AL
    
    MOV AH, 09H
    LEA DX, NL
    INT 21H
    
    
    MOV CL, COUNT
    MOV CH, 0
    L1:
        MOV AH, 02H
        MOV DL, CHAR
        INT 21H
    LOOP L1
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN