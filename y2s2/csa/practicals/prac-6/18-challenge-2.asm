; 18-challenge-2.asm
; display n-index number, n from 0-6,
; user input
.MODEL SMALL
.STACK 100
.DATA
   NUM DB 4,7,2,9,6,5,8
   TXT DB 'Enter index (0-6):'
   NL DB 13, 10, '$'
   
   INDEX DW ?
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH, 9
    LEA DX, TXT
    INT 21H
    
    MOV AH, 1
    INT 21H
    
    MOV AH, 0
    MOV INDEX, AX
    SUB INDEX, '0'
    
    ; LOAD INTO SI
    LEA SI, NUM
    ADD SI, INDEX 
    
    MOV AH, 02H
    MOV DL, [SI]
    ADD DL, '0'

    INT 21H
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN