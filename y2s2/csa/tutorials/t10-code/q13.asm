; q13.asm
; display all numeric data input by user, filter out all other characters
.MODEL SMALL
.STACK 100
.DATA
    INPROMPT    DB  "Please enter any data and press enter >> $"
    OUTPROMPT   DB  "The numerical value is >> $"
    NL          DB  13, 10, "$"
    KBINPUT     LABEL   BYTE
        MAXC    DB  50
        ACTC    DB  ?
        ACTSTR  DB  50 DUP('$')

    STRIPSTR    DB 50 DUP('$')

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    ; PRINT LABEL
    MOV AH, 09H
    LEA DX, INPROMPT
    INT 21H

    ; ACCEPT INPUT
    MOV AH, 0AH
    LEA DX, KBINPUT
    INT 21H

    MOV AH, 09H
    LEA DX, NL
    INT 21H

    ; STRIP ALL NON-NUMERIC FIGURE
    MOV CH, 0
    MOV CL, ACTC
    MOV SI, 0
    MOV DI, 0

    OPERATE:
        MOV BL, ACTSTR[SI]
        ; CHECK IF BETWEEN '0' AND '9'
        CMP BL, '0'
        JB CONTINUE
        CMP BL, '9'
        JA CONTINUE

        MOV STRIPSTR[DI], BL
        INC DI

        CONTINUE:
            INC SI
            LOOP OPERATE

    ; PRINT LABEL
    MOV AH, 09H
    LEA DX, OUTPROMPT
    INT 21H

    ; PRINT OUTPUT
    MOV AH, 09H
    LEA DX, STRIPSTR
    INT 21H

    MOV AX, 4C00H
    INT 21H
MAIN ENDP
END MAIN
