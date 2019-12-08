; 8-t8q9.asm
; display a right angled triangle, with 1-6

.MODEL SMALL
.STACK 100
.DATA
    CHAR DB '1'
    NL DB 10, 13, "$"

.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; display rows
    MOV CX, 3
    OL:
        MOV BX, CX
    
        ; display cols
        
        MOV CX, BX
        L1:
            MOV AH, 02H
            MOV DL, CHAR
            INT 21H
            
            INC CHAR
        LOOP L1
        
        MOV AH, 09h
        LEA DX, nl
        INT 21h
        
        MOV CX, BX
        LOOP OL
        
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN