; Given the thing in .DATA, display in uppercase

; Then add "The capital letter of STR is" in front of the output,
; where STR is m

.MODEL SMALL
.STACK 100
.DATA
   CHAR DB "m"
   STR  DB "The capital letter of $"
   IS   DB " is $"  
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Put the rest of your code here
    
    ; Display header 
    MOV AH, 09H
    LEA DX, STR
    INT 21H
    
    ; Display small letter
    MOV AH, 02H
    MOV DL, CHAR
    INT 21H
    
    ; Display is
    MOV AH, 09H
    LEA DX, IS
    INT 21H
    
    ; Display caps CHAR
    MOV AH, 02H
    MOV DL, CHAR
    SUB DL, "a"
    ADD DL, "A"
    INT 21H
    
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN