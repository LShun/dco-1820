; 5-ex1-3.asm
; display 3 rows of alphabet, each 4 alphabet, from A-D

.MODEL SMALL
.STACK 100
.DATA
    CHAR DB 'A'
    NL DB 10, 13, "$" 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV CX, 3
    L1:
        MOV BX, CX
        ; Display 3 @@@
        
        MOV CX, 4
        L2:
            MOV AH, 02H
            MOV DL, CHAR
            INT 21H
            INC CHAR
        LOOP L2
            
        MOV CX, BX
        
        MOV AH, 09H
        LEA DX, NL
        INT 21H
        
        MOV CHAR, 'A'
    LOOP L1
        
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN