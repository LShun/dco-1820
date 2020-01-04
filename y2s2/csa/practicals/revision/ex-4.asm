; ex-4.asm (loop, array, jump i/p string)
; validate postcode input.
; valid postcode have 5 digits

.MODEL SMALL
.STACK 100
.DATA
    pcodedigits DB 5
    intxt DB 'Enter postcode: $'
    val   DB 'Valid Postcode$'
    inval DB 'Invalid Postcode$'
    nl    DB 13,10,'$'
    
    STR LABEL BYTE
        MAXN DB 6
        ACTN DB ?
        ACTSTR DB 6 DUP("$")

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    ; ask for a postcode
    MOV AH, 09H
    LEA DX, intxt
    INT 21h
    
    MOV AH, 0AH
    LEA DX, STR
    INT 21H
    
    CALL NEWLINE
    
    
    ; check if tchars != 5
    MOV AL, actn
    CMP AL, pcodedigits
    
    ; if so, invalid
    JNE invalid
    
    ; else, test if each char between 
    ; '0' and '9'
    MOV CH, 0
    MOV CL, pcodedigits
    MOV SI, 0
    ; loop
    CHECK:
        MOV BL, actstr[SI]
        
        ; check if '0' <= n <= '9'
        CMP BL, '0'
        JL invalid
        
        CMP BL, '9'
        JG invalid
        ; if not, invalid
        
        ; if yes, continue
        INC SI
        LOOP check
    ; end loop
    
    ; valid
    VALID:
        MOV AH, 09h
        LEA DX, val
        INT 21h
        JMP FIN
    
    ; invalid
    INVALID:
        MOV AH, 09h
        LEA DX, inval
        INT 21h
    
    ; end prog
    FIN:
        MOV AX, 4C00H
        INT 21H

MAIN ENDP

newline PROC
    MOV AH, 09h
    LEA DX, nl
    INT 21h
    RET
newline ENDP

END MAIN