; t10-challenge-1.0-HOT-TOPIC.asm
; Write a program to determine the number of positive &
; negative numbers in a list

LIST DB 12, 29, -9, 5, -48, 20
MOV SI, 0
MOV CX, 6

L1:
    CMP LIST[SI], 0
    JE L2
    JG L3
    INC CNTN ; > 0
    JMP L2
    L3: INC CNTP ; <0
    L2:
        INC SI
    LOOP L1
    MOV AH, 02H