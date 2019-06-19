/*
Name: p5q2ii.c
Desc: Program to add/print products to/from binary to table in the form of "Product Code  Expiry Year  Country"
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define IN_FILE "product.dat"
#define OUT_FILE "product.dat"

typedef struct {
    char code[6];
    int expiryYear;
    char country[25];
}Product;

//prototypes
void addProducts();
void displayProducts();
int productMenu();

int main(void)
{
    //variables
    int choice;

    while(1)
    {
        choice = productMenu();
        switch (choice)
        {
            case 1:
                addProducts();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

void addProducts()
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
        scanf("%4d", &prod.expiryYear);
        rewind(stdin);
        printf("Enter a product's country ( eg: Malaysia ): ");
        scanf("%25[^\n]", &prod.country);
        rewind(stdin);
        //write contents of prod into output file
        fwrite(&prod, sizeof(Product), 1, fp);
    }
    //repeat until stop
    
    //close file stream
    fclose(fp);
    printf("Done.\n");
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
    printf("\n" "< %d products listed >\n\n", listing);

    //close file
    fclose(fp);
}

int productMenu()
{
    //variables
    int choice;
    //display menu
    printf("\t\tProduct Menu\n\n");
    printf("1. Add new product.\n"
           "2. Display product details.\n"
           "3. Exit.\n\n"
           "\tEnter your choice: ");
    //accept user choice
    scanf("%d", &choice);
    rewind(stdin);
    //print a seperator
    printf("\n");
    return choice;
}