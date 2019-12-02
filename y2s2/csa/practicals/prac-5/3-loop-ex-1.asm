; Display "A" for 26 times.

.MODEL SMALL
.STACK 100
.DATA
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV CX, 26
    L1:
        MOV AH, 02H
        MOV DL, "A"
        INT 21H
    LOOP L1
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN