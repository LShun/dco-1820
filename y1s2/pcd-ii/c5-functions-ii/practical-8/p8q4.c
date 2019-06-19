/*
Name: p8q4.c
Desc: Converts time from seconds to hr, min, sec
*/
//directives
#include <stdio.h>

//declarations
#define HR(seconds) ((seconds)/3600)
#define MIN(seconds) ((seconds)%(3600)/(60))
#define SEC(seconds) ((seconds)%60)

//prototypes
int convertTime(int seconds, int* hr, int* min, int* sec);

int main(void)
{
    //variables
    int seconds, hr, min, sec;

    //ask user to input time
    printf("Enter time in seconds: ");
    scanf("%d", &seconds);

    //convert the time
    convertTime(seconds, &hr, &min, &sec);

    //print the results
    printf("%d seconds = %d hr %d min %d sec", seconds, hr, min, sec);
}

int convertTime(int seconds, int* hr, int* min, int* sec)
{
    *hr = HR(seconds);
    *min = MIN(seconds);
    *sec = SEC(seconds);
    return 0;
}