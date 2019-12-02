; Display from 17-21

.MODEL SMALL
.STACK 100
.DATA
    in1 DB "Enter a digit: $"
    NL DB 13,10, "$"
    total DB 0
    num1 DB ?
    num2 DB ?
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV CX, 4
    INPUT:
        MOV AH, 09H
        LEA DX, in1
        INT 21H
        
        MOV AH, 01H
        INT 21H
        
        SUB AL, "0"
        ADD total, AL
        
        CALL NEWLINE
        LOOP INPUT
    
        
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP

NEWLINE PROC
    MOV AH, 09H
    LEA DX, NL
    INT 21H 
END MAIN