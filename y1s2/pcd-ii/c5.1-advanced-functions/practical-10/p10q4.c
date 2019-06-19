/*
Name: p10q4.c
Desc: Calculate amount of time asleep.
*/

#include <stdio.h>

typedef struct {
    int hrs, mins, secs;
} Time;

Time elapsedTime (Time start, Time end);

int main(void)
{
    //variables
    Time start, end, elapsed;

    //Input
    //Prompt user for sleep time start and time end
    printf("Enter time you went to sleep (eg: 11:45:00): ");
    scanf("%2d: %2d: %2d", &start.hrs, &start.mins, &start.secs);
    printf("Enter time you woke up from sleep (eg: 11:45:00): ");
    scanf(" %2d: %2d: %2d", &end.hrs, &end.mins, &end.secs);

    //Process
    //Calculate time elapsed
    elapsed = elapsedTime(start, end);

    //Output
    //Display elapsed time
    printf("Time elapsed during your sleep: %02d:%02d:%02d\n", elapsed.hrs, elapsed.mins, elapsed.secs);
    
    return 0;
}
Time elapsedTime (Time start, Time end)
{
    //variables
    Time elapsed = {0};
    
    //find the seconds passed
    //if ending seconds < starting seconds
    if (end.secs < start.secs)
    {
        //decrease minutes by 1, increase seconds by 60
        elapsed.mins -= 1;
        elapsed.secs += 60;
    }
    //calculate seconds elapsed
    elapsed.secs += (end.secs - start.secs);
        

    //find the minutes passed
    //if ending minutes < starting minutes
    if (end.mins < start.mins)
    {
        //increase minutes by 60, deduct hour by 1
        elapsed.hrs -= 1;
        elapsed.mins += 60;
    }
    //calculate minutes elapsed
    elapsed.mins += (end.mins - start.mins);

    //find the hours passed
    //if starting hours > ending hours
    if (start.hrs > end.hrs)
    {
        //add hours to midnight
        elapsed.hrs += (24 - start.hrs);
        //add time from another day
        elapsed.hrs += end.hrs;
    }
    else
    {
        //deduct ending hours by starting hours
        elapsed.hrs += end.hrs - start.hrs;
    }
    //return back elapsed time.
    return elapsed;
}