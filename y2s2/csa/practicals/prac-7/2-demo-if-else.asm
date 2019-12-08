; 1-warmup.asm
; ask user to enter 3 characters, store in 
; an array, and display with MOV AH, 09H

.MODEL SMALL
.STACK 100
.DATA
    STRP    DB "PASS$"
    STRF    DB "FAIL$"
    SCORE   DB 7   
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; IF (SCORE >= 5)
    CMP SCORE, 5
    JL FAIL
    
    MOV AH, 9
    LEA DX, STRP
    INT 21H
    JMP FINISH
    
    FAIL:
        MOV AH, 9
        LEA DX, STRF
        INT 21H
        
    FINISH:
        MOV AX, 4C00H
        INT 21H
MAIN ENDP
END MAIN