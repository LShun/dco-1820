; 2-demo.asm
; display 4 rows of '@@@'

.MODEL SMALL
.STACK 100
.DATA
    CHAR DB '@'
    NL DB 10, 13, "$" 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV CX, 4
    L1:
        MOV BX, CX
        ; Display 3 @@@
        
        MOV CX, 3
        L2:
            MOV AH, 02H
            MOV DL, CHAR
            INT 21H
        be LOOP L2
            
        MOV CX, BX
        
        
        MOV AH, 09H
        LEA DX, NL
        INT 21H
    LOOP L1
        
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN