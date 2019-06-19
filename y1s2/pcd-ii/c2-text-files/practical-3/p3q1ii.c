/*
Name: p3q1ii.c
Desc: Read unknown number of integers from a file
*/

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    //variables
    FILE *fp;
    int n, sum = 0, i, tnum = 0;
    double avg;

    //open file for reading, check for error
    fp = fopen("./numbers.txt", "r");
    if (fp == NULL)
    {
        printf("Cannot open file.\n");
        exit(-1);
    }
    
    //repeat till reach EOF
    while (fscanf(fp, "%d", &n) != EOF)
    {
        sum += n;
        tnum++;
    }
        
    //calculate average
    avg = (double) sum / tnum;
    //display sum & avg
    printf("%-8s= %d\n"
           "%-8s= %f\n", "Sum", sum, "Average", avg);

    //close the file
    fclose(fp);
}