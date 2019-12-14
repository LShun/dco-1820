; 5-ex1.3.asm
; Allow user enter a char
; check if vowel or consonant
; display 'Vowel' or 'Consonant

.MODEL SMALL
.STACK 100
.DATA
    opText DB 'Enter a character: $'
    nl DB 13,10,'$'
    op DB ?
    
    vowe DB 'Vowel$'
    cons DB 'Consonant$'
    
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
    
    ; check if not vowel
    CMP op, 'a'
    JE VOW
    
    CMP op, 'e'
    JE VOW
    
    CMP op, 'i'
    JE VOW
    
    CMP op, 'o'
    JE VOW
    
    CMP op, 'u'
    JE VOW 
    
    LEA DX, cons
    JMP fin
    
    VOW:
        LEA DX, vowe
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