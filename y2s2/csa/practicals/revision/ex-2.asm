; ex-2 (looping,jump,divide)
; display all digit from 1-9, using looping
; BUT, ask user for digit, n
; replace all digits that can be divided evenly by n with *

.MODEL SMALL
.STACK 100
.DATA

    NUM DB 9
    START DB 1

    INP DB "Enter a digit: $"
    NL  DB 13, 10, '$'

    USR DB ?

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    ; ASK FOR DIGIT
    MOV AH, 09H
    LEA DX, INP
    INT 21H

    MOV AH, 01H
    INT 21H
    ; STORE DIGIT AWAY
    SUB AL, '0'
    MOV USR, AL

    ; NEWLINE
    MOV AH, 09H
    LEA DX, NL
    INT 21H

    ; LOOP (FROM 1-9)
    MOV CH, 0
    MOV CL, NUM
    NUMLIST:
        ; DIVIDE START BY USR
        MOV AH, 0
        MOV AL, START
        DIV USR

        ; IF AH == 0, THEN DISPLAY *
        CMP AH, 0
        JNE DISPNUM
        MOV AH, 02H
        MOV DL, '*'
        JMP CONTINUE

        ; ELSE, DISPLAY THE NUMBER (ASCII)
        DISPNUM:
            MOV AH, 02H
            MOV DL, START
            ADD DL, '0'
        
        CONTINUE:
            INT 21H
            INC START
            LOOP NUMLIST

    MOV AX, 4C00H
    INT 21H
MAIN ENDP
END MAIN