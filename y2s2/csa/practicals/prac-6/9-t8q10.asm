; 10-t8q11.asm
; display a right angled triangle, with 1-5,
; with less numbers down the line

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
    MOV CX, 5
    OL:
        MOV BX, CX
    
        ; display cols
        
        MOV CX, BX
        L1:
            MOV AH, 02H
            MOV DL, CHAR
            INT 21H
            
            ; increase num
            INC CHAR
        LOOP L1
        
        MOV AH, 09h
        LEA DX, nl
        INT 21h
        
        MOV CX, BX
        
        MOV CHAR, "1"
        LOOP OL
        
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN