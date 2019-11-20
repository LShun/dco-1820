.MODEL SMALL
.STACK 100
.DATA
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Put the rest of your code here
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN