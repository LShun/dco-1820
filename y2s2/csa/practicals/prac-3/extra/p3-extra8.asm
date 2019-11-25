; Ask for input and let user know next char

.MODEL SMALL
.STACK 100
.DATA
    INP DB "Enter a character: $"
    NXT DB "The next character is $"
    CHAR DB ?
    NL  DB 13, 10, "$" 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Ask for input
    MOV AH, 09H
    LEA DX, INP
    INT 21H
    
    ; Input
    MOV AH, 01H
    INT 21H
    
    MOV CHAR, AL
    
    ; Newline
    MOV AH, 09H
    LEA DX, NL
    INT 21H
    
    ; Display header
    LEA DX, NXT
    INT 21H
    
    ; Display next char
    INC CHAR
    MOV AH, 02H
    MOV DL, CHAR
    INT 21H
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN