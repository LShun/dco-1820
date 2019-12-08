; 15-ex-2-1
; declare list of int, write prog to disp all 
.MODEL SMALL
.STACK 100
.DATA
   NUM DB 2,5,6,8,1,7 
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
        ADD DL, "0"
        INT 21H
        INC SI
    LOOP L1
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN