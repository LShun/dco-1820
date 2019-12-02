; Accept digit (from 1-9), display serires from 1 to that digit

.MODEL SMALL
.STACK 100
.DATA
   p1 DB "Enter a digit: $"
   NL DB 13, 10, "$"
   d1 DB ?
   CHAR DB "1" 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH, 09H
    LEA DX, p1
    INT 21H
    
    MOV AH, 01H
    INT 21H
    
    SUB AL, "0"
    MOV d1, AL
    
    CALL NEWLINE
    
    MOV CL, d1
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