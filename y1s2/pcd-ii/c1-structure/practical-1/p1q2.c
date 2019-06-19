/*
Name: p1q2.c
Desc: Single-book simple inventory management program for bookshop
*/

#include <stdio.h>

typedef struct {
    char id[10];
    char author[30];
    char title[60];
    char publisher[20];
    int year;
    int stock;
} BookInventory;

struct Transactions {
    char transactionCode; // ('S' = sold, 'P' = purchased)
    int quantity;         // (quantity sold/purchased, eg. 2)
};

//prototypes
void displayBook(BookInventory *book);
void process(BookInventory *book, struct Transactions *txn);

int main(void)
{
    //variables
    BookInventory book = {"BK-2044", "JK Rowling", "Harry Potter and the Prisoner of Azkaban", "Bloomsbury", 1999, 25};
    struct Transactions txn;

    //display book details
    displayBook(&book);

    //obtain transaction details from user
    do process(&book, &txn);
    while (txn.transactionCode != 'X');
}

void displayBook(BookInventory *book)
{
    printf("Book Details:\n"
            "=============\n"
            "Book ID\t\t\t:%s\n"
            "Author Name\t\t:%s\n"
            "Book Title\t\t:%s\n"
            "Publisher\t\t:%s\n"
            "Year of Publication\t:%d\n"
            "Quantity in Stock\t:%d\n",
            book->id, book->author, book->title, book->publisher, book->year, book->stock); 
}

void process(BookInventory *book, struct Transactions *txn)
{
    printf("Enter Transaction Code (S=sold, P=purchased, X=exit): ");
    txn->transactionCode = getchar();
    rewind(stdin);

    //carry out transaction
    switch(txn->transactionCode)
    {
        case 'S':
            printf("Transaction Quantity: ");
            scanf("%d", &txn->quantity);
            rewind(stdin);
            book->stock -= txn->quantity;
            printf("Sold\t: %d copies of \"%s\" by %s\n" 
                   "There are now %d copies in stock.\n", txn->quantity, book->title, book->author, book->stock);
            break;
        case 'P':
            printf("Transaction Quantity: ");
            scanf("%d", &txn->quantity);
            rewind(stdin);
            book->stock += txn->quantity;
            printf("Purchased\t: %d copies of \"%s\" by %s\n" 
                   "There are now %d copies in stock.\n", txn->quantity, book->title, book->author, book->stock);
            break;
        case 'X':
            printf("Exited - End of Transactions.\n");
            return;
        default:
            printf("Invalid transaction code!\n");
    }
}