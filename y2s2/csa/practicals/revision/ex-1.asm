; ex-1.asm
; Minus first char with second char, display result in ASCII.
; Assume: 1st char ALWAYS > 2nd char

.MODEL SMALL
.STACK 100
.DATA
    IPONE DB "Enter 1st character: $"
    IPTWO DB "Enter 2nd character: $"
    MINUS DB " - $"
    EQUAL DB " = $"
    QUO   DB ?
    REM   DB ?
    CH1   DB ?
    CH2   DB ?
    TEN   DB 10
    NL    DB 13,10,'$'
    DIFF  DB ?
.CODE

MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    ; ask for first char
    MOV AH, 09H
    LEA DX, IPONE
    INT 21H

    MOV AH, 01H
    INT 21H

    MOV CH1, AL

    ; NEWLINE
    MOV AH, 09H
    LEA DX, NL
    INT 21H

    ; ask for 2nd char
    MOV AH, 09H
    LEA DX, IPTWO
    INT 21H

    MOV AH, 01H
    INT 21H
    MOV CH2, AL

    ; NEWLINE
    MOV AH, 09H
    LEA DX, NL
    INT 21H

    ; 1st char - 2nd char
    MOV BL, CH1
    SUB BL, CH2

    MOV DIFF, BL

    ; display result (note: two digits)

    ; display CH1 - CH2 = 
    MOV AH, 02H
    MOV DL, CH1
    INT 21H

    MOV AH, 09H
    LEA DX, MINUS
    INT 21H

    MOV AH, 02H
    MOV DL, CH2
    INT 21H

    MOV AH, 09H
    LEA DX, EQUAL
    INT 21H

    ; divide by 10
    MOV AH, 0
    MOV AL, DIFF
    DIV TEN

    MOV REM, AH
    MOV QUO, AL

    ; display AL (ASCII)
    MOV AH, 02H
    MOV DL, QUO
    ADD DL, '0'
    INT 21H

    ; display AH (ASCII)
    MOV AH, 02H
    MOV DL, REM
    ADD DL, '0'
    INT 21H

    MOV AX, 4C00H
    INT 21H
MAIN ENDP
END MAIN