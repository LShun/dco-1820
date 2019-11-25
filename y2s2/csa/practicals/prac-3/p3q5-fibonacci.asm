TITLE FibonacciSequence
; Calculate first 6 fibonacci number sequence using the formula:
; Fib(n) = Fib(n-1) + Fib(n-2)

.MODEL SMALL
.STACK 100
.DATA
    Fibo DB 1,1,?,?,?,? 
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    
    MOV CX, 4
    LEA SI, Fibo+2
    FIBONNACI:
        MOV BL, [SI]-1
        MOV BH, [SI]-2
        ADD BL, BH
        
        MOV [SI], BL
        INC SI
        LOOP FIBONNACI
        
    MOV CX, 6
    LEA SI, Fibo    
    SHOWNUM:
        ; Load the number from array
        MOV DL, [SI]
        ADD DL, '0'
        MOV DH, 0
        ; Display the number
        MOV AH, 02H
        INT 21H
        ; Display the ','
        MOV DL, ','
        INT 21H
        
        INC SI
        LOOP SHOWNUM
        
        
          
    
    ; For the rest, take the n-1 and n-2 and add together
    ; repeat for 4 times
    
    MOV AX,4C00H
    INT 21H
    
MAIN ENDP
END MAIN