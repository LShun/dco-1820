.MODEL SMALL
.STACK 100
.DATA
   STR DB "I LOVE MR.LOH$"
   NEWSTR DB "MR.LOH LOVES ME ALSO$"
   NL DB 13,10,"$" 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Put the rest of your code here
    MOV AH, 09H
    LEA DX, STR
    INT 21H
    
    LEA DX, NL
    INT 21H
    
    LEA DX, NEWSTR
    INT 21H
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN