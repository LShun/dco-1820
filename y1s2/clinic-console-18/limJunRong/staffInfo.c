/*<Staff Information Module>
Name           : Lim Jun Rong
Student ID     : 18WMD04952
Course Name    : Diploma In Science (Computer Science and Computer Mathematics)
Tutorial Group : 5
Purpose        : To store the information of medical staff, i.e doctor, nurse and pharmacist
*/


#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<Windows.h>
#pragma warning(disable:4996)


//Structures
struct DateEmployed
{
	int day;
	int month;
	int year;
};

typedef struct
{
	char name[100];
	char gender;
	char identityCardNo[15];

}Identification;

typedef struct
{
	//Data field
	char staffId[100];
	char designation[100];
	Identification id; //Nested structure
	struct DateEmployed date;  //Nested structure
	int workingExperience;
	char qualifications[100];
	char phoneNo[15];
	double salary;

}StaffInformation;


int mainMenu(void);
void addRecord(void);
void searchRecord(void);
void modifyRecord(void);
void displayExistingRecord(void);
void removeRecord(void);
int getValidDate(int day, int month, int year);
void homescreen(void);
void header(void);
void displayRemoveRecord(void);
int calWorkingExperience(int tempYear);

void staffInfo(void)
{
	//Variables declaration
	int choice;

	//Function call-mainMenu()
	choice = mainMenu();

	do
	{
		system("cls");

		if (choice == 1)
		{
			displayExistingRecord();

			system("pause");
			system("cls");

			choice = mainMenu();
		}

		else if (choice == 2)
		{
			addRecord();

			system("pause");
			system("cls");

			choice = mainMenu();
		}

		else if (choice == 3)
		{
			searchRecord();

			system("pause");
			system("cls");

			choice = mainMenu();
		}

		else if (choice == 4)
		{
			modifyRecord();

			system("pause");
			system("cls");

			choice = mainMenu();
		}

		else if (choice == 5)
		{
			removeRecord();

			system("pause");
			system("cls");

			choice = mainMenu();
		}

		else if (choice == 6)
		{
			displayRemoveRecord();

			system("pause");
			system("cls");

			choice = mainMenu();
		}

		else if (choice != 7)
		{
			printf("Error! Please enter again\n\n");

			system("pause");
			system("cls");

			choice = mainMenu();
		}

		printf("\n\n");

	} while (choice != 7);

	system("pause");
}


int mainMenu(void) //To allow the user to perform any of the transaction
{
	//Local Variables declaration 
	int selection;

	//Display homescreen
	homescreen();

	//Display menu
	header("Staff Information Module");

	printf("%20s%s\n", " ", "1. Display Existing Staff Record");
	printf("%20s%s\n", " ", "2. Add Staff Record");
	printf("%20s%s\n", " ", "3. Search Staff Record");
	printf("%20s%s\n", " ", "4. Modify Staff Record");
	printf("%20s%s\n", " ", "5. Remove Staff Record");
	printf("%20s%s\n", " ", "6. Display Removed Staff Record");
	printf("%20s%s\n\n", " ", "7. Exit");

	//Input
	printf("%20s%s", " ", "Enter your selection : ");
	scanf("%d", &selection);
	rewind(stdin);

	return selection;
}


void addRecord(void)  //To add new record of staff
{
	//Variables declaration
	FILE *fPointer;
	StaffInformation staff;
	int valid;

	//Open file for appending mode
	fPointer = fopen("StaffInfo.txt", "a");
	if (fPointer == NULL)
	{
		printf("File cannot be opened!!!\n");
		system("pause");
		exit(-1);
	}

	//Append information into the file
	printf("D-Doctor, N-Nurse, P-Pharmacist\n");
	printf("Enter 4-character staff ID (XXX to stop) [E.g D123]: ");
	rewind(stdin);
	scanf("%4s", staff.staffId);

	while (strcmp(staff.staffId, "XXX") != 0)  //Stop adding new record when user enter XXX
	{
		printf("Enter designation : ");
		rewind(stdin);
		scanf("%s", staff.designation);
		printf("Enter name : ");
		rewind(stdin);
		scanf("%[^\n]", staff.id.name);

		printf("Enter gender [E.g M or F]: ");
		rewind(stdin);
		scanf("%c", &staff.id.gender);

		while (staff.id.gender != 'M'&&staff.id.gender != 'F')
		{
			printf("Invalid gender!!! Please enter again\n");

			printf("Enter gender : ");
			rewind(stdin);
			scanf("%c", &staff.id.gender);
		}

		printf("Enter identification card No (with '-') : ");
		rewind(stdin);
		scanf("%14s", staff.id.identityCardNo);

		do
		{
			printf("Enter date of employed (DD MM YYYY) : ");
			rewind(stdin);
			scanf("%d %d %d", &staff.date.day, &staff.date.month, &staff.date.year);

			valid = getValidDate(staff.date.day, staff.date.month, staff.date.year);

			if (valid == 0)
				printf("Please enter valid date!\n");

		} while (valid == 0);
		
		printf("Enter qualification : ");
		rewind(stdin);
		scanf("%[^\n]", staff.qualifications);

		printf("Enter phone number (with '-') : ");
		rewind(stdin);
		scanf("%14s", &staff.phoneNo);

		printf("Enter salary : ");
		rewind(stdin);
		scanf("%lf", &staff.salary);

		fprintf(fPointer, "%s|%s|%s|%c|%s|%d/%d/%d|%s|%s|%.2f\n", staff.staffId, staff.designation, staff.id.name, staff.id.gender, staff.id.identityCardNo, staff.date.day, staff.date.month, staff.date.year, staff.qualifications, staff.phoneNo, staff.salary);
		printf("\n\n");
		printf("Done adding\n");
		printf("\n\n");

		printf("D-Doctor, N-Nurse, P-Pharmacist\n");
		printf("Enter staff ID (XXX to stop) : ");
		rewind(stdin);
		scanf("%s", staff.staffId);

	}


	fclose(fPointer);

}


void displayExistingRecord(void)  //To display all the record of existing staff
{
	//Variables declaration
	FILE *fPointer;
	struct DateEmployed date;
	StaffInformation staff;
	int i = 0;
	int choice;
	SYSTEMTIME t;

	GetLocalTime(&t);

	//Open file for reading mode
	fPointer = fopen("StaffInfo.txt", "r");

	//Check for file's existency
	if (fPointer == NULL)
	{
		printf("File cannot be opened!!!\n");
		system("pause");
		exit(-1);
	}
	printf("Viewed by : %d/%d/%d %02d:%02d\n", t.wDay, t.wMonth, t.wYear, t.wHour, t.wMinute);

	printf("+------------+--------------+---------------------------+----------+\n");
	printf("|%12s|%14s|%27s|%10s|\n", "Staff ID", "Designation", "Name", "Gender");
	printf("+------------+--------------+---------------------------+----------+\n");

	//Read contents from StaffInfo.txt (text file)
	while (fscanf(fPointer, "%[^|]|%[^|]|%[^|]|%c|%[^|]|%d/%d/%d|%[^|]|%[^|]|%lf\n", staff.staffId, staff.designation, staff.id.name, &staff.id.gender, staff.id.identityCardNo, &staff.date.day, &staff.date.month, &staff.date.year, staff.qualifications, staff.phoneNo, &staff.salary) != EOF)
	{
		if (staff.id.gender == 'M')
		{
			printf("|%12s|%14s|%27s|", staff.staffId, staff.designation, staff.id.name);
			printf("%10s|\n", "Male");

		}


		else
		{
			printf("|%12s|%14s|%27s|", staff.staffId, staff.designation, staff.id.name);
			printf("%10s|\n", "Female");
		}

		i++;
	}
	printf("+------------+--------------+---------------------------+----------+\n");
} 


void modifyRecord(void) //To modify the personal information of staff
{
	//Variables declaration
	FILE *fPointer;
	StaffInformation s1[20];
	int nStaff = 0, i = 0;
	int found = 0, choice;
	char inputId[5];
	char response;
	int valid;

	//Open file for reading mode
	fPointer = fopen("StaffInfo.txt", "r");

	//Check for file's existency
	if (fPointer == NULL)
	{
		printf("File cannot be opened!!!\n");
		system("pause");
		exit(-1);
	}

	while (fscanf(fPointer, "%[^|]|%[^|]|%[^|]|%c|%[^|]|%d/%d/%d|%[^|]|%[^|]|%lf\n", s1[i].staffId, s1[i].designation, s1[i].id.name, &s1[i].id.gender, s1[i].id.identityCardNo, &s1[i].date.day, &s1[i].date.month, &s1[i].date.year, s1[i].qualifications, s1[i].phoneNo, &s1[i].salary) != EOF)
	{
		nStaff++;
		i++;
	}

	fclose(fPointer);

	displayExistingRecord();

	do
	{
		printf("Enter staff ID for modification (XXX to stop) :");
		scanf("%4s", inputId);

		rewind(stdin);

		for (i = 0; i < nStaff && !found; i++)
		{
			if (strcmp(inputId, "XXX") == 0)
				found = -1; // Exit from the function when user enter XXX

			else if (strcmp(inputId, s1[i].staffId) == 0)
			{
				printf("Record found >\n");
				printf("\t%-30s:%30s\n", "Staff ID", s1[i].staffId);
				printf("\t%-30s:%30s\n", "Designation", s1[i].designation);
				printf("\t%-30s:%30s\n", "Staff Name", s1[i].id.name);
				printf("\t%-30s", "Gender");

				if (s1[i].id.gender == 'M')
					printf(":%30s\n", "Male");

				else
					printf(":%30s\n", "Female");

				printf("\t%-30s:%30s\n", "Identification Card No", s1[i].id.identityCardNo);
				printf("\t%-30s:%20s%02d/%02d/%d\n", "Employed Date", " ", s1[i].date.day, s1[i].date.month, s1[i].date.year);

				s1[i].workingExperience = calWorkingExperience(s1[i].date.year);

				printf("\t%-30s:%30d\n", "Working Experience", s1[i].workingExperience);
				printf("\t%-30s:%30s\n", "Qualifications", s1[i].qualifications);
				printf("\t%-30s:%30s\n", "Phone Number", s1[i].phoneNo);
				printf("\t%-30s:%20sRM %.2f\n", "Salary", " ", s1[i].salary);
				do
				{

					printf("Sure to modify (Y=Yes) ? ");
					rewind(stdin);
					scanf("%c", &response);
					rewind(stdin);

					response = toupper(response);

					if (response == 'Y')
					{


						do
						{
							system("cls");
							printf("Record found>\n");
							printf("\t%-30s:%30s\n", "Staff ID", s1[i].staffId);
							printf("\t%-30s:%30s\n", "Designation", s1[i].designation);
							printf("\t%-30s:%30s\n", "Staff Name", s1[i].id.name);
							printf("\t%-30s", "Gender");

							if (s1[i].id.gender == 'M')
								printf(":%30s\n", "Male");

							else
								printf(":%30s\n", "Female");

							printf("\t%-30s:%30s\n", "Identification Card No", s1[i].id.identityCardNo);
							printf("\t%-30s:%20s%02d/%02d/%d\n", "Employed Date", " ", s1[i].date.day, s1[i].date.month, s1[i].date.year);

							s1[i].workingExperience = calWorkingExperience(s1[i].date.year);
							printf("\t%-30s:%30d\n", "Working Experience", s1[i].workingExperience);
							printf("\t%-30s:%30s\n", "Qualifications", s1[i].qualifications);
							printf("\t%-30s:%30s\n", "Phone Number", s1[i].phoneNo);
							printf("\t%-30s:%20sRM %.2f\n", "Salary", " ", s1[i].salary);

							printf("\n\n");

							printf("MODIFICATION\n");
							printf("------------\n");
							printf("1. Identification Card No\n");
							printf("2. Employed Date\n");
							printf("3. Qualifications\n");
							printf("4. Phone Number\n");
							printf("5. Salary\n");
							printf("6. Exit\n");

							printf("Enter the number for modification :");
							scanf("%d", &choice);

							if (choice == 1)
							{
								printf("Enter new identification card No (with '-') : ");
								rewind(stdin);
								scanf("%s", &s1[i].id.identityCardNo);
							}

							else if (choice == 2)
							{
								do
								{
									printf("Enter new employed date (DD MM YYYY) : ");
									rewind(stdin);
									scanf("%d %d %d", &s1[i].date.day, &s1[i].date.month, &s1[i].date.year);

									valid = getValidDate(s1[i].date.day, s1[i].date.month, s1[i].date.year);

									if (valid == 0)
										printf("Please enter valid date!\n");

								} while (valid == 0);

							}

							else if (choice == 3)
							{
								printf("Enter new qualifications : ");
								rewind(stdin);
								scanf("%[^\n]", s1[i].qualifications);
							}


							else if (choice == 4)
							{
								printf("Enter new phone number (with '-') : ");
								rewind(stdin);
								scanf("%s", s1[i].phoneNo);
							}

							else if (choice == 5)
							{
								printf("Enter new salary : ");
								rewind(stdin);
								scanf("%lf", &s1[i].salary);
							}

							else if (choice != 6)
							{
								printf("Error please enter again!!!\n");
							}

						} while (choice != 6);

					}

					else if (response != 'N')
					{
						printf("You can only enter Y or N!!!\n");
					}

				} while (response != 'Y' && response != 'N');

				found = 1;
			}

			else
				found = 0;

		}

		if (found == 0)
		{
			printf("Record not found! Please enter again\n");
		}

	} while (found == 0);

	fclose(fPointer);

	//Open file for writing mode
	fPointer = fopen("StaffInfo.txt", "w");

	//Check for file's existency
	if (fPointer == NULL)
	{
		printf("File cannot be opened!!!\n");
		system("pause");
		exit(-1);
	}

	for (i = 0; i < nStaff; i++)
	{
		fprintf(fPointer, "%s|%s|%s|%c|%s|%d/%d/%d|%s|%s|%.2f\n", s1[i].staffId, s1[i].designation, s1[i].id.name, s1[i].id.gender, s1[i].id.identityCardNo, s1[i].date.day, s1[i].date.month, s1[i].date.year, s1[i].qualifications, s1[i].phoneNo, s1[i].salary);
	}

	printf("\n");

	fclose(fPointer);
}


void searchRecord(void) //To search the record of particular staff
{
	//Local Variables Declaration
	FILE *fPtr;
	char searchId[5];
	int i = 0, nStaff = 0;
	int found = 0;
	StaffInformation sRec[20];

	//Open file
	fPtr = fopen("StaffInfo.txt", "r");

	//Check file existency
	if (fPtr == NULL)
	{
		printf("File cannot be opened!!!\n");
		system("pause");
		exit(-1);
	}

	while (fscanf(fPtr, "%[^|]|%[^|]|%[^|]|%c|%[^|]|%d/%d/%d|%[^|]|%[^|]|%lf\n", sRec[i].staffId, sRec[i].designation, sRec[i].id.name, &sRec[i].id.gender, sRec[i].id.identityCardNo, &sRec[i].date.day, &sRec[i].date.month, &sRec[i].date.year, sRec[i].qualifications, sRec[i].phoneNo, &sRec[i].salary) != EOF)
	{
		nStaff++;
		i++;
	}

	fclose(fPtr);

	displayExistingRecord();
	do
	{
		printf("Enter ID to search (XXX to stop) :");
		scanf("%4s", searchId);

		rewind(stdin);

		for (i = 0; i < nStaff && !found; i++)
		{
			if (strcmp(searchId, "XXX") == 0)
			{
				found = -1; //Exit from the function when user enter XXX
			}

			else if (strcmp(searchId, sRec[i].staffId) == 0)
			{
				printf("\n");
				printf("\t%-30s:%30s\n", "Staff ID", sRec[i].staffId);
				printf("\t%-30s:%30s\n", "Designation", sRec[i].designation);
				printf("\t%-30s:%30s\n", "Staff Name", sRec[i].id.name);
				printf("\t%-30s", "Gender");

				if (sRec[i].id.gender == 'M')
					printf(":%30s\n", "Male");

				else
					printf(":%30s\n", "Female");

				printf("\t%-30s:%30s\n", "Identification Card No", sRec[i].id.identityCardNo);
				printf("\t%-30s:%20s%02d/%02d/%d\n", "Employed Date", " ", sRec[i].date.day, sRec[i].date.month, sRec[i].date.year);

				//Process
				sRec[i].workingExperience = calWorkingExperience(sRec[i].date.year);

				printf("\t%-30s:%30d\n", "Working Experience (years)", sRec[i].workingExperience);
				printf("\t%-30s:%30s\n", "Qualifications", sRec[i].qualifications);
				printf("\t%-30s:%30s\n", "Phone Number", sRec[i].phoneNo);
				printf("\t%-30s:%20sRM %.2f\n", "Salary", " ", sRec[i].salary);

				found = 1;
			}

			else
				found = 0;

		}

		if (found == 0)
		{
			printf("Record is not found!!! Please make sure the input data is valid\n");
		}

	} while (found == 0);
}


void removeRecord(void) //To remove the record of staff
{
	//Local Variables declaration
	StaffInformation staff[20];
	FILE *pointer;
	FILE *removePtr;
	int i = 0, j;
	int found = 0;
	int staffCount = 0;
	char inputId[5];
	char response;
	SYSTEMTIME t;

	GetLocalTime(&t);

	//Open file for reading mode
	pointer = fopen("StaffInfo.txt", "r");

	//Check file's existency
	if (pointer == NULL)
	{
		printf("File cannot be opened!!!\n");
		system("pause");
		exit(-1);
	}

	//Process
	while (fscanf(pointer, "%[^|]|%[^|]|%[^|]|%c|%[^|]|%d/%d/%d|%[^|]|%[^|]|%lf\n", staff[i].staffId, staff[i].designation, staff[i].id.name, &staff[i].id.gender, &staff[i].id.identityCardNo, &staff[i].date.day, &staff[i].date.month, &staff[i].date.year, &staff[i].qualifications, staff[i].phoneNo, &staff[i].salary) != EOF)
	{
		staffCount++;
		i++;

	}

	fclose(pointer);

	displayExistingRecord();

	//Open another file
	removePtr = fopen("StaffRemove.txt", "a");
	pointer = fopen("StaffInfo.txt", "w");

	//Check file's existency
	if (removePtr == NULL || pointer == NULL)
	{
		printf("File cannot be opened!!!\n");
		system("pause");
		exit(-1);
	}

	do
	{
		printf("Enter staff ID for removal (XXX to stop) :");
		rewind(stdin);
		scanf("%4s", inputId);

		for (i = 0; i < staffCount && !found; i++)
		{
			if (strcmp(inputId, "XXX") == 0)
				found = -1; //Exit from the function when user enter XXX

			else if (strcmp(inputId, staff[i].staffId) == 0)
			{
				printf("Record found >\n");
				printf("\t%-30s:%30s\n", "Staff ID", staff[i].staffId);
				printf("\t%-30s:%30s\n", "Designation", staff[i].designation);
				printf("\t%-30s:%30s\n", "Staff Name", staff[i].id.name);
				printf("\t%-30s", "Gender");

				if (staff[i].id.gender == 'M')
					printf(":%30s\n", "Male");

				else
					printf(":%30s\n", "Female");

				printf("\t%-30s:%30s\n", "Identification Card No", staff[i].id.identityCardNo);
				printf("\t%-30s:%20s%02d/%02d/%d\n", "Employed Date", " ", staff[i].date.day, staff[i].date.month, staff[i].date.year);

				staff[i].workingExperience = calWorkingExperience(staff[i].date.year);  //Calculate the working experience by calling another function

				printf("\t%-30s:%30d\n", "Working Experience", staff[i].workingExperience);
				printf("\t%-30s:%30s\n", "Qualifications", staff[i].qualifications);
				printf("\t%-30s:%30s\n", "Phone Number", staff[i].phoneNo);
				printf("\t%-30s:%20sRM %.2f\n", "Salary", " ", staff[i].salary);

				do
				{

					printf("Sure to remove record (Y=Yes) ? : ");
					rewind(stdin);
					scanf("%c", &response);

					response = toupper(response);


					if (response == 'Y')
					{
						fprintf(removePtr, "%s|%s|%s|%c|%s|%d/%d/%d|%s|%s|%.2f\n", staff[i].staffId, staff[i].designation, staff[i].id.name, staff[i].id.gender, staff[i].id.identityCardNo, staff[i].date.day, staff[i].date.month, staff[i].date.year, staff[i].qualifications, staff[i].phoneNo, staff[i].salary);

						for (j = i; j < staffCount - 1; j++)
						{
							staff[j] = staff[j + 1];

						}

					}

					else if (response != 'N')
					{
						printf("You can only enter Y or N!!!\n");
					}

				} while (response != 'Y'&&response != 'N');

				found = 1;
			}

			else
				found = 0;

		}

		if (found == 0)
		{
			printf("The record does not exist!!!\n");
		}

	} while (found == 0);

	if (response == 'Y')
	{
		for (i = 0; i < staffCount - 1; i++)
		{
			fprintf(pointer, "%s|%s|%s|%c|%s|%d/%d/%d|%s|%s|%.2f\n", staff[i].staffId, staff[i].designation, staff[i].id.name, staff[i].id.gender, staff[i].id.identityCardNo, staff[i].date.day, staff[i].date.month, staff[i].date.year, staff[i].qualifications, staff[i].phoneNo, staff[i].salary);
		}
	}

	else
	{
		for (i = 0; i < staffCount; i++)
		{
			fprintf(pointer, "%s|%s|%s|%c|%s|%d/%d/%d|%s|%s|%.2f\n", staff[i].staffId, staff[i].designation, staff[i].id.name, staff[i].id.gender, staff[i].id.identityCardNo, staff[i].date.day, staff[i].date.month, staff[i].date.year, staff[i].qualifications, staff[i].phoneNo, staff[i].salary);
		}
	}


	printf("Done \n\n");

	fclose(removePtr);
	fclose(pointer);




}


void displayRemoveRecord(void) //To display the record of staff that has been removed
{
	//Variables declaration
	FILE *fPointer;
	int i = 0;
	StaffInformation staff;
	SYSTEMTIME t;

	GetLocalTime(&t);

	//Open file for reading 
	fPointer = fopen("StaffRemove.txt", "r");

	//Check file's existency
	if (fPointer == NULL)
	{
		printf("File cannot be opened!!!\n");
		system("pause");
		exit(-1);
	}

	printf("Viewed by : %d/%d/%d %02d:%02d\n", t.wDay, t.wMonth, t.wYear, t.wHour, t.wMinute);

	printf("+------------+--------------+---------------------------+----------+\n");
	printf("|%12s|%14s|%27s|%10s|\n", "Staff ID", "Designation", "Name", "Gender");
	printf("+------------+--------------+---------------------------+----------+\n");

	while (fscanf(fPointer, "%[^|]|%[^|]|%[^|]|%c|%[^|]|%d/%d/%d|%[^|]|%[^|]|%lf\n", staff.staffId, staff.designation, staff.id.name, &staff.id.gender, staff.id.identityCardNo, &staff.date.day, &staff.date.month, &staff.date.year, staff.qualifications, staff.phoneNo, &staff.salary) != EOF)
	{
		if (staff.id.gender == 'M')
		{
			printf("|%12s|%14s|%27s|", staff.staffId, staff.designation, staff.id.name);
			printf("%10s|\n", "Male");

		}


		else
		{
			printf("|%12s|%14s|%27s|", staff.staffId, staff.designation, staff.id.name);
			printf("%10s|\n", "Female");
		}

		i++;
	}
	printf("+------------+--------------+---------------------------+----------+\n");

	fclose(fPointer);

}


int calWorkingExperience(int tempYear) //To calculate the working experience of staff
{
	//Variables declaration
	int workingExp;
	SYSTEMTIME t;


	GetLocalTime(&t);

	workingExp = t.wYear - tempYear;

	return workingExp;
}

