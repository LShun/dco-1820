1. How to open the debug program?

   ```assembly
   Open DOSBox,
   mount [driveLetter]: path\to\8086\
   
   Type `debug`
   ```

2. Which DEBUG command performs the following operations?
  a) Display the contents of registers after the execution.
  b) Begin assembling statements that will be converted to machine language.
  c) Display machine code for assembly instructions entered.
  d) Enter machine instructions into memory.
  e) To display the content of all the registers.
  f) To quit the DEBUG session.

3. Use DEBUG to enter the following commands:
  a 100
  mov cl, 42
  mov dl,2a
  add cl,dl
  jmp 100
  What you can see when the following command is typed?
  a) u 100,107
  b) d cs:100
  c) e cs:100 a1 00 02 03 06 02 02
  d) u 100,106

4. What you can see when the following command is typed?AACS3064 COMPUTER SYSTEMS ARCHITECTURE
  2
  a) abc0 0fff
  b) 0000 1111

5. Use DEBUG to enter the following commands:
  a 100
  mov ax,0123
  add ax,0025
  mov bx,ax
  add bx,ax
  mov cx,bx
  sub cx,ax
  sub ax,ax
  jmp 100
  What you can see when the following command is typed?
  a) r
  b) t (repeat 7 times)
  What is the command to run 7 lines starting from the address 100?

6. Use DEBUG to enter the following command:
  E CS:100 B8 45 01 05 25 00 The hexadecimal value 45 was supposed to be

7. Code another E command to correct only the one byte that is incorrect,
   that is change 45 to 54 directly.

8. Assume that you have used DEBUG to enter the following E command:
  E CS:100 B8 05 1B 00 2C EB F8
  What are the three symbolic instruction represented here?