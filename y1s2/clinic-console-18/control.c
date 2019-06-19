#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

void homescreen(void);
void header(char title[]);

int main()
{
	int choice;

	do
	{
		system("cls");
		homescreen();
		header("MAIN MENU");

		printf("%20c%s", ' ', "1. Patient Info\n");
		printf("%20c%s", ' ', "2. Staff Info\n");
		printf("%20c%s", ' ', "3. Appointments\n");
		printf("%20c%s", ' ', "4. Medical Supplies\n");
		printf("%20c%s", ' ', "5. Exit\n");

		printf("%20c%s", ' ', "Enter choice:");
		scanf("%d", &choice);
		rewind(stdin);

		system("cls");

		switch(choice)
		{
			case 1:	patientInfo();					break;
			case 2: staffInfo();					break;
			case 3:	appointments();					break;
			case 4:	medicalSupplies(); 				break;
			case 5:									break;
			default: header("Invalid choice");
					 system("pause");
		}
	} while (choice != 5);
	homescreen();
	header("Bye bye!");

	system("pause");
}