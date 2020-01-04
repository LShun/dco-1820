; 8-challenge-2.asm
; Allow user enter 2 4-char string
; Compare if same or different

.MODEL SMALL
.STACK 100
.DATA
    INPROMPT1       DB 'Enter string1 >> $'
    INPROMPT2       DB 'Enter string2 >> $'
    SAME            DB 'SAME$'
    DIFF            DB 'DIFFERENT$'
    NL              DB 13, 10, '$'
    
    MAXCHAR         DB 4
    STR1            LABEL BYTE
                    MAXN DB MAXCHAR
                    ACTN DB ?
                    ACTSTR DB MAXCHAR DUP("$")
    STR2            LABEL BYTE
                    MAXN2   DB MAXCHAR
                    ACTN2   DB ?
                    ACTSTR2 DB 20 DUP("$")
    
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Prompt user to enter str1
    MOV AH, 09H
    LEA DX, INPROMPT1
    INT 21H
    
    ; Accept chars
    MOV AH, 0AH
    LEA DX, STR1
    INT 21H
    
    CALL NEWL
    
    ; TODO: Prompt user to enter str2
    MOV AH, 09H
    LEA DX, INPROMPT2
    INT 21H
    
    ; Accept chars
    MOV AH, 0AH
    LEA DX, STR2
    INT 21H
    
    CALL NEWL
    
    ; Display result
    
    MOV CH, 0
    MOV CL, MAXCHAR
    MOV SI, 0
    DISPL:
        MOV AH, 02H
        MOV DL, ACTSTR[SI]
        
        MOV AH, 02H
        MOV DH, ACTSTR2[SI]
        
        ; Check if same
        CMP DL, DH
        JNE DIFR
        
        INC SI
        LOOP DISPL
        
        ; All same
        MOV AH, 09H
        LEA DX, SAME
        INT 21H
        JMP END
        
        DIFR:
           MOV AH, 09H
           LEA DX, DIFF
           INT 21H 
        
    END:
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