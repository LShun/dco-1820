; 5-prac5-q2.asm
; Allow user enter string, one digit, offset
; the entire string with the number

.MODEL SMALL
.STACK 100
.DATA
    PROMPT      DB 'ENTER A SECRET WORD: $'
    KEYPROMPT   DB 'ENTER ENCRYPTION KEY (1-9): $'
    RESPROMPT   DB 'RESULT WORD: $'
    NL     DB 13, 10, '$'
    STR    LABEL BYTE
        MAXN DB 20
        ACTN DB ?
        ACTSTR DB 20 DUP("$")
    KEY   DB ? 
    
    
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
    
    ; Display prompt & ask key
    MOV AH, 09H
    LEA DX, KEYPROMPT
    INT 21H
    
    MOV AH, 01H
    INT 21H
    MOV KEY, AL
    SUB KEY, '0'
    
    CALL NEWL
    
    ; Display result
    MOV AH, 09H
    LEA DX, RESPROMPT
    INT 21H
    
    MOV CH, 0
    MOV CL, ACTN
    MOV SI, 0
    DISPL:
        MOV AH, 02H
        MOV DL, ACTSTR[SI]
        
        ADD DL, KEY
        
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