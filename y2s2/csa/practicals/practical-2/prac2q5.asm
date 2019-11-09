.MODEL SMALL
.STACK 100
.DATA
    VAL DB 4
    strReq DB "Please enter a digit: $"
    strMid DB " times $"
    strEnd DB " returns: $"
    usrDig DB ?
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Put the rest of your code here
    ; Req for in
    MOV AH, 09H
    LEA DX, strReq
    INT 21H
    
    ; Get int
    MOV AH, 01H
    INT 21H
    
    ; Store int into usrDIg
    MOV usrDig, AL
    
    CALL NEW_LINE
    
    ; Print the output
    MOV AH, 02H
    MOV DX, usrDig
    INT 21H
    
    MOV AH, 09H
    LEA DX, strMid
    INT 21H
    
    MOV AH, 02H
    MOV DX, usrDig
    INT 21H
    
    MOV AH, 09H
    LEA DX, strEnd
    INT 21H
    
    ; Find the square
    MOV BX, usrDig
    SUB BX, "0"
    MOV AL, BX
    MUL BX
    ADD AX, "0"
    MOV usrDig, AX
    
    ; Print the square
    MOV AH, 02H
    MOV DX, usrDig
    INT 21H
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP

NEW_LINE PROC
    MOV     AH, 02H
    MOV     DL, 0DH
    INT     21H
    MOV     DL, 0AH
    INT     21H
    RET                    
NEW_LINE ENDP

END MAIN