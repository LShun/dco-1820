; Accept digit (from 1-9), display serires from num1 to num2

.MODEL SMALL
.STACK 100
.DATA
   p1 DB "Enter 1st digit: $"
   p2 DB "Enter 2nd digit: $"
   NL DB 13, 10, "$"
   d1 DB ?
   d2 DB ?
   CHAR DB ? 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH, 09H
    LEA DX, p1
    INT 21H
    
    MOV AH, 01H
    INT 21H
    
    MOV CHAR, AL
    SUB AL, "1"
    MOV d1, AL
    
    CALL NEWLINE
    
    MOV AH, 09H
    LEA DX, p1
    INT 21H
    
    MOV AH, 01H
    INT 21H
    
    SUB AL, "0"
    MOV d2, AL
    
    CALL NEWLINE
    
    MOV CL, d2
    SUB CL, d1
    MOV CH, 0
    
    DISP:
        MOV AH, 02H
        MOV DL, CHAR
        INT 21H
        INC CHAR
    LOOP DISP
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP


NEWLINE PROC
   MOV AH, 09H
   LEA DX, NL
   INT 21H
   RET
NEWLINE ENDP
END MAIN