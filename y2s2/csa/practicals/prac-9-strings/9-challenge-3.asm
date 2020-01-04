; 9-challenge-3.asm
; Allow user to enter string. Check if its
; palindrome, reads same forward & backward.

.MODEL SMALL
.STACK 100
.DATA
    INPROMPT1       DB 'Enter a string: $'
    YES             DB 'It is a palindrome word$'
    NO              DB 'It is not a palindrome word$'
    NL              DB 13, 10, '$'
    
    MAXCHAR         DB 20
    STR1            LABEL BYTE
                    MAXN DB MAXCHAR
                    ACTN DB ?
                    ACTSTR DB MAXCHAR DUP("$")
    
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Prompt user to enter str
    MOV AH, 09H
    LEA DX, INPROMPT1
    INT 21H
    
    ; Accept chars
    MOV AH, 0AH
    LEA DX, STR1
    INT 21H
    
    CALL NEWL
    
    ; Use a pointer to track start
    ; and end.
    MOV SI, 0    ; START PTR
    MOV BH, 0
    MOV BL, ACTN
    MOV DI, BX   ; END PTR
    DEC DI       ; DECREMENT BY 1 FOR EOF
    
    CHECK:
        ; Check if start ptr = end ptr
        CMP SI, DI
        ;   yes, palindrome
        JGE  PALI
        ;   else, check if both chars are same
        MOV BH, ACTSTR[SI]
        MOV BL, ACTSTR[DI]
        CMP BH, BL
        ;       yes, incr. start ptr, decr. end ptr
        JNE NOTPALI
        INC SI
        DEC DI
        ;            repeat sequence
        LOOP CHECK
        ;       no,  return not palindrome
    NOTPALI:
        MOV AH, 9H
        LEA DX, NO
        INT 21H
        JMP END
    PALI:
        MOV AH, 9H
        LEA DX, YES
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