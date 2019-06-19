/*
Name: p5q3.c
Desc: Program to add/print products to/from binary to table in the form of "Product Code  Expiry Year  Country". This program also can modify individual entries.
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
void modifyProducts();
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
            modifyProducts();
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
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
    printf("\n" "< %d products listed >\n", listing);

    //close file
    fclose(fp);
}

void modifyProducts()
{
    //variables (some are inherently bad choices due to being one of the question criteria, 
    //Eg: p[20], can you confirm its always less than 20?)
    char pCode[6], changes[25];
    FILE *fp;
    int confirm, pCount, i = 0, match = -1, modifications = 0, selection;
    Product p[20];

    //open IN_FILE for reading
    fp = fopen(IN_FILE, "rb");
    //copy records into arrays, keeping in record of the products read (as a return value)
    pCount = fread(&p, sizeof(Product), 20, fp);
    //close the file
    fclose(fp);
    
    while(1)
    {
        //Find product to modify
        do
        {
            //ask user for product code
            printf("Please enter a product code for modification (Enter XXX to go to menu): ");
            scanf("%s", &pCode);
            if (strcmp(pCode, "XXX") == 0)
            {
                //FINALIZE CHANGES
                //inform user changes made
                printf("Total records modified: %d\n", modifications);

                //open the file
                fp = fopen(OUT_FILE, "wb");
                //check for errors
                if (fp == NULL)
                {
                    printf("Output file cannot be opened. Changes have not been made.\n");
                    exit(-1);
                }

                //copy back array into the file
                fwrite(&p, sizeof(Product), pCount, fp);

                //close the file
                fclose(fp);
                printf("Exiting....\n");
                return;
            }
            match = -1;
            //match it with the product code stored in the array
            for (i = 0; i < pCount; i++)
            {
                if(strcmp(p[i].code, pCode) == 0)
                {
                    printf("Record found.\n");
                    match = i;
                    goto found;
                }
            }
            printf("Record cannot be found.\n");
        }
        while (match == -1);
        
        found:
        //display the required record
        printf( "Product Code: %s\n"
                "Expiry Year\t: %d\n" 
                "Country\t: %s\n",
                p[match].code, p[match].expiryYear, p[match].country);

        
        //Ask what to modify
        printf("Modify: \n"
            "\t1. Expiry Year\n"
            "\t2. Country\n"
            "\t3. Cancel\n"
            "Your choice?: ");
        //get input
        scanf("%d", &selection);
        rewind(stdin);


        //Get Modification
        printf("Enter your changes to overwrite: ");
        scanf("%25[^\n]", &changes);
        rewind(stdin);
        //Confirmation
        printf("This process is irreversible, are you sure to overwrite? (Y/N): ");
        scanf("%c", &confirm);
        rewind(stdin);

        //Perform modification
        if (confirm == 'N')
        {
            printf("Action cancelled, no changes have been made.\n");
            continue;
        }

        if (selection == 1)
        {
            p[match].expiryYear = atoi(changes);
        }
        else
        {
            strcpy(p[match].country, changes);
        }

        //Show updated record
        printf("Modified record:\n"
            "\tNew Product Code: %s\n"
            "\tNew Product Code: %d\n"
            "\tNew Product Code: %s\n", 
            p[match].code, p[match].expiryYear, p[match].country);
        modifications++;
    }
}

int productMenu()
{
    //variables
    int choice;
    //display menu
    printf("\n" "\t\tProduct Menu\n\n");
    printf("1. Add new product.\n"
           "2. Display product details.\n"
           "3. Edit products.\n"
           "4. Exit.\n\n"
           "\tEnter your choice: ");
    //accept user choice
    scanf("%d", &choice);
    rewind(stdin);
    //print a seperator
    printf("\n");
    return choice;
}