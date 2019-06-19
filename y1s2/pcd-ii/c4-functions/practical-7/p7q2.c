/* 
Name: p7q2.c
Desc: Prints the corresponding date of the week
 */

//directives
#include <stdio.h>

//prototypes
void dayOfWeek(int day);

int main(void)
{
    //variables
    int day;

    printf("Enter a day (0-6): ");
    scanf("%d", &day);
    while (day < 0 || day > 6)
    {
        printf("Invalid day, please enter again: ");
        scanf("%d", &day);
    }
    dayOfWeek(day);
}

//definitions
void dayOfWeek(int day)
{
    switch(day)
    {
        case 0:     printf("Sunday.\n");    break;
        case 1:     printf("Monday.\n");    break;
        case 2:     printf("Tuesday.\n");   break;
        case 3:     printf("Wednesday.\n"); break;
        case 4:     printf("Thursday.\n");  break;
        case 5:     printf("Friday.\n");    break;
        case 6:     printf("Saturday.\n");  break;
    }
}