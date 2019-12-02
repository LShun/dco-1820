; Display 1-9 vertically

.MODEL SMALL
.STACK 100
.DATA
    NL DB 13,10, "$"
    num DB "1"
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV CX, 9
    DISP:
        MOV AH, 02H
        MOV DL, num
        INT 21H
        
        CALL NEWLINE
        
        INC num
        
        LOOP DISP
        
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP

NEWLINE PROC
    MOV AH, 09H
    LEA DX, NL
    INT 21H
    RET 
END MAIN