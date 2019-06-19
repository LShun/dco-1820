/*<Patient Information Module>
Name           : Ong Shannen
Student ID     : 18WMD05273
Course Name    : Diploma In Science (Computer Science and Computer Mathematics)
Tutorial Group : Group 5
Purpose        : To add, display, search, modify and display statistic of patient information
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>
#pragma warning(disable:4996)

typedef struct {
	int day, month, year;
	int min, hour;
}Date;

typedef struct {
	char patientID[9];
	Date d;
	char name[40];
	int age;
	char gender;
	char contactNo[13];
	char allergies[40];
	char sickness[40];
}Patient;

void addPatientRecords();
void searchPatientRecords();
void modifyPatientRecords();
void displayPatientRecords();
void statistic();
void graph(int a, int b);
void homescreen(void);

void patientInfo()
{
	homescreen();

	int choice;
	do
	{
		header("PATIENT INFORMATION MODULE");

		printf("\t\t\t1. Add patient records\n");
		printf("\t\t\t2. Search patient records\n");
		printf("\t\t\t3. Modify patient records\n");
		printf("\t\t\t4. Display patient records\n");
		printf("\t\t\t5. Display statistics of records\n");
		printf("\t\t\t6. Exit\n");

		printf("\n\t\t\tEnter your choices: ");
		scanf("%d", &choice);
		printf("\n");
		rewind(stdin);

		if (choice == 1)
			addPatientRecords();
		else if (choice == 2)
			searchPatientRecords();
		else if (choice == 3)
			modifyPatientRecords();
		else if (choice == 4)
			displayPatientRecords();
		else if (choice == 5)
			statistic();

		system("pause");
		system("cls");

	} while (choice != 6);

}
void addPatientRecords() //To add patient information
{
	Patient p;

	FILE*fp1;

	char ans;

	fp1 = vfopen("patient.txt", "a");

	header("ADD PATIENT MODULE");

	rewind(stdin);
	printf("Do you want to add record? (Enter N to exit): ");
	scanf("%c", &ans);
	rewind(stdin);

	while (ans != 'n' && ans != 'N') 
	{
		printf("Enter date (dd mm yyyy): ");
		scanf("%d %d %d", &p.d.day, &p.d.month, &p.d.year);

		while (getValidDate(p.d.day, p.d.month, p.d.year) == 0) //To validate date
		{	printf("Invalid date!! Please enter again\n\n");
			printf("Enter date (dd mm yyyy): ");
			scanf("%d %d %d", &p.d.day, &p.d.month, &p.d.year);
		}

		rewind(stdin);

		printf("Enter time (hh mm): ");
		scanf("%d %d", &p.d.hour, &p.d.min);

		while (getValidTime(p.d.hour, p.d.min)==0) //To validate time
		{
			printf("Invalid time!! Please enter again\n\n");
			printf("Enter time (hh mm): ");
			scanf("%d %d", &p.d.hour, &p.d.min);
		}

		rewind(stdin);

		printf("Enter patient ID (P2018XXX): ");
		scanf("%s", p.patientID);

		rewind(stdin);

		printf("Enter patient name: ");
		scanf("%[^\n]", p.name);

		rewind(stdin);

		printf("Enter the age: ");
		scanf("%d", &p.age);
		rewind(stdin);

		
		printf("Enter gender: ");
		scanf("%c", &p.gender);
		rewind(stdin);

		while (p.gender != 'M'&&p.gender != 'F')
		{
			printf("Invalid!! Please enter again\n\n");

			printf("Enter gender: ");
			scanf("%c", &p.gender);
			rewind(stdin);
		}

		printf("Enter contact number (01X-XXXXXXXX): ");
		scanf("%s", p.contactNo);

		rewind(stdin);

		printf("Enter allergies of patient: ");
		scanf("%s", p.allergies);

		rewind(stdin);

		printf("Enter sickness of patient: ");
		scanf("%s", p.sickness);

		rewind(stdin);

		printf("Add more records? (Enter N to exit): ");
		scanf("%c", &ans);

		//print to text file 
		fprintf(fp1, "%s|%d/%d/%d|%d:%d|%s|%d|%c|%s|%s|%s\n", p.patientID, p.d.day, p.d.month, p.d.year, p.d.hour, p.d.min, p.name, p.age, p.gender, p.contactNo, p.allergies, p.sickness);

		printf("Record added successfully\n");
	}
	fclose(fp1);
}

void searchPatientRecords() //To search for patient information
{
	Patient p[30];

	FILE*fp2;

	char search[10];
	int i = 0, nPatient = 0, found=0;

	fp2 = vfopen("patient.txt", "r");


	while (fscanf(fp2, "%[^|]|", p[i].patientID) != EOF) //Read from text file
	{
		fscanf(fp2, "%d/%d/%d|%d:%d|", &p[i].d.day, &p[i].d.month, &p[i].d.year, &p[i].d.hour, &p[i].d.min);
		fscanf(fp2, "%[^|]|%d|%c|%[^|]|%[^|]|%[^\n]\n", p[i].name, &p[i].age, &p[i].gender, p[i].contactNo, p[i].allergies, p[i].sickness);
		nPatient++;
		i++;
	}

	displayPatientRecords();

	header("SEARCH PATIENT MODULE");

		do {
			printf("Enter the patient ID to search: ");
			scanf("%s", search);
			rewind(stdin);

			for (i = 0; i < nPatient && !found; i++)
			{
				if (strcmp(search, p[i].patientID) == 0)
				{
					printf("\n\n\t%-30s : %s\n", "PATIENT ID", p[i].patientID);
					printf("\t%-30s : %s\n", "NAME", p[i].name);
					printf("\t%-30s : %d\n", "AGE", p[i].age);
					printf("\t%-30s : %c\n", "GENDER", p[i].gender);
					printf("\t%-30s : %s\n", "CONTACT NO", p[i].contactNo);
					printf("\t%-30s : %s\n", "ALLERGIES", p[i].allergies);
					printf("\t%-30s : %s\n\n\n", "SICKNESS", p[i].sickness);

					found = 1;
				}
				else
					found = 0;

			}
			if (found == 0)
			{
				printf("Patient ID not found!!\n\n");
			}

		} while (found == 0);


	fclose(fp2);
}
void modifyPatientRecords() //To modify patient records
{
	Patient p[30];

	FILE*fp3;

	int i = 0, choice, found=0;
	char modify[9];
	char ans;
	int nPatient=0;

	fp3 = vfopen("patient.txt", "r");

	while (fscanf(fp3, "%[^|]|", p[i].patientID) != EOF)
	{
		fscanf(fp3, "%d/%d/%d|%d:%d|", &p[i].d.day, &p[i].d.month, &p[i].d.year, &p[i].d.hour, &p[i].d.min);
		fscanf(fp3, "%[^|]|%d|%c|%[^|]|%[^|]|%[^\n]\n", p[i].name, &p[i].age, &p[i].gender, p[i].contactNo, p[i].allergies, p[i].sickness);
		i++;
		nPatient++;
	}
	fclose(fp3);

	displayPatientRecords();

	header("MODIFY PATIENT MODULE");

	do {
		printf("Enter the patient ID to modify: ");
		scanf("%s", &modify);
		rewind(stdin);

		for (i = 0; i < nPatient && !found; i++)
		{
			if (strcmp(p[i].patientID, modify) == 0)
			{
				printf("\n\n\t%-30s : %s\n", "PATIENT ID", p[i].patientID);
				printf("\t%-30s : %s\n", "NAME", p[i].name);
				printf("\t%-30s : %d\n", "AGE", p[i].age);
				printf("\t%-30s : %c\n", "GENDER", p[i].gender);
				printf("\t%-30s : %s\n", "CONTACT NO", p[i].contactNo);
				printf("\t%-30s : %s\n", "ALLERGIES", p[i].allergies);
				printf("\t%-30s : %s\n\n\n", "SICKNESS", p[i].sickness);

				printf("Sure to modify? (Y=yes, N=no): ");
				scanf("%c", &ans);
				rewind(stdin);

				found = 1;

				if (ans == 'Y' || ans == 'y')
				{
					do {
						system("cls");

						printf("\n\n\t%-30s : %s\n", "PATIENT ID", p[i].patientID);
						printf("\t%-30s : %s\n", "NAME", p[i].name);
						printf("\t%-30s : %d\n", "AGE", p[i].age);
						printf("\t%-30s : %c\n", "GENDER", p[i].gender);
						printf("\t%-30s : %s\n", "CONTACT NO", p[i].contactNo);
						printf("\t%-30s : %s\n", "ALLERGIES", p[i].allergies);
						printf("\t%-30s : %s\n\n\n", "SICKNESS", p[i].sickness);

						printf("1.Age of patient\n");
						printf("2.Contact number of patient\n");
						printf("3.Allergies\n");
						printf("4.Sickness\n");
						printf("5.Exit\n\n");

						printf("Enter the choice to modify: ");
						scanf("%d", &choice);
						rewind(stdin);

						if (choice == 1)
						{
							printf("\nModify the age of patient: ");
							scanf("%d", &p[i].age);
							rewind(stdin);
						}
						else if (choice == 2)
						{
							printf("\nModify the contact number of patient: ");
							scanf("%s", p[i].contactNo);
							rewind(stdin);
						}
						else if (choice == 3)
						{
							printf("\nModify the allergies of patient: ");
							scanf("%[^\n]", p[i].allergies);
							rewind(stdin);
						}
						else if (choice == 4)
						{
							printf("\nModify the sickness of patient: ");
							scanf("%[^\n]", p[i].sickness);
							rewind(stdin);
						}

					} while (choice != 5);
					/*found = 1;*/
				}
			}
			else
				found = 0;

		}
		if (found == 0)
		{
			printf("Patient ID not found!\n\n");
		}
	} while (found == 0);

	fp3 = vfopen("patient.txt", "w");
	for (i = 0; i < nPatient; i++)
	{
		fprintf(fp3, "%s|%d/%d/%d|%d:%d|%s|%d|%c|%s|%s|%s\n", p[i].patientID, p[i].d.day, p[i].d.month, p[i].d.year, p[i].d.hour, p[i].d.min, p[i].name, p[i].age, p[i].gender, p[i].contactNo, p[i].allergies, p[i].sickness);
	}
	fclose(fp3);

}

void displayPatientRecords() //To display patient record
{
	Patient p;

	FILE*fp4;

	fp4 = vfopen("patient.txt", "r");

	header("PATIENT INFORMATION MODULE");
	
	printf("\t\t\t+-----------+------+------------+------------------+-----+--------+\n");
	printf("\t\t\t|%11s|%6s|%12s|%18s|%5s|%8s|\n","DATE","TIME","PATIENT ID","NAME","AGE","GENDER");
	printf("\t\t\t+-----------+------+------------+------------------+-----+--------+\n");

	while (fscanf(fp4, "%[^|]|", p.patientID) != EOF)
	{
		fscanf(fp4, "%d/%d/%d|%d:%d|", &p.d.day, &p.d.month, &p.d.year, &p.d.hour, &p.d.min);
		fscanf(fp4, "%[^|]|%d|%c|%[^|]|%[^|]|%[^\n]\n", p.name, &p.age, &p.gender, p.contactNo, p.allergies, p.sickness);
		printf("\t\t\t| %02d/%02d/%02d| %02d:%02d|%12s|%18s|%5d|%8c|\n", p.d.day, p.d.month, p.d.year, p.d.hour, p.d.min, p.patientID, p.name, p.age, p.gender);
	}
	printf("\t\t\t+-----------+------+------------+------------------+-----+--------+\n");
	fclose(fp4);
}
void statistic()
{
	Patient p;

	FILE*fp5;
	
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0, count7 = 0, count8 = 0, count9 = 0;
	char sick1[10][50] = {0}, sick2[10][50] = { 0 }, sick3[10][50] = { 0 }, sick4[10][50] = { 0 }, sick5[10][50] = { 0 };
	char sick6[10][50] = { 0 }, sick7[10][50] = { 0 }, sick8[10][50] = { 0 }, sick9[10][50] = { 0 };

	fp5 = vfopen("patient.txt", "r");
	
	while (fscanf(fp5, "%[^|]|", p.patientID) != EOF)
	{
		fscanf(fp5, "%d/%d/%d|%d:%d|", &p.d.day, &p.d.month, &p.d.year, &p.d.hour, &p.d.min);
		fscanf(fp5, "%[^|]|%d|%c|%[^|]|%[^|]|%[^\n]\n", p.name, &p.age, &p.gender, p.contactNo, p.allergies, p.sickness);
		{
			if (p.age > 0 && p.age <= 10)
				strcpy(sick1[count1++], p.sickness);
			else if (p.age > 10 && p.age <= 20)
				strcpy(sick2[count2++], p.sickness);
			else if (p.age > 20 && p.age <= 30)
				strcpy(sick3[count3++], p.sickness);
			else if (p.age > 30 && p.age <= 40)
				strcpy(sick4[count4++], p.sickness);
			else if (p.age > 40 && p.age <= 50)
				strcpy(sick5[count5++], p.sickness);
			else if (p.age > 50 && p.age <= 60)
				strcpy(sick6[count6++], p.sickness);
			else if (p.age > 60 && p.age <= 70)
				strcpy(sick7[count7++], p.sickness);
			else if (p.age > 70 && p.age <= 80)
				strcpy(sick8[count8++], p.sickness);
			else if (p.age > 80 && p.age <= 90)
				strcpy(sick9[count9++], p.sickness);

		}
	}
	
	header("STATISTIC MODULE");
		
		if(sick1[0][0]!='\0')
		{
			printf("+-------------------------------------------------------+\n");
			printf("|\t%-48s|\n", "The sickness in the age range of  1 to 10");
			printf("+-------------------------------------------------------+\n");
			for (int i = 0; i < count1; i++)
				printf("|\t\t%-40s|\n", sick1[i]);
			printf("+-------------------------------------------------------+\n\n");
		}
		if (sick2[0][0] != '\0')
		{
			printf("+-------------------------------------------------------+\n");
			printf("|\t%-48s|\n", "The sickness in the age range of 11 to 20");
			printf("+-------------------------------------------------------+\n");
			for (int i = 0; i < count2; i++)
				printf("|\t\t%-40s|\n", sick2[i]);
			printf("+-------------------------------------------------------+\n\n");
		}
		if (sick3[0][0] != '\0')
		{
			printf("+-------------------------------------------------------+\n");
			printf("|\t%-48s|\n", "The sickness in the age range of 21 to 30");
			printf("+-------------------------------------------------------+\n");
			for (int i = 0; i < count3; i++)
				printf("|\t\t%-40s|\n", sick3[i]);
			printf("+-------------------------------------------------------+\n\n");
		}
		if (sick4[0][0] != '\0')
		{
			printf("+-------------------------------------------------------+\n");
			printf("|\t%-48s|\n", "The sickness in the age range of 31 to 40");
			printf("+-------------------------------------------------------+\n");
			for (int i = 0; i < count4; i++)
				printf("|\t\t%-40s|\n", sick4[i]);
			printf("+-------------------------------------------------------+\n\n");
		}
		if (sick5[0][0] != '\0')
		{
			printf("+-------------------------------------------------------+\n");
			printf("|\t%-48s|\n", "The sickness in the age range of 41 to 50");
			printf("+-------------------------------------------------------+\n");
			for (int i = 0; i < count5; i++)
				printf("|\t\t%-40s|\n", sick5[i]);
			printf("+-------------------------------------------------------+\n\n");
		}
		if (sick6[0][0] != '\0')
		{
			printf("+-------------------------------------------------------+\n");
			printf("|\t%-48s|\n", "The sickness in the age range of 51 to 60");
			printf("+-------------------------------------------------------+\n");
			for (int i = 0; i < count6; i++)
				printf("|\t\t%-40s|\n", sick6[i]);
			printf("+-------------------------------------------------------+\n\n");
		}
		if (sick7[0][0] != '\0')
		{
			printf("+-------------------------------------------------------+\n");
			printf("|\t%-48s|\n", "The sickness in the age range of 61 to 70");
			printf("+-------------------------------------------------------+\n");
			for (int i = 0; i < count7; i++)
				printf("|\t\t%-40s|\n", sick7[i]);
			printf("+-------------------------------------------------------+\n\n");
		}
		if (sick8[0][0] != '\0')
		{
			printf("+-------------------------------------------------------+\n");
			printf("|\t%-48s|\n", "The sickness in the age range of 71 to 80");
			printf("+-------------------------------------------------------+\n");
			for (int i = 0; i < count8; i++)
				printf("|\t\t%-40s|\n", sick8[i]);
			printf("+-------------------------------------------------------+\n\n");
		}
		if (sick9[0][0] != '\0')
		{
			printf("+-------------------------------------------------------+\n");
			printf("|\t%-48s|\n", "The sickness in the age range of 81 to 90");
			printf("+-------------------------------------------------------+\n");
			for (int i = 0; i < count9; i++)
				printf("|\t\t%-40s|\n", sick9[i]);
			printf("+-------------------------------------------------------+\n\n");
		}


		int count[9] = { count1, count2, count3, count4, count5,count6,count7,count8,count9 };

	for (int i = 9; i >= 1; i--)
		graph(count[i - 1], i);

	fclose(fp5);
}
void graph(int count, int i)
{
	if (i == 9)
		printf("\t%7s\n", "Age");

	/*First Line*/
	printf("\t%5c|", ' ');
	for (int i = 0; i<count; i++)
		printf("_____");
	printf("\n");

	/*Second line*/
	printf("\t%2d-%2d|", 10 * i - 9, 10 * i);
	for (int i = 0; i<count; i++)
		printf("_____");
	if (count != 0)
	{
		printf("|\n");
	}
	else
		printf("\n");

	/*Third Line*/
	printf("\t%5c|\n", ' ');
	
	/*Fourth Line*/
	if (i == 1)
	{
		printf("\t     |______________________________________________________Number of people\n");
		printf("\t           1    2    3    4    5    6    7    8    9    10\n");
	}
}


