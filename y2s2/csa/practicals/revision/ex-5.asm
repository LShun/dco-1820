; ex-5.asm (loop, array, jump)
; find largest value from list
; prompt for 5 digits
; accept 5 digits (assume will only enter 5 digits)
; find largest value
; display largest value on screen

.MODEL SMALL
.STACK 100
.DATA
   STR LABEL BYTE
       maxn DB 6
       actn DB ?
       actstr DB 6 dup('$')
       
       
   max DB ?
   digits DB 5
   inTxt DB 'Please enter 5 digits >> $'
   maxTxt DB 'The largest value is >> $'
   nl DB 13,10,'$'

.CODE

MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    ; ask for 5 digits
    ; text
    MOV AH, 09h
    LEA DX, inTxt
    INT 21h
    
    ; input
    MOV AH, 0Ah
    LEA DX, str
    INT 21h
    
    
    ; set first digit as max
    MOV BL, actstr[0]
    MOV max, BL
    
    MOV CH, 0
    MOV CL, actn
    MOV SI, 0
    ; from 2-5 digit in ACTSTR
    COMPARE:
        ; compare n with max
        MOV BL, actstr[SI]
        CMP BL, max
        ; if n <= max, cont
        JG REPLACE
        JMP CONTINUE
        
        ; else, max = n
        REPLACE:
            MOV BL, actstr[SI]
            MOV max, BL
        ; continue
        CONTINUE:
            INC SI
            LOOP COMPARE
    ; display max
    CALL NEWLINE
    
    MOV AH, 09H
    LEA DX, maxTxt
    INT 21h
    
    MOV AH, 02h
    MOV DL, max
    INT 21h
    
    MOV AX ,4C00h
    INT 21H
    
MAIN ENDP

NEWLINE PROC
    MOV AH, 09H
    LEA DX, nl
    INT 21h
    RET

NEWLINE ENDP

END MAIN