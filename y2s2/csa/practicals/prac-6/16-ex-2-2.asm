; 16-ex-2-2
; declare list of int, write prog to disp all
; then display total 
.MODEL SMALL
.STACK 100
.DATA
   NUM DB 2,5,6,8,1,7
   TOTAL DB 0
   TEN DB 10 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Put the rest of your code here
    ; DIRECT OFFSET
    MOV SI, 0 ; SI/DI/BX TO CHOOSE
    
    MOV CX, 6
    L1:
        MOV AH, 02H
        MOV DL, NUM[SI]
        ADD TOTAL, DL
        INC SI
    LOOP L1
    
    ; display
    MOV AL, TOTAL
    MOV AH, 0
    DIV TEN
    
    MOV BH, AH
    MOV BL, AL
    
    MOV AH, 02H
    MOV DL, BL
    ADD DL, "0"
    INT 21H
    
    MOV DL, BH
    ADD DL, "0"
    INT 21H
    
    
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN