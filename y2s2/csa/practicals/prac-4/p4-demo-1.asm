.MODEL SMALL
.STACK 100
.DATA
    NUM1 DB 3
    NUM2 DB 2
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; 6 = 3* 2
    ; AX = AL * NUL2
    
    MOV AL, NUM1
    MUL NUM2

    MOV BX, AX ; Move to protect data, because AX change a lot.
    
    MOV AH, 02H
    MOV DX, BX
    ADD DX, "0"
    INT 21H
    
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN