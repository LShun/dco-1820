.MODEL SMALL
.STACK 100
.DATA
    byte1 DB 10, 20, 30
    array1 DW 30 DUP(?), 0, 0
    array2 DW 5 DUP(3 DUP(?))
    array3 DW 1,2,3,4
    digitStr DB 12345678$"
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV DX, LENGTHOF byte1
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN