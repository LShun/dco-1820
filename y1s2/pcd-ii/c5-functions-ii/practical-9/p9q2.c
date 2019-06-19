/*
Name: p9q2.c
Desc: Demonstrate how global variable works using an example to calculate marks.
*/
#include <stdio.h>
int upgrade (int mgTest, int *cwMark);

int main(void)
{
    int cwMark, mgTest;

    //get cousework mark
    printf("Cousework mark: ");
    scanf(" %2d", &cwMark);

    //if cousework between 40-49
    if (cwMark >= 40 && cwMark <= 49)
    {
        //get make good test score
        printf("Enter make good test mark: ");
        scanf(" %2d", &mgTest);
        //upgrade
        //if upgrade return 1, print new coursework mark
        if (upgrade(mgTest, &cwMark) == 1)
        {
            printf("Your new coursework mark: %d.\n", cwMark);
        }
        else
        {
            printf("Not applicable for upgrade. Your coursework mark: %d.\n", cwMark);
        }
    }
    else {
        printf("Your mark is not applicable for make good test. Your coursework mark: %d.\n", cwMark);
        return 0;
    }
    
    //else print not applicable, print original coursework mark
}
int upgrade (int mgTest, int *cwMark)
{
    if (*cwMark >= 40)//if cousework mark between 40-49
        {
            if (mgTest >= 50)//if make good test > 50
            {   
                //add mgTest/10 to cwMark
                *cwMark += mgTest/10;
                if (*cwMark > 50) //if coursework > 50
                {
                    *cwMark = 50;//set cousework to 50
                }    
                //return 1
                return 1;
            }
            else{
                return 0;
            }
            
        }
    else{
        return 0;
    }
        //else, return 0
    //else, return 0
}

