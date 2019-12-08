; 1-warmup.asm
; ask user to enter 3 characters, store in 
; an array, and display with MOV AH, 09H

.MODEL SMALL
.STACK 100
.DATA
    TXT  DB 'ENTER 3 CHARACTERS: $'
    CHAR DB 4 DUP('$')
    NL DB 13,10,'$'    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; INPUT
    MOV AH, 9
    LEA DX, TXT
    INT 21H
    
    LEA SI, CHAR
    
    MOV CX, 3
    LIN:
        MOV AH, 01H
        INT 21H
        MOV [SI], AL
        INC SI
        LOOP LIN
        
    
    ; PROCESS
    
    
    ; OUTPUT
    MOV AH,9
    LEA DX, NL
    INT 21H 
    LEA DX, CHAR
    INT 21H
    
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN