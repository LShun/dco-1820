; t10-challenge-1.2-HOT-TOPIC.asm
; Write a program to determine the number of positive &
; negative numbers in a list
; The number 0 is used to end the list, which means 
; the size of the integer list is not fixed

LIST DB 12, 29, -9, 5, -48, 20
MOV SI, 0

L1:
    CMP LIST[SI], 0
    JE Display
    JG L3
    INC CNTN ; > 0
    JMP L2
    L3: INC CNTP ; <0
    L2:
        INC SI
    JMP L1

Display: