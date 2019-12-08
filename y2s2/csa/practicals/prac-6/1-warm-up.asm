; Write prog to print : AaBb...Gg

.MODEL SMALL
.STACK 100
.DATA
   CHA1 DB "A"
   CHA2 DB "a" 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV CX, 7
    PRINT:
        MOV AH, 02H
        MOV DL, CHA1
        INT 21H
        MOV DL, CHA2
        INT 21H
        INC CHA1
        INC CHA2
        LOOP PRINT
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN