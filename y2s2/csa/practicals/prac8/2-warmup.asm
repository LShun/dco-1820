;2-warmup.asm
; User enter (P,R,Y,W) 
; Display Pink/Red/Yellow/White depending
; on usr

.MODEL SMALL
.STACK 100
.DATA
    opText DB 'Enter a code: $'
    nl DB 13,10,'$'
    op DB ?
    
    cp DB "Pink$"
    cr DB "Red$"
    cy DB "Yellow$"
    cw DB "White$"
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; ask for operator
    MOV AH, 09h
    LEA DX, opText
    INT 21h
    
    MOV AH, 01h
    INT 21h
    
    MOV op, AL
    
    CALL newline
    
    CMP op, 'W'
    JE WHITE
    
    CMP op, 'P'
    JE PINK
    
    CMP op, 'R'
    JE RED
    
    CMP op, 'Y'
    JE YELLOW
    
    WHITE: LEA DX, cw
           JMP fin
    
    PINK:  LEA DX, cp
           JMP fin
    
    RED:   LEA DX, cr
           JMP fin
           
    YELLOW:LEA DX, cy
        
    FIN:
        MOV AH, 09h
        INT 21H
        
        MOV AX,4C00H
        INT 21H  
    
    
    
MAIN ENDP

newline PROC
    MOV AH, 09h
    LEA DX, nl
    INT 21h
    RET
newline ENDP
END MAIN