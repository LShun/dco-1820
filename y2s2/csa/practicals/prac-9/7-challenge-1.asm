; 7-challenge-1.asm
; Allow user enter 8-bit binary
; Flip binary data accepted
; Display one's complement

.MODEL SMALL
.STACK 100
.DATA
    INPROMPT       DB 'ENTER 8-BIT BINARY DATA >> $'
    OCOMPROMPT     DB "1'S COMPLEMENT VALUE    >> $"
    NL     DB 13, 10, '$'
    STR    LABEL BYTE
        MAXN DB 20
        ACTN DB ?
        ACTSTR DB 20 DUP("$")
    OFF   DB '0'
    ON    DB '1' 
    
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Prompt user to enter char
    MOV AH, 09H
    LEA DX, INPROMPT
    INT 21H
    
    ; Accept chars
    MOV AH, 0AH
    LEA DX, STR
    INT 21H
    
    CALL NEWL
    
    ; Display result
    MOV AH, 09H
    LEA DX, OCOMPROMPT
    INT 21H
    
    MOV CH, 0
    MOV CL, ACTN
    MOV SI, 0
    DISPL:
        MOV AH, 02H
        MOV DL, ACTSTR[SI]
        
        ; Check if between 1 OR 0
        CMP DL, OFF
        JNE NOFF
        MOV DL, ON
        JMP END
        
        NOFF:
           MOV DL, OFF
        
        
        END:
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