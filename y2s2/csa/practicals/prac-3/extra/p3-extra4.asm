; Given the thing in .DATA, display in uppercase

.MODEL SMALL
.STACK 100
.DATA
   CHAR DB "m"  
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Put the rest of your code here
    MOV AH, 02H
    MOV DL, CHAR
    SUB DL, "a"
    ADD DL, "A"
    INT 21H
    
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN