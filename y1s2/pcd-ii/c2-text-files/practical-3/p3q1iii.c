/*
Name: p3q1iii.c
Desc: Read unknown number of integers from a file and write to another file
*/

#include <stdio.h>
#include <stdlib.h>

#define IN_FILE "./numbers.txt"
#define OUT_FILE "./results.txt"

int main(void)
{
    //variables
    FILE *fin, *fout;
    int n, sum = 0, i, tnum = 0;
    double avg;

    //open file for reading, check for error
    fin = fopen(IN_FILE, "r");
    if (fin == NULL)
    {
        printf("Cannot open input file. Check IN_FILE path.\n");
        exit(-1);
    }

    //open file for writing
    fout = fopen(OUT_FILE, "w");
    if (fout == NULL)
    {
        printf("Output file cannot be opened. Check OUT_FILE path.\n");
        exit(-1);
    }

    //repeat till reach EOF
    while (fscanf(fin, "%d", &n) != EOF)
    {
        sum += n;
        tnum++;
    }
        
    //calculate average
    avg = (double) sum / tnum;

    fprintf(fout, "%-8s= %d\n"
                  "%-8s= %f\n", "Sum", sum, "Average", avg);

    //print completion
    printf("Process completed.\n");

    //close the file
    fclose(fin);
    fclose(fout);
}