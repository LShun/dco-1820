; ex-1.asm
; Minus first char with second char, display result in ASCII.
; Assume: 1st char ALWAYS > 2nd char

.MODEL SMALL
.STACK 100
.DATA 
    c1_txt DB "Enter 1st character: $"
    c2_txt DB "Enter 2nd character: $"
    minus DB " - $"
    equal DB ' = $'
    
    c1 DB ?
    c2 DB ?
    
    res DB ?
    
    quo DB ?
    rem DB ?
    
    TEN DB 10
    
    nl DB 13, 10, '$'
    
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; get 1st char
    MOV AH, 09h
    LEA DX, c1_txt
    INT 21h
    
    MOV AH, 01h
    INT 21h
    
    MOV c1, AL
    
    CALL newline
    
    ; get 2nd char
    MOV AH, 09h
    LEA DX, c2_txt
    INT 21h
    
    MOV AH, 01h
    INT 21h
    
    MOV c2, AL
    
    CALL newline
    
    ; result = 2nd - 1st char
    MOV BL, c2
    SUB BL, c1
    
    MOV res, BL
    
    ; div result by 10
    MOV AH, 0
    MOV al, res
    
    DIV ten
    
    MOV quo, AL      ; quotient
    MOV rem, AH      ; remainder

    ; display result
    MOV AH, 02h
    MOV DL, c2
    INT 21h
    
    MOV AH, 09h
    LEA DX, minus
    INT 21h
    
    MOV AH, 02h
    MOV DL, c1
    INT 21h
    
    MOV AH, 09h
    LEA DX, equal
    INT 21h
    
    MOV AH, 02h
    MOV DL, quo
    ADD DL, '0'
    INT 21h
    
    MOV AH, 02h
    MOV DL, rem
    ADD DL, '0'
    INT 21h
    
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP

newline PROC
    MOV AH, 09h
    LEA DX, nl
    INT 21h
    RET
newline ENDP

END MAIN