; q12.asm
; Perform 1-complement operation
; Ask user to enter 8-bit bin data, flip it,
; then display result

.MODEL SMALL
.STACK 100
.DATA
    INPROMPT    DB  "Please enter 8-bit binary data >> $"
    OUTPROMPT   DB  "The One's Complement value of the data is >> $"
    NL          DB  13,10,'$'
    KBINPUT     LABEL   BYTE
        MAXN    DB  10
        ACTN    DB  ?
        ACTTXT  DB  20 DUP('$')

.CODE

MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    ; PROMPT ENTER
    MOV AH, 09H
    LEA DX, INPROMPT
    INT 21H

    MOV AH, 0AH
    LEA DX, KBINPUT
    INT 21H
    
    MOV AH, 09H
    LEA DX, NL
    INT 21H

    ; FLIP BINARY
    MOV CH, 0
    MOV CL, ACTN
    LEA SI, ACTTXT

    CHECK:
        MOV BL, [SI]
        CMP BL, "1"
        JNE TOONE
        MOV BL, "0"
        MOV [SI], BL
        JMP FIN

        TOONE:
            MOV BL, "1"
            MOV [SI], BL
        
        FIN:
            INC SI
            LOOP CHECK

    ; DISPLAY OUTPUT PROMPT
    MOV AH, 09H
    LEA DX, OUTPROMPT
    INT 21H

    ; DISPLAY ONE'S COMPLEMENT
    MOV AH, 09H
    LEA DX, ACTTXT
    INT 21H
    LEA DX, NL
    INT 21H

    MOV AX, 4C00H
    INT 21H
MAIN ENDP

END MAIN