# Chapter 2: Representing Numerical Data

## 0. Exam Tips

- Exam DO NOT cover Unsigned Binary & BCD
- 1's complement will not come out
- Exam will come out 2's complement

## 1. Unsigned Binary & BCD

Two approaches to represent them.

- Conventional binary representation
- Binary-coded decimal (BCD) representation

### Conventional binary representation

- Direct binary equivalent for decimal integers
- Eg: 2~10~ = 10~2~

### Binary coded decimal representation

- Digit-by-digit
- Eg: 10~10~ = 1 0~10~ = 0001 0000~2~
- 4 bits per digit for decimal

## 2. Signed Integers Representation

### Sign and magnitude representation

- Leftmost bit for sign
- `0` for positive, `1` for negative

### 1's Complement

- Uses the complement to represent negative values
- `0000` to `0111` is positive, hence, `1111` to `1000` is negative
- Consequence: 
  - 2 values to represent `0`. `0000` and `1000` are zeroes of `+0` and `-0` 
    - Requires 'carry-bit' to fix

### 2's complement

- Simply is 1's complement + 1 (include carry bit).
- Eliminates problem of 2 zeroes.

#### 2's complement - explained

- Reddit, @Ocean_Ghost,  https://www.reddit.com/r/learnprogramming/comments/2g0auz/why_does_the_flip_the_bits_and_add_1_twos/

### 1's Complement vs 2's Complement

| 1's Complement                     | 2's Complement                       |
| ---------------------------------- | ------------------------------------ |
| Need to 'carry bit' after addition | Needs `+1` for every negative number |
| Must test and convert `-0`         |                                      |

### Overflow Flag (OF)

- When result of arithmetic does not fit in bits available
- Detected: Sign of result is opposite of both operands

### Carry Flag (CF)

- When result exceed bit available, disregarding sign
- Detected: 1 extra bit generated
- Ignored: Caused by sign bit, does not affect result if OF 
- A good way to imagine is:
  - For -2~10~  = 1111 1110~2~
  - The only digits involved to make 2~10~ are the last `10` in XXXX XX10~2~. 
  - The rest of the `1`'s , 1111 11XX~2~ are considered 'sign bit'. So in this case, the number -2~10~ has 6 sign bits.
  - A negative number needs AT LEAST 1 sign bit (that is, a `1` in the beginning).
  - As the number increases, the number of sign bits available decreases. They are 'pushed out' in calculations.
  - Since the 'extra' sign bits do not contribute to the overall result, they doesn't matter if they are 'pushed out', unless the last sign bit is 'pushed out'.

## 3. Floating Point Number (AKA FPs)

- Real number

- Used when:

  - Number too large/small
  - Contains **decimal** fraction
    - Binary fractions still can use normal binary representations up to certain extent (see later).

- Exponential notation

  - AKA Scientific Notation, always in the form of:
    $$
    Number * base^{exponent}
    $$

- Specifications for real number, combination of:

  - Mantissa part
    - Sign
    - Location of decimal point
    - Mantissa
  - Base-and-exponent part
    - Base
    - Exponent
      - Sign
      - Exponent

### 8-bit "[minifloat](https://en.wikipedia.org/wiki/Minifloat)" specification

$$
SEEMMMMM
$$

- S = sign

- E = exponent

- M = Mantissa

- **Excess-N notation**: N is the chosen middle value. More = positive. Less = negative. N = 0
- For signs, 0 represent '+', negative is other than '0' (but usually we use the highest digit, say Excess-50 we will use '50')

### Normalization & Formatting

- Normalization: Shift left until leading zeroes are eliminated
- Steps to convert
  - Change into **scientific notation**
  - **Shift decimal point to correct place**
  - Decrease exponent on mantissa to **eliminate leading zeroes**
  - Correct precision

### Add & Subtract

- Treat exponent and mantissa separately
- Both must be in same exponent (usually shift to higher one, easier)
- Overflow: Increment exponent and shift right.

### Multiply & Divide

- Mantissa: Multiplied/divided (without shifting)

- Exponents: Add/Subtract

  - If using excess-N, then subtract N from final result
    $$
    N=50\\
    a=5+N\\
    b=10+N\\
    a+b=5+N+10+N\\
    a+b=15+2N\\
    a+b-N=15+2N-N\\
    a+b=15+N
    $$

### Fractional numbers

- Repeatedly divide by 2, and take the remainder from bottom-up
- Base 2 to Base 16: Group 4 digits together and form one Hex digit.

### IEEE 754 FP

| Precision    | Single (32bit) - bits | Double (64bit) - bits |
| ------------ | --------------------- | --------------------- |
| Sign         | 1                     | 1                     |
| Exponent     | 8                     | 11                    |
| Notation     | Excess-127            | Excess-1023           |
| Implied Base | 2                     | 2                     |
| Range        | 2^-126^-2^127^        | 2^-1022^-2^1023^      |
| Mantissa     | 23                    | 52                    |

#### Convert decimal to binary

Example: 253.75~10~

1. Convert to binary (note that decimal places are 2^-1^, 2^-2^ ...)
   $$
   253.75=11111101.11
   $$

2. Add exponent
   $$
   11111101.11 * 2^0
   $$

3. Position decimal points
   $$
   1.111110111 * 2^7
   $$
   
4. Exponent
   $$
   127+7=134
   $$

5. Change to binary
   $$
   10000110
   $$

6. Sign of mantissa
   $$
   0 (positive)
   $$
   
7. Mantissa in 23 bits (Note, can use ... to represent trailing zeroes)
   $$
   11111011\quad1...
   $$
   
8. IEEE 754 format:
   $$
   0\quad10000110\quad11111011\quad1...
   $$
   

