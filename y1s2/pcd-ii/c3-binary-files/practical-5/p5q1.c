/*
Name: p5q1.c
Desc: Write product details to binary file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OUT_FILE "product.dat"

typedef struct {
    char code[6];
    int expiryYear;
    char country[25];
}Product;

int main(void)
{
    //variables
    FILE *fp;
    Product prod;
    int counter;

    //create a binary .dat file to store the products ( append )
    fp = fopen(OUT_FILE, "ab");
    //check file
    if (fp == NULL)
    {
        printf("Cannot open file for appending.\n");
        exit(-1);
    }

    //request product details from user
    while(1)
    {
        printf("Enter a new 5-characters product code (key in XXX to stop): ");
        scanf("%5s", &prod.code);
        rewind(stdin);
        //check if stop
        if (strcmp(prod.code, "XXX") == 0)
        {
            break;
        }
        printf("Enter product's expiry year ( eg: 2001 ): ");
        scanf("%d", &prod.expiryYear);
        rewind(stdin);
        printf("Enter a product's country ( eg: Malaysia ): ");
        scanf("%[^\n]", &prod.country);
        rewind(stdin);
        //write contents of prod into output file
        fwrite(&prod, sizeof(Product), 1, fp);
    }
    //repeat until stop
    
    //close file stream
    fclose(fp);
    printf("Done.\n");
}