; 6-ex3-1.asm
; display X for 6 times

.MODEL SMALL
.STACK 100
.DATA
    CHAR DB 'X'
    NL DB 10, 13, "$"
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV CX, 6
    L1:
        MOV AH, 02H
        MOV DL, CHAR
        INT 21H
    LOOP L1
        
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN