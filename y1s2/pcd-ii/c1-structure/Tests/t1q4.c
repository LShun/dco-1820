#include <stdio.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

int main(void)
{
    Date mfgDate = {17, 10, 2016}, expiryDate;
    printf("%d-%d-%d\n", mfgDate.day, mfgDate.month, mfgDate.year);
    printf("%d-", mfgDate.day);
    switch(mfgDate.month)
    {
    case 1:
        printf("JAN-");
        break;
    case 2:
        printf("FEB-");
        break;
    case 3:
        printf("MAR-");
        break;
    case 4:
        printf("APR-");
        break;
    case 5:
        printf("MAY-");
        break;
    case 6:
        printf("JUN-");
        break;
    case 7:
        printf("JUL-");
        break;
    case 8:
        printf("AUG-");
        break;
    case 9:
        printf("SEP-");
        break;
    case 10:
        printf("OCT-");
        break;
    case 11:
        printf("NOV-");
        break;
    case 12:
        printf("DEC-");
        break;
    }
    printf("%d\n", mfgDate.year);
    expiryDate = mfgDate;
    expiryDate.year = mfgDate.year + 5;
    printf("MFG %d %d %d\n", mfgDate.day, mfgDate.month, mfgDate.year);
    printf("EXP %d %d %d\n", expiryDate.day, expiryDate.month, expiryDate.year);  
}