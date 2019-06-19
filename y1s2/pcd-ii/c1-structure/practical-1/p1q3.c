/*
Name: p1q3.c
Desc: Finds the next minute in a 12-hour format
*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int hours;
    int minutes;
} Time;

int validate(Time *current);
void nextMinute(Time *current, Time *nextMin);

int main(void)
{
    Time current, nextMin;

    //input
    do
    {
        printf("Enter the current hour and minute (eg: 12 40): ");
        scanf("%d %d", &current.hours, &current.minutes);
    }
    while (validate(&current) == FALSE);
    
    //calculate nextMin
    nextMinute(&current, &nextMin);

    printf("It is now %02d:%02d. Next minute it will be %02d:%02d\n", current.hours, current.minutes, nextMin.hours, nextMin.minutes);
}

int validate(Time *current)
{
    //validate hours
    //check if within specific range
    if (current->hours < 0 || current->hours > 24)
    {
        printf("Invalid hour.\n");
        return FALSE;
    }
    //validate minutes
    //check if whithin specific range
    else if (current->minutes < 0 || current->minutes > 60)
    {
        printf("Invalid minutes.\n");
        return FALSE;
    }
}

void nextMinute(Time *current, Time *nextMin)
{
    //store hours to next time
    nextMin->hours = current->hours;

    //add 1 minute to current time, store it in nextMin structure
    nextMin->minutes = current->minutes+1;

    if (nextMin->minutes == 60)
    {
        nextMin->hours++; //increase hour by 1
        nextMin->minutes = 0; //set minute to zero
    }
    if (nextMin->hours > 12) //if hours more than 12
        nextMin->hours -= 12; //set from AM/PM to PM/AM
}