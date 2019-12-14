; 6-ex3.1.asm
; Allow user to enter D/C
; display Diploma/Certificate respectively

.MODEL SMALL
.STACK 100
.DATA
    opText DB 'Enter code (D/C): $'
    nl DB 13,10,'$'
    op DB ?
    
    dipl DB 'Diploma$'
    cert DB 'Certificate$'
    
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
    
    ; check if not diploma
    CMP op, 'C'
    JNE DIP
    
    
    LEA DX, cert
    JMP fin
    
    DIP:
        LEA DX, dipl
        JMP fin
    
    FIN:
        MOV AH, 09h
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