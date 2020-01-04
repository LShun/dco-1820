; 2-ex2-1.asm
; Require user to key in string of char,
; display third char

.MODEL SMALL
.STACK 100
.DATA
    PROMPT DB 'ENTER A WORD: $'
    ANSWER DB 'THE 3RD CHARACTER IS: $'
    NL     DB 13, 10, '$'
    STR    LABEL BYTE
        MAXN DB 20
        ACTN DB ?
        ACTSTR DB 20 DUP("$") 
    
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Prompt user to enter char
    MOV AH, 09H
    LEA DX, PROMPT
    INT 21H
    
    ; Accept char
    MOV AH, 0AH
    LEA DX, STR
    INT 21H
    
    CALL NEWL
    
    ; Display prompt then 3rd char
    MOV AH, 09H
    LEA DX, ANSWER
    INT 21H
    
    MOV AH, 02H
    MOV DL, ACTSTR[2]
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