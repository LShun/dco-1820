/*<Medical Supplies Module>
Name           : Hiew Long Shun
Student ID     : 18WMD06275
Course Name    : Diploma In Science (Computer Science and Computer Mathematics)
Tutorial Group : 5
Purpose        : To store the information of medical supplies
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#pragma warning(disable:4996)

#undef IN_FILE
#define IN_FILE "supplies.dat"
#undef OUT_FILE
#define OUT_FILE "supplies.dat"

#undef T_MEDICINE
#define T_MEDICINE 30 //MODIFY THIS NUMBER TO CHANGE TOTAL MEDICINE CAN BE HANDLED

#undef TCONTENTS_FSTRING
#define TCONTENTS_FSTRING "                    |%-6.6s|%-28.28s|%02d/%02d/%04d |%12.12s|%-5.5s|%-5d|%-5d|\n"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct {
	int day, month, year;
} msDate;

typedef struct {
	char company[30];
	char country[4];
} Manufacturer;

typedef struct {
	char itemID[6];
	char desc[60];
	msDate expiry;
	Manufacturer mfr;
	int qty;
	int restock;
} Medicine;

//prototypes
int msMenu();
void showSupplies(FILE *fp);
/************************************************/
void addSupplies();
void newMedicine(FILE* fp, Medicine medicine);
/************************************************/
void searchSupplies();
int searchMenu();
/************************************************/
void modifySupplies();
void deleteSupplies();
void showRestock();
/************Supplementary***********************/
void medicineExpiryCheck(Medicine medicine);
void tableHeader(void);
void homescreen(void);
FILE* vfopen(char file[], char mode[]);
void header(char title[]);

int medicalSupplies(void) // Medical supplies module's control module
{
	//variables
	int choice;
	FILE *fp;

	while (1)
	{
		homescreen();
		//ask user for choice
		choice = msMenu();
		system("cls");
		switch (choice)
		{
		case 1:
			fp = vfopen(IN_FILE, "rb");
			showSupplies(fp);
			fclose(fp);
			break;
		case 2:
			addSupplies();
			break;
		case 3:
			searchSupplies();
			break;
		case 4:
			//show all entries
			fp = vfopen(IN_FILE, "rb");
			showSupplies(fp);
			fclose(fp);
			//start modify
			modifySupplies();
			break;
		case 5:
			deleteSupplies();
			break;
		case 6:
			showRestock();
			break;
		case 7:
			printf("Exiting...\n");
			return 0;
		default:
			header("Invalid choice.");
		}
		system("pause");
		system("cls");
	}
}

int msMenu() // Main menu for medical supplies module
{
	//variables
	int choice;

	//display mainMenu
	header("Medical Supplies Module");
	printf("%20c1. Show medical supplies\n"
		"%20c2. Add medical supplies\n"
		"%20c3. Search medical supplies\n"
		"%20c4. Modify medical supplies\n"
		"%20c5. Delete medical supplies\n"
		"%20c6. Show medical supplies require restocking\n"
		"%20c7. Exit\n\n"
		"%20cEnter your choice (1-7): ",
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');

	//accept user choice
	scanf("%d", &choice);
	rewind(stdin);
	//print a separator
	printf("\n");
	return choice;
}


void showSupplies(FILE *fp) // Show medical supplies stored in database
{
	//variables
	Medicine medicine;
	SYSTEMTIME t;
	int listing = 0;

	//get the current time
	GetLocalTime(&t);

	//print title and date
	//printf("Medicine Details - as at %d-%d-%d\n\n", t.wDay, t.wMonth, t.wYear);
	header("Medicine Details");

	tableHeader();

	while (fread(&medicine, sizeof(Medicine), 1, fp) == 1) //read details from file into structure
	{
		//print details
		printf(TCONTENTS_FSTRING, medicine.itemID, medicine.desc, medicine.expiry.day, medicine.expiry.month, medicine.expiry.year, medicine.mfr.company, medicine.mfr.country, medicine.qty, medicine.restock);

		//increase total listing
		listing++;
	}
	tableHeader();
	//print total Medicine listed
	printf("\n" "< %d Medicines listed >\n\n", listing);

	//close file
	fclose(fp);
} 


void addSupplies() // Add medical supplies to database
{
	//variables
	FILE *fp;
	Medicine medicine = { '\0' };

	//create a binary .dat file to store the Medicines ( append )
	fp = vfopen(OUT_FILE, "ab");

	header("Add new medical supplies");

	//request Medicine details from user
	newMedicine(fp, medicine);

	//close file stream
	fclose(fp);
	printf("Done.\n");
} 

void newMedicine(FILE* fp, Medicine medicine) //take user input for adding new medicines
{
	printf("Enter a medicine's ITEM ID (key in XXX to stop): ");
	scanf(" %5s", &medicine.itemID);
	rewind(stdin);

	while (strcmp(medicine.itemID, "XXX") != 0)
	{
		printf("Enter medicine's DESCRIPTION: ");
		scanf(" %59[^\n]", &medicine.desc);
		rewind(stdin);

		printf("Enter medicine's EXPIRY DATE ( format: DD MM YYYY ): ");
		scanf(" %d %d %d", &medicine.expiry.day, &medicine.expiry.month, &medicine.expiry.year);
		rewind(stdin);
		while (medicine.expiry.day < 1 || medicine.expiry.day > 31 ||
			medicine.expiry.month < 1 || medicine.expiry.month > 12)
		{
			printf("Invalid expiry date, please try again.\n"
				"Enter medicine's EXPIRY DATE ( eg: DD MM YYYY ): ");
			scanf(" %d %d %d", &medicine.expiry.day, &medicine.expiry.month, &medicine.expiry.year);
			rewind(stdin);
		}
		medicineExpiryCheck(medicine);

		printf("Enter medicine's MFG COMPANY (Eg: (GSK) GlaxoSmithKline): ");
		scanf(" %29[^\n]", &medicine.mfr.company);
		rewind(stdin);

		printf("Enter medicine's MFG COUNTRY INITIALS (Eg: MY): ");
		scanf(" %3s", &medicine.mfr.country);
		rewind(stdin);

		printf("Enter medicine's QUANTITY IN STOCK (Eg: 1000): ");
		scanf(" %d", &medicine.qty);
		rewind(stdin);
		while (medicine.qty < 0)
		{
			printf("%d is an invalid quantity\n", medicine.qty);
			printf("Enter medicine's QUANTITY IN STOCK (Eg: 1000): ");
			scanf(" %d", &medicine.qty);
			rewind(stdin);
		}

		printf("Enter medicine's RESTOCK COUNT (Eg: 1000): ");
		scanf(" %d", &medicine.restock);
		rewind(stdin);

		//write contents of medicine into output file
		fwrite(&medicine, sizeof(Medicine), 1, fp);
		printf("\nEnter a medicine's ITEM ID (key in XXX to stop): ");
		scanf(" %5s", &medicine.itemID);
		rewind(stdin);
	}
}


void searchSupplies() // Search medical supplies in database
{
	//variables
	FILE *fp;
	Medicine medicine;
	SYSTEMTIME t;
	int listing = 0, searchBy;
	char search[60];

	//open the binary file
	fp = vfopen(IN_FILE, "rb");

	//get the current time
	GetLocalTime(&t);
	//prompt user for input
	searchBy = searchMenu();

	switch (searchBy)
	{
	case 1:
		printf("Searching by ID...\n\n");
		break;
	case 2:
		printf("Searching by description...\n\n");
		break;
	case 3:
		printf("Exiting...\n");
		return;
	}
	printf("Enter search terms (beginning with): ");
	scanf("%[^\n]", &search);
	rewind(stdin);

	//print title and date
	header("Medicine Details");

	tableHeader();

	if (searchBy == 1)
	{
		while (fread(&medicine, sizeof(Medicine), 1, fp) == 1) //read details from file into structure
		{
			//print details
			if (strncmp(search, medicine.itemID, strlen(search)) == 0)
			{
				printf(TCONTENTS_FSTRING, medicine.itemID, medicine.desc, medicine.expiry.day, medicine.expiry.month, medicine.expiry.year, medicine.mfr.company, medicine.mfr.country, medicine.qty, medicine.restock);
				//increase total listing
				listing++;
			}
		}
		tableHeader();
	}
	else
	{
		while (fread(&medicine, sizeof(Medicine), 1, fp) == 1) //read details from file into structure
		{
			//if a match is found
			if (strncmp(search, medicine.desc, strlen(search)) == 0)
			{
				printf(TCONTENTS_FSTRING, medicine.itemID, medicine.desc, medicine.expiry.day, medicine.expiry.month, medicine.expiry.year, medicine.mfr.company, medicine.mfr.country, medicine.qty, medicine.restock);
				//increase total listing
				listing++;
			}
		}
		tableHeader();
	}

	//print total Medicine listed
	printf("\n" "< %d Medicines listed >\n\n", listing);

	//close file
	fclose(fp);
}


int searchMenu() // Menu for search medical supplies criteria
{
	int choice;
	//prompt for input
	header("Search medical supplies");
	printf("Search by:\n\n"

		"1. Medicine ID\n"
		"2. Medicine Description\n"
		"3. Cancel\n\n"

		"Enter your choice (1-3): ");
	
	scanf("%d", &choice);
	rewind(stdin);
	while (choice < 1 || choice > 3)
	{
		printf(ANSI_COLOR_RED "Invalid choice. Enter again (1-3): " ANSI_COLOR_RESET);
		scanf("%d", &choice);
		rewind(stdin);
	}

	rewind(stdin);
	return choice;
}

void modifyMenu() //menu for modify medical supplies
{
	printf("Modify: \n"
		"\t1. Item ID\n"
		"\t2. Desc\n"
		"\t3. Expiry Date\n"
		"\t4. MFR Company\n"
		"\t5. MFR Country\n"
		"\t6. Quantity\n"
		"\t7. Restock Count\n"
		"\t8. Go to next entry (if available, if not, stop modify)\n"
		"\tOther. Cancel\n"
		"Your choice? (Key in a number): ");
}


void modifySupplies() //Modify medical supplies in database
{
	char mID[6], confirm, changes[25];
	FILE *fp;
	int mCount, i = 0, match = -1, modifications = 0, selection = 0;
	Medicine m[T_MEDICINE], buffer;

	//open IN_FILE for reading
	fp = vfopen(IN_FILE, "rb");

	//copy records into arrays, keeping in record of the Medicines read (as a return value)
	mCount = fread(&m, sizeof(Medicine), T_MEDICINE, fp);
	//close the file
	fclose(fp);

	//check if limit reached for medicines
	while (1)
	{
		//Find Medicine to modify
		do
		{
			//ask user for Medicine code
			printf("Please enter a Medicine ItemID for modification (Enter XXX to go to menu): ");
			scanf("%s", &mID);
			rewind(stdin);
			if (strcmp(mID, "XXX") != 0)
			{
				match = -1;
				//match it with the Medicine code stored in the array
				for (i = 0; i < mCount; i++)
				{
					if (strcmp(m[i].itemID, mID) == 0)
					{
						printf(ANSI_COLOR_GREEN "Record found." ANSI_COLOR_RESET "\n");
						match = i;
						buffer = m[match];
						tableHeader();
						//print details
						printf(TCONTENTS_FSTRING, m[i].itemID, m[i].desc, m[i].expiry.day, m[i].expiry.month, m[i].expiry.year, m[i].mfr.company, m[i].mfr.country, m[i].qty, m[i].restock);
						tableHeader();

						//Ask what to modify
						modifyMenu();
						scanf("%d", &selection);
						rewind(stdin);

						//Get Modification
						confirm = 'N';
						if (selection >= 1 && selection <= 7)
						{
							printf("Enter your changes to overwrite: ");
							scanf("%25[^\n]", &changes);
							rewind(stdin);
							//Perform modification
							switch (selection)
							{
							case 1: strcpy(buffer.itemID, changes);                       break;
							case 2: strcpy(buffer.desc, changes);                         break;
							case 3:
								if ((buffer.expiry.day = atoi(strtok(changes, "-/ "))) != NULL)
								{
									if ((buffer.expiry.month = atoi(strtok(NULL, "-/ "))) != NULL)
									{
										buffer.expiry.year = atoi(strtok(NULL, "-/ "));
									}
								}
								while (buffer.expiry.day < 1 || buffer.expiry.day > 31 ||
									buffer.expiry.month < 1 || buffer.expiry.month > 12)
								{
									printf("Invalid expiry date, please try again.\n"
										"Enter medicine's new expiry date ( eg: DD/MM/YYYY ): ");
									scanf("%s", &changes);
									rewind(stdin);
									if ((buffer.expiry.day = atoi(strtok(changes, "-/ "))) != NULL)
									{
										if ((buffer.expiry.month = atoi(strtok(NULL, "-/ "))) != NULL)
										{
											buffer.expiry.year = atoi(strtok(NULL, "-/ "));
										}
									}
								};                                                        break;
							case 4: strcpy(buffer.mfr.company, changes);                  break;
							case 5: strcpy(buffer.mfr.country, changes);                  break;
							case 6: buffer.qty = atoi(changes);                           break;
							case 7: buffer.restock = atoi(changes);                       break;
							}
							//Confirmation
							printf("This previous entry will be destroyed, are you sure to overwrite? (Y/N): ");
							scanf("%c", &confirm);
							rewind(stdin);
						}
						//Show updated record
						if (confirm == 'Y')
						{
							m[match] = buffer;
							printf("Modified record:\n");
							tableHeader();
							//print details
							printf(TCONTENTS_FSTRING, m[i].itemID, m[i].desc, m[i].expiry.day, m[i].expiry.month, m[i].expiry.year, m[i].mfr.company, m[i].mfr.country, m[i].qty, m[i].restock);
							tableHeader();
							medicineExpiryCheck(m[i]);
							modifications++;
						}
						else
						{
							if (selection < 1 || selection > 8)
							{
								printf("Action cancelled, no changes have been made.\n\n");
								i = mCount;
							}
						}
					}
				}
				if (i == mCount && selection == 8)
					printf("\nNo other record with the code '%s' found in first %d medicine.\n"
						"If your total medicine count is above %d, \n"
						"increase the T_MEDICINE constant in medical supplies program.\n", mID, T_MEDICINE, T_MEDICINE);
				else if (match == -1)
				{
					printf("No record with product code %s is found\n", mID);
				}
			}
			else
			{
				//FINALIZE CHANGES
				//inform user changes made
				printf("\nTotal modifications: %d\n", modifications);

				//open the file
				fp = vfopen(OUT_FILE, "wb");

				//copy back array into the file
				fwrite(&m, sizeof(Medicine), mCount, fp);

				//close the file
				fclose(fp);
				printf("Exiting....\n\n");
				return;
			}
		} while (match == -1);
	}
}


void deleteSupplies() // Delete medical supplies from database
{
	//variables
	Medicine m[T_MEDICINE];
	FILE *fp;
	int i, mEntries, j = 0;
	char mID[6], choice = 'N';

	//open the file
	fp = vfopen(IN_FILE, "rb");

	//copy the entire file into the array
	mEntries = 0;
	while (fread(&m[mEntries], sizeof(Medicine), 1, fp) == 1)
	{
		mEntries++;
	}

	fclose(fp);

	header("Delete Medical Supplies");

	//ask user on which medicine code to delete
	printf("Enter the medicine ID to delete (XXX to stop): ");
	scanf("%6s", &mID);
	rewind(stdin);

	//check the entire array for that Medicine code
	if (strcmp(mID, "XXX") != 0)
	{
		for (i = 0; i < mEntries; i++)
		{
			if (strcmp(m[i].itemID, mID) == 0)
			{
				//if found, ask for confirmation
				printf("Matching record found, Medicine:\n");
				tableHeader();
				printf(TCONTENTS_FSTRING, m[i].itemID, m[i].desc, m[i].expiry.day, m[i].expiry.month, m[i].expiry.year, m[i].mfr.company, m[i].mfr.country, m[i].qty, m[i].restock);
				tableHeader();
				printf("Are you sure you want to delete? (Y = yes/N = next entry (if present)/C = cancel): ");

				scanf(" %c", &choice);
				rewind(stdin);

				if (choice == 'Y' || choice == 'y')
				{
					printf("Deleting...\n");
					//shift the rest forward
					for (i; i < (mEntries - 1); i++)
					{
						m[i] = m[i + 1];
					}
					//write into file
					fp = vfopen(OUT_FILE, "wb");
					fwrite(&m[j], sizeof(Medicine), mEntries - 1, fp);
					printf(ANSI_COLOR_GREEN "Completed." ANSI_COLOR_RESET "\n");
					fclose(fp);
				}
			}
			if (choice == 'C' || choice == 'c')
			{
				i = mEntries; //set to end
				printf("\n" ANSI_COLOR_YELLOW "Deletion process cancelled. No changes has been made" ANSI_COLOR_RESET "\n");
			}
		}
		if (i == mEntries && (choice == 'N' || choice == 'n'))
		{
			//if not found, prompt not found
			printf("\n\nNo other medicine with that code '%s' found in first %d medicine.\n"
				"If your total medicine count is above %d, \n"
				"increase the T_MEDICINE constant in medical supplies program.\n\n", mID, T_MEDICINE, T_MEDICINE);
		}
	}
}


void showRestock() //show products reaching restock level
{
	//variables
	FILE *fp;
	Medicine medicine;
	SYSTEMTIME t;
	int listing = 0;

	//open the binary file
	fp = vfopen(IN_FILE, "rb");

	//get the current time
	GetLocalTime(&t);

	//print title and date
	header("Medicine Restocking Details");
	//printf("Medicine Restocking Details - as at %d-%d-%d\n\n", t.wDay, t.wMonth, t.wYear);
	tableHeader();

	while (fread(&medicine, sizeof(Medicine), 1, fp) == 1) //read details from file into structure
	{
		if (medicine.qty <= medicine.restock)
		{
			//print details
			printf(TCONTENTS_FSTRING, medicine.itemID, medicine.desc, medicine.expiry.day, medicine.expiry.month, medicine.expiry.year, medicine.mfr.company, medicine.mfr.country, medicine.qty, medicine.restock);

			//increase total listing
			listing++;
		}
	}
	tableHeader();
} //Show medical supplies reaching restock threshold in database

void medicineExpiryCheck(Medicine medicine) //Check expiry date for medicines
{
	SYSTEMTIME t;
	GetLocalTime(&t);

	if (medicine.expiry.year < t.wYear ||
		(medicine.expiry.year == t.wYear && medicine.expiry.month < t.wMonth) ||
		(medicine.expiry.year == t.wYear && medicine.expiry.month == t.wMonth && medicine.expiry.day <= t.wDay))
	{
		printf("\n" ANSI_COLOR_YELLOW "WARN: Product already expired as of %d/%d/%d, ensure this is intended." ANSI_COLOR_RESET "\n\n", t.wDay, t.wMonth, t.wYear);
	}
} 

void tableHeader(void) // Prints table header for database
{
	printf("                    +------+----------------------------+-----------+------------+-----+-----+-----+\n"
		   "                    |ItemID|Desc                        |EXP(D/M/Y) |MFR COMPANY |CTRY.|QTY  |RES. |\n"
		   "                    +------+----------------------------+-----------+------------+-----+-----+-----+\n");
} 

