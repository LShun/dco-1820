/*
Name: p5q2i.c
Desc: Print products from binary to table in the form of "Product Code  Expiry Year  Country"
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define IN_FILE "product.dat"

typedef struct {
    char code[6];
    int expiryYear;
    char country[25];
}Product;

//prototypes
void displayProducts();

int main(void)
{
    displayProducts();
}

void displayProducts()
{
    //variables
    FILE *fp;
    Product prod;
    SYSTEMTIME t;
    int listing = 0;

    //open the binary file
    fp = fopen(IN_FILE, "rb");
    //check for errors
    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        exit(-1);
    }

    //get the current time
    GetLocalTime(&t);

    //print title and date
    printf("Product Details - as at %d-%d-%d\n\n", t.wDay, t.wMonth, t.wYear);

    //print table column names
    printf("Product Code   Expiry Year   Country\n"
    //print seperator
           "============   ===========   =======\n");

    //while file not EOF
    while (fread(&prod, sizeof(Product), 1, fp) == 1) //read details from file into structure
    {
        //print details
        printf("  %-10s     %-9d   %-25s\n", prod.code, prod.expiryYear, prod.country);

        //increase total listing
        listing++;
    }

    //print total product listed
    printf("\n" "< %d products listed >\n", listing);

    //close file
    fclose(fp);
}