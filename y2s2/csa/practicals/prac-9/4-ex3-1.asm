; 4-ex3-1.asm
; Allow user input string, display all 'o'
; in string

.MODEL SMALL
.STACK 100
.DATA
    PROMPT DB 'ENTER A STRING: $'
    ANSWER DB 'o inside: $'
    NL     DB 13, 10, '$'
    STR    LABEL BYTE
        MAXN DB 20
        ACTN DB ?
        ACTSTR DB 20 DUP("$")
    CMPC   DB 'o' 
    
    
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
        
        ; DISPLAY IF 'o'
        CMP DL, CMPC
        JNE END
        INT 21H
        
        END:
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