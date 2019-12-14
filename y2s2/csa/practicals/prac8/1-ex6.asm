;1-ex6.asm
;Write prog to allow user to enter (+, -),
; perform calc based on operator

.MODEL SMALL
.STACK 100
.DATA
    opText DB 'Enter an operator (+, -): $'
    txt1 DB 'Enter 1st number: $'
    txt2 DB 'Enter 2nd number: $'
    nl DB 13,10,'$'
    n1 DB ?
    n2 DB ?
    op DB ?
    res DB ?
    quo DB ?
    rem DB ?
    ten DB 10
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; ask for operator
    MOV AH, 09h
    LEA DX, opText
    INT 21h
    
    MOV AH, 01h
    INT 21h
    
    MOV op, AL
    
    CALL newline
    
    ; ask for 2 num
    MOV AH, 09h
    LEA DX, txt1
    INT 21h
    
    MOV AH, 01h
    INT 21h
    SUB AL, '0'
    
    MOV n1, AL
    
    CALL newline
    
    
    MOV AH, 09h
    LEA DX, txt2
    INT 21h
    
    MOV AH, 01h
    INT 21h
    SUB AL, '0'
    
    MOV n2, AL
    
    CALL newline
    
    ; if plus, go in here
    CMP op, '-'
    JE NEGA
    
    POS:
        ; add them together
        MOV BL, n1
        ADD BL, n2
        MOV res, BL
        ; display result
        MOV AH, 02h
        MOV DL, n1
        ADD DL, '0'
        INT 21h
        
        MOV DL, '+'
        INT 21h
        
        MOV DL, n2
        ADD DL, '0'
        INT 21h
        
        MOV DL, '='
        INT 21h
        
        ; go to end
        JMP fin
    
    NEGA:
    ; else if minus, go in here
        MOV BL,n1
        ; subtract them
        SUB BL, n2
        MOV res, BL
        ; display result
        MOV AH, 02h
        MOV DL, n1
        ADD DL, '0'
        INT 21h
        
        MOV DL, '-'
        INT 21h
        
        MOV DL, n2
        ADD DL, '0'
        INT 21h
        
        MOV DL, '='
        INT 21h
        
        
    FIN:
        MOV AH, 0
        MOV AL, res
        DIV ten
        
        ADD AH, '0'
        add al, '0'
        
        MOV rem, AH
        MOV quo, AL
        
        
        MOV AH, 02h
        MOV DL, quo
        INT 21H
        
        MOV AH, 02h
        MOV DL, rem
        INT 21H
        
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