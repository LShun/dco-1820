; Accidentally saved, but here's the q for 
; e5.1
; Accept vehicle code
; if M display RM1
; if C display RM2

; 8-ex5.2.asm
; Accept vehicle code, hours,
; display parking rate
; - if 'M', 1 * hrs
; - else, 2 * hrs

.MODEL SMALL
.STACK 100
.DATA
    DIG   DB ?
    HRS   DB ?
    TOTAL DB ?
    TXT   DB "Enter a vehicle code (C/M): $"
    TXTHRS DB "Enter hours: $"
    TXTPC  DB "Parking Charge = RM$"
    NL    DB 13, 10, "$"
    MF  DB 1
    CF  DB 2  
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; Ask input
    MOV AH, 9
    LEA DX, TXT
    INT 21H
    
    MOV AH, 1
    INT 21H
    MOV DIG, AL
    
    MOV AH, 9
    LEA DX, NL
    INT 21H
    
    MOV AH, 9
    LEA DX, TXTHRS
    INT 21H
    
    MOV AH, 1
    INT 21H
    SUB AL, "0"
    MOV HRS, AL
    
    MOV AH, 9
    LEA DX, NL
    INT 21H
    
    CMP DIG, 'M'
    JNE CAR
    
    MOV AH, 0
    MOV AL, HRS
    MUL MF
    JMP FINISH
    
    CAR:
        MOV AH, 0
        MOV AL, HRS
        MUL CF
        
        
    FINISH:
        MOV TOTAL, AL
        
        MOV AH, 09H
        LEA DX, TXTPC
        INT 21H
        
        MOV AH, 02H
        MOV DL, TOTAL
        ADD DL, "0"
        INT 21H
        
        MOV AX, 4C00H
        INT 21H
MAIN ENDP
END MAIN