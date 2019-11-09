; Excahnge two characters contents, print output

.MODEL SMALL
.STACK 100
.DATA
    A DB 'a'
    B DB 'b'
    
.CODE
MAIN PROC

    MOV AX,@DATA
    MOV DS,AX
        
    ; Before exchange
    
    MOV BX, A
    MOV CX, B
    
    MOV AH, 02H
    MOV DL, '('
    INT 21H    
    
    MOV DL, BX
    INT 21H
    
    MOV DL, ','
    INT 21H
    
    MOV DL, CX
    INT 21H
    
    MOV DL, ')'
    INT 21H   
    
    ; Exchange
    
    XCHG BX, CX
    
    ; After exchange
    
    MOV AH, 02H
    MOV DL, '('
    INT 21H    
    
    MOV DL, BX
    INT 21H
    
    MOV DL, ','
    INT 21H
    
    MOV DL, CX
    INT 21H
    
    MOV DL, ')'
    INT 21H
    
MAIN ENDP


END MAIN