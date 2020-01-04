; ex-3.asm (looping, array, jump)
; given list of number 'NUM DB 4,9,7,3,2,5,4,0'

; Requirements:
; display all integers
; modify to display integers > 2
; add up all numbers > 2, display the result (ans: 32)

.MODEL SMALL
.STACK 100
.DATA
    NUM DB 4,9,7,3,2,5,4,0
    count DB 8
    NL DB 13, 10, '$'
    sum DB ?
    quo DB ?
    rem DB ?
    ten DB 10
    
    alltxt DB "All integers in NUM: $"
    g2txt DB "All integers in NUM > 2: $"
    sumtxt DB "SUM OF All integers in NUM > 2: $" 
    
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; display all integers
    ; display text
    MOV AH, 09h
    LEA DX, alltxt
    INT 21h
    
    
    ; for all n in NUM (NOTE: count is CL)
    MOV BL, count
    MOV SI, 0
    MOV CH, 0
    MOV CL, count
    MOV AH, 02H
    DISPALL:
        ; display n
        MOV DL, NUM[SI]
        ADD DL, "0"
        INT 21H
        
        MOV DL, " "
        INT 21H
        INC SI
        
        LOOP DISPALL
    
    CALL NEWLINE
    
    ; display all integers > 2
    ; display text
    MOV AH, 09h
    LEA DX, g2txt
    INT 21h
        
    ; for all n in NUM (NOTE: count is CL)
    MOV BL, count
    MOV SI, 0
    MOV CH, 0
    MOV CL, count
    MOV AH, 02H
    DISPG2:
        ; if n > 2, display
        MOV DL, NUM[SI]
        CMP DL, 2
        
        JNG SKIP
        ; display results (NOTE: ADD '0' for ASCII)
        ADD DL, '0'
        INT 21h
        
        MOV DL, " "
        INT 21H
        
        ; else, skip
        SKIP:
            ; loop
            INC SI
            LOOP DISPG2
    
    
    CALL NEWLINE
    
    ; add up all num > 2, display sum
    
    ; display text
    MOV AH, 09h
    LEA DX, sumtxt
    INT 21h
        
    ; for all n in NUM (NOTE: count is CL)
    MOV BL, count
    MOV SI, 0
    MOV CH, 0
    MOV CL, count
    GETSUM:
        ; if n > 2
        MOV DL, NUM[SI]
        CMP DL, 2
        
        JNG SKIPADD
        ; SUM += n
        ADD sum, DL
        
        ; else, skip
        SKIPADD:
            ; loop
            INC SI
            LOOP GETSUM
    
    ; display results (NOTE: ADD '0' for ASCII), can be > 10
    ; divide sum
    MOV AH, 0
    MOV AL, sum
    
    DIV ten
    
    MOV quo, AL
    MOV rem, AH
    
    ; display sum
    MOV AH, 02h
    MOV DL, quo
    ADD DL, '0'
    INT 21h
    
    MOV AH, 02h
    MOV DL, rem
    ADD DL, '0'
    INT 21h
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP

newline PROC
    MOV AH, 09h
    LEA DX, nl
    INT 21h
    RET
newline ENDP

END MAIN