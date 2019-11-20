.MODEL SMALL
.STACK 100
.DATA
    byteList DB 2,4,6,8,10,12
    label    DB "Sum: $"
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Clear BX
    MOV BX, 0
    
    ; for every item in byteList
    LEA SI, byteList
    MOV CX, 6
    SUMLIST:
        ADD BL, [SI]
        INC SI
        LOOP SUMLIST
        
    ; display "sum: "
    MOV AH, 09H
    LEA DX, label
    INT 21H
    
    ; display the figure
    ; split the figure into tens & ones
    MOV AX, BX
    MOV BL, 10
    DIV BL

    ; display each of them individually
    MOV BH, AH ; move away data first
    MOV AH, 02H
    MOV DL, AL
    ADD DL, "0"
    MOV DH, 0
    INT 21H
    
    MOV DL, BH
    MOV DH, 0
    ADD DL, "0"
    INT 21H
    
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN