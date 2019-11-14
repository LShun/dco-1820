.MODEL SMALL
.STACK 100
.DATA
    ITEMA DB 40
    ITEMB DB 1AH
    ITEMC DW ?
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AL, 40 
    SHL AL, 1
    MOV BL, 1AH
    MUL AL
    
    ; Q5c
    MOV AL, ITEMA
    SHL AL, 1
    
    ; Q5d
    MOV BL, ITEMB
    MUL AL
    
    ; Q5e
    MOV ITEMC, AX
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN