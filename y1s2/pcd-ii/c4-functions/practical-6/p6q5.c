/*
Name: p6q5.c
Desc: Validates a person's mark
*/

#include <stdio.h>

#define MIN_MARK 0
#define MAX_MARK 100

int getValidMark();

int main(void)
{
    int mark;
    mark = getValidMark();
}

int getValidMark()
{
    //variables
    int mark;
    //ask for valid mark
    printf("Enter a mark between %d and %d: ", MIN_MARK, MAX_MARK);
    scanf("%d", &mark);
    rewind(stdin);

    //validate mark
    while (1)
    {
        if (mark >= MIN_MARK && mark <= MAX_MARK)
            return mark;
        else
        {
            
            printf("Invalid mark.\n"
                   "Enter a mark between %d and %d: ", MIN_MARK, MAX_MARK);
            scanf("%d", &mark);
            rewind(stdin);
        }
    }

    
}