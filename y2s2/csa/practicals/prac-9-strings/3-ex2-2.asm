; 3-ex2-2.asm
; Modify previous prog to display word with
; looping.

.MODEL SMALL
.STACK 100
.DATA
    PROMPT DB 'ENTER A WORD: $'
    ANSWER DB 'THE CHARACTERS ARE: $'
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
    
    ; Display prompt then string
    MOV AH, 09H
    LEA DX, ANSWER
    INT 21H
    
    MOV CH, 0
    MOV CL, ACTN
    MOV SI, 0
    DISPL:
        MOV AH, 02H
        MOV DL, ACTSTR[SI]
        INT 21H
        INC SI
        LOOP DISPL
        
    
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