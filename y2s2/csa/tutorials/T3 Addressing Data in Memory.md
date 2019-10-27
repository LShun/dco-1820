## T3: Addressing Data in Memory

### 3a)

- Stack segment
- CS
- ES



#### b)

- Similarity and differences between register and RAM
  -  Register and memory, hold the data that can be **directly** accessed by the **processor** which also increases the processing speed of CPU.  
  - RAM use address of register. Register use name to refer.
  - RAM is located in motherboard. Register is inside CPU.
  - Register store in sequence, but not RAM.

### c)

- Absolute address directly refers to the address. But segment:offset adress need to be added.

## Q4

a. 120~8~=50~16~

​	Always store in AL first, if AL full only store in AH

Break AX into a two cell diagram 

Draw a diagram

b.         11112 x 1112 x 112  

AX=1 AL=3B

## Q5

1. a. Use CS and IP. 02B30+0025=02B55
2. b. 09B84H

Remember segment x 10H

## Q6

Show in 20 bits binary

12AD0H

0001 0010 1010 1101 0000

## Q7

1: Convert to bin: 0110 0001 0010 0000

NC, PL, NZ, NV

2. Add AL, AAH
   1. + 1010 1010
      + Total in AL: 1100 1010
      + AX: 0110 0001 1100 1010
   2. NC NG NZ NV
3. ADD AH, FFH
   1. 0110 0001 + 1111 1111 =  **1 0110 0000** 
      1. CY PL NZ NV
4. ADD AX 2
   1. **01100000** + 0000 0010 = **0110 0010**
   2. NC PS NZ NV

