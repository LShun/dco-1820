; Display from 17-21

.MODEL SMALL
.STACK 100
.DATA
    num DB 17
    TEN DB 10
    n1 DB ?
    n2 DB ? 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV CX, 5
    DISP:
        MOV AL, num
        MOV AH, 0
        
        DIV TEN
        
        MOV n1, AL
        MOV n2, AH
        
        MOV AH, 02H
        MOV DL, n1
        ADD DL, "0"
        INT 21H
        
        MOV AH, 02H
        MOV DL, n2
        ADD DL, "0"
        INT 21H
        INC num 
        LOOP DISP
        
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP

END MAIN