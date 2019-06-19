/*
Name: p3q1i.c
Desc: Read specified integers from a file
*/

#include <stdio.h>
#include <stdlib.h>
#define T_NUM 6

int main(void)
{
    //variables
    FILE *fp;
    int n, sum = 0, i;
    double avg;

    //open file for reading, check for error
    fp = fopen("./numbers.txt", "r");
    if (fp == NULL)
    {
        printf("Cannot open file.\n");
        exit(-1);
    }
    
    //repeat 6 times
    for (i = 0; i < T_NUM; i++)
    {
        fscanf(fp, "%d", &n);
        sum += n;
    }
        
    //calculate average
    avg = (double) sum / T_NUM;
    //display sum & avg
    printf("%-8s= %d\n"
           "%-8s= %f\n", "Sum", sum, "Average", avg);

    //close the file
    fclose(fp);
}