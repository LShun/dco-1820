; 3-ex1.asm
; compare & disp largest num between 5 & 9

.MODEL SMALL
.STACK 100
.DATA
    D1    DB 5
    D2    DB 9
    TXT   DB "The largest is $"  
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH, 9
    LEA DX, TXT
    INT 21H
    
    ; IF (D1 < D2)
    MOV AL, D1
    CMP AL, D2
    JL SECOND
    
    MOV DL, D1
    JMP FINISH
    
    SECOND:
        MOV DL, D2
        
    FINISH:
        ADD DL, "0"
        MOV AH, 02H
        INT 21H
        
        MOV AX, 4C00H
        INT 21H
MAIN ENDP
END MAIN