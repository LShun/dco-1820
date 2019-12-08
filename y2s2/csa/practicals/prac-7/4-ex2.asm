; 4-ex2.asm
; ask user for 1/0, display 0/1 (inverse)

.MODEL SMALL
.STACK 100
.DATA
    BIT   DB ?
    TXT   DB "Enter a bit: $"
    NL    DB 13, 10, "$"  
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH, 9
    LEA DX, TXT
    INT 21H
    
    MOV AH, 1
    INT 21H
    MOV BIT, AL
    
    MOV AH, 9
    LEA DX, NL
    INT 21H
    
    
    
    ; IF (BIT == 0)
    CMP BIT, "0"
    JE ZERO
    
    MOV DL, "0"
    JMP FINISH
    
    ZERO:
        MOV DL, "1"
        
    FINISH:
        MOV AH, 02H
        INT 21H
        
        MOV AX, 4C00H
        INT 21H
MAIN ENDP
END MAIN