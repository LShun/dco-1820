# Tutorial 7 - Procedural Design

## Question 1

```pseudocode
DO Calculation of Vehicle Insurance premium
	Enter make and model of vehicle
	Retrieve insurance premium for this make and model of vehicle
	Display this insurance premium on the screen
	Enter age of applicant
	IF age<25 AND age>60
		Add 10% to basic insurance premium
	ENDDO
Display applicant insurance premium on the screen
ENDDO

```

Standard Error: Line 8, `ENDDO` should be `ENDIF`

Functional Error: Line 6, `IF age < 25 AND age > 60` is never true, no one person can have their age both less than 25 AND more than 60 at the same time, therefore, the condition is always false. Should be `IF age < 25 OR age > 60`

## Question 2

```pseudocode
DO ATM_HANDLE_CUSTOMER

	accept PIN from customer
	tries = 1
	WHILE tries < 3:
		check PIN validity
		IF invalid PIN:
			tries = tries + 1
			Accept retry PIN
		ENDIF
	IF tries > 3:
		confiscate ATM card
		RETURN
	ENDIF
	ENDWHILE
	
	WHILE user clicks continue button
		Provide options to users
	ENDWHILE
	
	Produce Receipt
END
	
	
	
	
		
			
```



## Question 3

### Note: Use half-rule condition

> Basically first, break it into two equal parts
>
> > YYYY NNNN
> >
>
> then break them into 4 parts
>
> > YYNN YYNN
> >
>
> then break them again into another 4 parts
>
> > YNYN YNYN
> >
>
> The end result will be:
>
> > YYYY NNNN
> >
> > YYNN YYNN
> >
> > YNYN YNYN
> >

### Sales Promotion Policy Decision Table

| Condition               | 1    | 2    | 3    | 4    |
| ----------------------- | ---- | ---- | ---- | ---- |
| Is Preferred Customer?  | Y    | Y    | Y    | N    |
| Is Order > RM1000?      | Y    | Y    | N    | -    |
| Is Using a Change Card? | Y    | N    | -    | -    |
| **Action**              |      |      |      |      |
| 5% Discount             |      | X    |      |      |
| 10% Discount            | X    |      |      |      |
| RM25 Coupon             |      |      | X    |      |
| RM 5 Coupon             |      |      |      | X    |



## Question 4

### Hudley Ltd Loyalty Scheme Decision Table

| Conditions                                             | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    |
| ------------------------------------------------------ | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| Pay in advance                                         | Y    | Y    | Y    | Y    | N    | N    | N    | N    |
| Designated key account customer                        | Y    | Y    | N    | N    | Y    | Y    | N    | N    |
| Order > RM1200 in year                                 | Y    | N    | Y    | N    | Y    | N    | Y    | N    |
| **Action**                                             |      |      |      |      |      |      |      |      |
| 5% Discount                                            | X    | X    | X    | X    |      |      |      |      |
| 50 Bonus Points                                        | X    | X    |      |      |      |      |      |      |
| 20 Bonus Points                                        |      |      |      |      | X    | X    |      |      |
| RM10 customer card fee waived                          | X    |      | X    |      | x    |      | X    |      |
| No discount, bonus points, and card fee return (what?) |      |      |      |      |      |      |      | x    |

b) Decision tree is a design tool which provide graphical representation that acts as an alternate way to define complex relationships compared to decision tables.

- Sequential structure of decision tree branches so that the order of checking conditions and executing orders is immediately noticeable.

