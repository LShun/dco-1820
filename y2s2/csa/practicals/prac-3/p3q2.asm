; Copy the contents
; Given the following declarations, write a program that replaces the content of
; data2 with data1 AND displays the content of data1 AND data2. 
 

.MODEL SMALL
.STACK 100
.DATA
    initTxt DB "Initial content", 13, 10, '$'
    finTxt  DB "After replacement", 13, 10, '$'
    d1Txt DB "data1: $"
    d2Txt DB "data2: $"
    DATA1 DB "MILK"
    DATA2 DB 4 DUP ('*')
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Print title
    MOV AH, 09H
    LEA DX, initTxt
    INT 21H
    
    CALL PRINTCONTENT
    CALL NEWLINE
    
    ; Replace DATA2 with DATA1
    
    LEA SI, DATA1
    LEA DI, DATA2
    
    MOV CX, 4
    REPLACE:
        MOV DL, [SI]
        MOV [DI], DL
        INC DI
        INC SI
        LOOP REPLACE
        
    MOV AH, 09H
    LEA DX, finTxt
    INT 21H
    
    CALL PRINTCONTENT

    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP

PRINTCONTENT PROC
    ; Print label + DATA1
    MOV AH, 09H
    LEA DX, d1Txt
    INT 21H
   
    LEA SI, DATA1
    CALL PRINT4
    CALL NEWLINE
    
    ; Print label + DATA2
    MOV AH, 09H
    LEA DX, d2Txt
    INT 21H
    
    LEA SI, DATA2
    CALL PRINT4
    CALL NEWLINE
    RET
PRINTCONTENT ENDP

; Print the first 4 letters in array pointed by SI
PRINT4 PROC
    MOV CX, 4
    L0:
        MOV DL, [SI]
        MOV AH, 2
        INT 21H
        INC SI
        LOOP L0
    RET 
PRINT4 ENDP

NEWLINE PROC
    MOV AH, 02H
    MOV DL, 0DH ; Carriage return
    INT 21H
    MOV DL, 0AH ; Line feed
    INT 21H
    RET
NEWLINE ENDP

END MAIN