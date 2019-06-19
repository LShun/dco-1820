/*
Name: p10q1.c
Desc: Stores and display integer array contents and total.
*/

#include <stdio.h>
#define INTEGERS 4

void printArray(char arrName[], int arr[], int size);
int totalArray(const int arr[], int size);
void getArray(int arr[], int size);

int main(void)
{
    //variables
    int myArray[10], total;

    //prompt for user input
    getArray(myArray, INTEGERS);
    
    //calculate total
    total = totalArray(myArray, INTEGERS);
    
    //display the contents of array
    printArray("Array\n", myArray, INTEGERS);
    //print total
    printf("Total: %d\n", total);
    return 0;
}

//print the array
void printArray(char arrName[], int arr[], int size)
{
    //variables
    int i, total;
    //display arrName[]
    printf("Name: %s\n", arrName);
    //display contents of arr
    printf("Contents: ");
    //loop through size   
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//return the total array elements
int totalArray(const int arr[], int size)
{
    //variables
    int total = 0, i;

    //loop through the array until "size" amount
    for (i = 0; i < size; i++)
    {
        //add the numbers together
        total += arr[i];
    }
    //return the total
    return total;
}

void getArray(int arr[], int size)
{
    //variables
    int i;
    
    //for "size" times
    for (i = 0; i < size; i++)
    {
        //prompt user for an integer
        printf("Enter the %d/%d number: ", i+1, size);
        scanf(" %d", &arr[i]);
    }
}