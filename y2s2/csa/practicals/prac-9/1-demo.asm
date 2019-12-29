; 1-demo.asm
; copy a string into an array and display it

.MODEL SMALL
.STACK 100
.DATA
    PROMPT DB "ENTER A FRUIT: $"
    STR LABEL BYTE
        MAXN DB 20
        ACTN DB ?
        ACTSTR DB 20 DUP("$")
    NL DB 13, 10, '$'
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH, 09H
    LEA DX, PROMPT
    INT 21H
    
    MOV AH, 0AH
    LEA DX, STR
    INT 21H
    
    CALL NEWL
    
    MOV AH, 09H
    LEA DX, ACTSTR
    INT 21H
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP

NEWL PROC
    MOV AH, 09H
    LEA DX, NL
    INT 21H
    RET
NEWL ENDP
END MAIN