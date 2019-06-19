/*
Name: p6q1.c
Desc: Produce a table of numbers, their squares and their cubes
*/
#include <stdio.h>

#define T_NUM 10

void displaySquaresCubes(void);

void main()
{
    displaySquaresCubes();
    system("pause");
}

void displaySquaresCubes()
{
    //variables
    int num, square, cube, i;

    //print header
    printf("%-20s%-20s%-20s\n"
           "%-20s%-20s%-20s\n",
           "NUMBER", "SQUARE", "CUBE",
           "------", "------", "------");
    //for T_NUM numbers
    for (num = 0; num < T_NUM; num++)
    {
        //calculate the square
        square = num * num;
        //calculate the cube
        cube = square * num;
        //display the number, square and cube
        printf("%6d", num);
        for(i = 0; i < 14; i++)
        {
            printf(" ");
        }
        printf("%6d", square);
        for(i = 0; i < 14; i++)
        {
            printf(" ");
        }
        printf("%6d\n", cube);
    }
}
