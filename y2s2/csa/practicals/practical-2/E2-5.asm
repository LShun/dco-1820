.MODEL SMALL
.STACK 100
.DATA
    VAL DB 4
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH, 02H
    MOV DL, VAL
    DEC DL
    ADD DL, 30H
    INT 21H

    MOV DL, ','
    INT 21H

    MOV DL, '4'
    INT 21H

    
    MOV DL, ','
    INT 21H

    MOV DL, '5'
    INT 21H    
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN