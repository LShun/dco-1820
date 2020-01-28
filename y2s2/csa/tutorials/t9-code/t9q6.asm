.MODEL SMALL
.STACK 100
.DATA
    INPROMPT    DB  "Please enter 5 decimal digits >> $"
    OUTPROMPT   DB  "The largest value in the list is >> $"
    NL          DB  13,10,'$'
    DIGITS      LABEL   BYTE
        MAXN    DB  6
        ACTN    DB  ?
        ACTSTR  DB  20 DUP('$')
    LARGEST     DB ?
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    ; ASK FOR 5 DIGITS
    MOV AH, 09H
    LEA DX, INPROMPT
    INT 21H

    MOV AH, 0AH
    LEA DX, DIGITS
    INT 21H

    MOV AH, 09H
    LEA DX, NL
    INT 21H

    ; MOVE LAST NUMBER IN
    LEA DI, ACTSTR
    MOV BL, [DI]
    MOV LARGEST, BL
    INC DI
    ; CHECK-AND-COMPARE

    MOV CX, 4
    MAX:
        MOV BL, [DI]
        CMP BL, LARGEST
        JLE CONTINUE
        ; IF LARGEST, MOVE IN
        MOV BL, [DI]
        MOV LARGEST, BL
        ; ELSE, JUST CONT
        CONTINUE:
            INC DI
            LOOP MAX
    
    ; DISPLAY LARGEST VALUE
    MOV AH, 9H
    LEA DX, OUTPROMPT
    INT 21H

    MOV AH, 02H
    MOV DL, LARGEST
    INT 21H

    MOV AX,4C00H
    INT 21H
MAIN ENDP
END MAIN