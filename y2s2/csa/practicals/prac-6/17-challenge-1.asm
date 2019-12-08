; 17-challenge-1.asm
; declare two list of int, 
; write prog to disp all
; then display sum of each column
.MODEL SMALL
.STACK 100
.DATA
   NUM1 DB 4,7,2,9
   NUM2 DB 10,8,5,3
   TOTAL DB 0
   TEN DB 10 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Put the rest of your code here
    ; DIRECT OFFSET
    MOV SI, 0 ; SI/DI/BX TO CHOOSE
    
    MOV CX, 4
    L1:
        MOV AH, 02H
        MOV DL, NUM1[SI]
        ADD TOTAL, DL
        MOV DL, NUM2[SI]
        ADD TOTAL, DL
        INC SI
        
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
        
        MOV TOTAL, 0
        
        ; display space
        MOV AH, 02H
        MOV DL, ' '
        INT 21H
    LOOP L1
    
    
    
    
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN