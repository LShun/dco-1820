/*
Name: p10q2.c
Desc: Convert day in numbers to words.
*/

#include <stdio.h>
#include <string.h>
//prototypes

int convertDay(int day, char *dayName);

int main(void)
{
    char dayName[20], tmr[20];
    int day;

    printf("Enter today's day (1-7): ");
    scanf("%d", &day);
    if (convertDay(day, dayName) == 1)
    {
        convertDay((day + 1) % 7, tmr);
        printf("Today is %s, tomorrow will be %s\n", dayName, tmr);
    }
    else
        printf("Error in conversion - Invalid Day.\n");
}

int convertDay(int day, char *dayName)
{
    switch (day)
    {
        case 1: strcpy(dayName, "Monday");    break;
        case 2: strcpy(dayName, "Tuesday");   break;
        case 3: strcpy(dayName, "Wednesday"); break;
        case 4: strcpy(dayName, "Thursday");  break;
        case 5: strcpy(dayName, "Friday");    break;
        case 6: strcpy(dayName, "Saturday");  break;
        case 7: strcpy(dayName, "Sunday");    break;
        default: return 0;
    }
    return 1;
}