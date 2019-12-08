; 5-ex3.asm
; ask user for "M/F" and disp:
; - 'Male' if M
; - 'Female' if F

.MODEL SMALL
.STACK 100
.DATA
    GENDER   DB ?
    TXT   DB "Enter gender (M/F): $"
    NL    DB 13, 10, "$"
    M    DB "Male$"
    F  DB "Female$"  
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH, 9
    LEA DX, TXT
    INT 21H
    
    MOV AH, 1
    INT 21H
    MOV GENDER, AL
    
    MOV AH, 9
    LEA DX, NL
    INT 21H
    
    
    
    ; IF (BIT == F)
    CMP GENDER, "M"
    JNE FEMALE
    
    LEA DX, M
    JMP FINISH
    
    FEMALE:
        LEA DX, F
        
    FINISH:
        MOV AH, 09H
        INT 21H
        
        MOV AX, 4C00H
        INT 21H
MAIN ENDP
END MAIN