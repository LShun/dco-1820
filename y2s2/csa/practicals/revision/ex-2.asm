; ex-2 (looping,jump,divide)
; display all digit from 1-9, using looping
; BUT, ask user for digit, n
; replace all digits that can be divided evenly by n with *

.MODEL SMALL
.STACK 100
.DATA
    reqtxt DB 'Enter a digit: $'
    
    m DB ?
    n DB ?    ; user digit
    
    digits DB 9
    
    nl db 13, 10, '$' 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; ask for a digit, n
    MOV AH, 09h
    LEA DX, reqtxt
    INT 21h
    
    MOV AH, 01h
    INT 21h
    SUB AL, '0'
    MOV n, AL
    
    CALL newline
    
    
    ; for numbers, m in 1-9
    MOV m, 1
    MOV CH, 0
    MOV CL, digits
    NUMBERS:
        ; divide m by n
        MOV AH, 0
        MOV AL, m
        
        DIV n
        
        ; compare
        CMP AH, 0
        JNE DISPM
        
        ; ; else, display '*'
        MOV DL, '*'

        JMP PRINT
        
        ; if remainder != 0, display m
        DISPM:
            MOV DL, m
            ADD DL, '0'
            
        PRINT:
            MOV AH, 02h
            INT 21h
            
        ; add 1 to m
        INC m
        
        ; continue
        LOOP NUMBERS
    
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