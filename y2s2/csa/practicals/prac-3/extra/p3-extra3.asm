.MODEL SMALL
.STACK 100
.DATA
   SQUARE DB "*****", 13, 10, 
          DB "*   *", 13, 10, 
          DB "*   *", 13, 10, 
          DB "*****", "$" 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Put the rest of your code here
    MOV AH, 09H
    LEA DX, SQUARE
    INT 21H
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN