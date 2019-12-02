; Display 1-9 vertically, with a " x 3 =" trailer, then the result
; in the left

.MODEL SMALL
.STACK 100
.DATA
    NL DB 13,10, "$"
    num DB 1
    trailer DB " x 3 = $"
    THR DB 3
    TEN DB 10
    ans DB ?
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV CX, 9
    DISP:
        MOV AH, 02H
        MOV DL, num
        ADD DL, "0"
        INT 21H
        
        MOV AH, 09H
        LEA DX, trailer
        INT 21H
        
        ; multiply & divide
        MOV AL, num
        MUL THR
        
        DIV TEN
        MOV BH, AH
        MOV BL, AL

        ; display
        
        MOV AH, 02H
        MOV DL, BL
        ADD DL, "0"
        INT 21H
        
        MOV AH, 02H
        MOV DL, BH
        ADD DL, "0"
        INT 21H
        
        CALL NEWLINE
        
        INC num
        
        LOOP DISP
        
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP

NEWLINE PROC
    MOV AH, 09H
    LEA DX, NL
    INT 21H
    RET 
END MAIN