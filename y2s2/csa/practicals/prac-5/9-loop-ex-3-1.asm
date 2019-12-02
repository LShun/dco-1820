; Allow user to enter 1 char, display it 7 times

.MODEL SMALL
.STACK 100
.DATA
   CHAR DB ?
   pro DB "Enter a character: $"
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
    
    MOV CX, 7
    L1:
        MOV AH, 02H
        MOV DL, CHAR
        INT 21H
    LOOP L1
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN