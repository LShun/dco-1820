; 6-ex4.asm
; Ask for num
; - if even, output 'Even'
; - else, 'Odd'
; Note: According to ASCII, 48 is "0",
;       therefore, no need to subtract or add

.MODEL SMALL
.STACK 100
.DATA
    DIG   DB ?
    TXT   DB "Enter a digit: $"
    NL    DB 13, 10, "$"
    E    DB "Even$"
    O  DB "Odd$"
    TWO DB 2  
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH, 9
    LEA DX, TXT
    INT 21H
    
    MOV AH, 1
    INT 21H
    MOV DIG, AL
    
    MOV AH, 9
    LEA DX, NL
    INT 21H
    
    MOV AL, DIG
    MOV AH, 0
    DIV TWO
    
    CMP AH, 0 ; check remainder
    JNE ODD
    
    LEA DX, E
    JMP FINISH
    
    ODD:
        LEA DX, O
        
    FINISH:
        MOV AH, 09H
        INT 21H
        
        MOV AX, 4C00H
        INT 21H
MAIN ENDP
END MAIN