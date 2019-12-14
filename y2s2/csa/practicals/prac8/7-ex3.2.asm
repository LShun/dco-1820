; 7-ex3.2.asm
; Allow user to enter D/C
; display Diploma/Certificate respectively
; ask user if want to repeat, if yes, cont.

.MODEL SMALL
.STACK 100
.DATA
    opText DB 'Enter code (D/C): $'
    nl DB 13,10,'$'
    op DB ?
    
    dipl DB 'Diploma$'
    cert DB 'Certificate$'
    conti DB 'Continue(Y/N): $'
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    QUERY:
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
    JMP cont
    
    DIP:
        LEA DX, dipl
        JMP cont
    
    CONT:
        MOV AH, 09h
        INT 21H
        
        CALL newline
        
        ; ask if continue
        MOV AH, 9H
        LEA DX, conti
        INT 21H

        MOV AH, 01H
        INT 21H
        MOV op, AL
        
        CALL newline
        
        CMP op, 'Y'
        JNE FIN
        JMP QUERY
        
    FIN:    
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