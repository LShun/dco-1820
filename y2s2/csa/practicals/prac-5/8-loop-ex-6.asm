; Display "9" to "1", jump 1 numbers every time.

.MODEL SMALL
.STACK 100
.DATA
   CHAR DB "9" 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV CX, 5
    L1:
        MOV AH, 02H
        MOV DL, CHAR
        INT 21H
        DEC CHAR
        DEC CHAR
    LOOP L1
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN