; t9q7.asm
; Password authentication

.MODEL SMALL
.STACK 100
.DATA
    NPROMPT DB 'Login Name: $'
    PPROMPT DB 'Password: $'
    SUCCESS DB '*** Login Successfully! ***$'
    FAILU   DB '*** Invalid Login Name. Access Denied! ***$'
    FAILS   DB '*** Invalid Password. Access Denied! ***$'

    REALN   DB 'ABC$'
    REALP   DB '123$'
    NL     DB 13, 10, '$'
    
    USRNAME LABEL BYTE
        MAXN    DB  4
        ACTN    DB  ?
        ACTS    DB  4 DUP('$')

    PWORD   LABEL BYTE
        MAXP    DB 4
        ACTPL    DB ?
        ACTP    DB 4 DUP('$')

.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; PROMPT USER FOR LOGIN NAME
    MOV AH, 09H
    LEA DX, NPROMPT
    INT 21H

    MOV AH, 0AH
    LEA DX, USRNAME
    INT 21H

    MOV AH, 09H
    LEA DX, NL
    INT 21H

    ; PROMPT USER FOR PW
    MOV AH, 09H
    LEA DX, PPROMPT
    INT 21H

    MOV AH, 0AH
    LEA DX, PWORD
    INT 21H

    MOV AH, 09H
    LEA DX, NL
    INT 21H

    ; COMPARE LOGIN NAME
    MOV CH, 0
    MOV CL, ACTN
    LEA SI, ACTS
    LEA DI, REALN
    LOGINCMP:
        MOV BL, [SI]
        CMP BL, [DI]
        ; IF FAIL, DISPLAY ERROR FOR NAME
        JNE FAILUSR
        INC SI
        INC DI
        LOOP LOGINCMP

    MOV CH, 0
    MOV CL, ACTPL
    LEA SI, ACTP
    LEA DI, REALP
    ; ELSE, COMPARE PW
    PWCMP:
        MOV BL, [SI]
        CMP BL, [DI]
        ; IF FAIL, DISPLAY ERROR FOR PW
        JNE FAILPW
        INC SI
        INC DI
        LOOP PWCMP
    
    JMP CORRECT

    FAILUSR:
        MOV AH, 09H
        LEA DX, FAILU
        INT 21H
        JMP ENDPROG
    
    FAILPW:
        MOV AH, 09H
        LEA DX, FAILS
        INT 21H
        JMP ENDPROG
    
    ; ELSE, DISPLAY SUCCESS
    CORRECT:
        MOV AH, 09H
        LEA DX, SUCCESS
        INT 21H

    ENDPROG:
        MOV AX, 4C00H
        INT 21H
    
    
MAIN ENDP

NEWL PROC
    MOV AH, 09H
    LEA DX, NL
    INT 21H
    RET
NEWL ENDP
END MAIN