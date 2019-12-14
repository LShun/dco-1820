;4-ex1.2.asm
; Allow user enter day (any digit, 1 digit)
; If 1-5, display "This is a weekday"
; If 6-7, display "This is a weekend"
; else, display "Not a valid day"

.MODEL SMALL
.STACK 100
.DATA
    opText DB 'Enter a day: $'
    nl DB 13,10,'$'
    op DB ?
    
    wkdy DB 'This is a weekday$'
    wken DB 'This is a weekend$'
    inval DB 'Not a valid day$'
    
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
    
    ; if 1 <= op <= 7
    CMP op, '1'
    JL INVA
    
    CMP op, '7'
    JG INVA
    
    ; if <= 5, wkdy, else wken
    CMP op, '5'
    JG WEEKEND
    
    LEA DX, wkdy
    JMP fin
    
    WEEKEND:
        LEA DX, wken
        JMP fin
    
    INVA:
        LEA DX, inval 
    
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