; 6-ex4.asm
; Allow user enter string
; display numbers only

.MODEL SMALL
.STACK 100
.DATA
    PROMPT      DB 'PLEASE ENTER ANY DATA >> $'
    VALPROMPT   DB 'THE NUMERICAL VALUE IS >> $'
    NL     DB 13, 10, '$'
    STR    LABEL BYTE
        MAXN DB 20
        ACTN DB ?
        ACTSTR DB 20 DUP("$")
    LOW   DB '0'
    HIGH  DB '9' 
    
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Prompt user to enter char
    MOV AH, 09H
    LEA DX, PROMPT
    INT 21H
    
    ; Accept chars
    MOV AH, 0AH
    LEA DX, STR
    INT 21H
    
    CALL NEWL
    
    ; Display result
    MOV AH, 09H
    LEA DX, VALPROMPT
    INT 21H
    
    MOV CH, 0
    MOV CL, ACTN
    MOV SI, 0
    DISPL:
        MOV AH, 02H
        MOV DL, ACTSTR[SI]
        
        ; Check if between 0 & 9
        CMP DL, LOW
        JL  END
        CMP DL, HIGH
        JG  END
        
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