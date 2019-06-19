/*<Appointment Module>
Name           : Yap Kim Chun
Student ID     : 18WMD05588
Course Name    : Diploma In Science (Computer Science and Computer Mathematics)
Tutorial Group : 5
Purpose        : To add, display, search, modify, delete appoointment
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)

typedef struct {
	char date[11];       //To store date
	char time[6];        //To store time
}Time;

typedef struct {
	Time today;
	Time appointStart;
	Time appointEnd;
	char name[50];
	char patientName[50], patientId[9];
	char preferedDoc[20];
	char remark[50];
}Appointment;

int addAppointment(Appointment appoint[], const int appointSize);
void displayAppointmentInList(Appointment list[], const int size);
int searchAppointment(Appointment appoint[], const int size);
void displayAppointmentDetail(Appointment appoint);
int deleteAppointment(Appointment appoint[], int size);
void modifyAppointment(Appointment appoint[], int appointSize);
int getValidDate(int day, int month, int year);
int getValidTime(int hour, int min);
int generateList(Appointment* temp, Appointment appoint[], const int size, Appointment list[], int current);
int checkTimeOverlap(Appointment* source, Appointment list[], const int size);
void header(char s[]);

int appointments() {
	Appointment appointment[50];    //An array of structure
	int appointSize = 0;      //Keep track the number of the array
	char choice;
	FILE *fp = vfopen("Appointment.dat", "ab+");

	while (fread(&appointment[appointSize], sizeof(Appointment), 1, fp) != 0)  //read into the array  
		appointSize++;

	fclose(fp);

	do {

		homescreen();
		header("APPOINTMENT MODULE");

		printf("%20c%s",' ',"1.Display Appointment\n");
		printf("%20c%s",' ',"2.Add Appointment\n");
		printf("%20c%s",' ',"3.Search Appointment\n");
		printf("%20c%s",' ',"4.Modify Appointment\n");
		printf("%20c%s",' ',"5.Delete Appointment\n");
		printf("%20c%s",' ',"6.Display Doctor Schedule\n");
		printf("%20c%s",' ',"7.Save and Exit\n\n");
		printf("%20c%s",' ',"Enter choice : ");
		scanf(" %c", &choice);

		system("cls");

		if (choice == '1'){
			header("DISPLAY APPOINTMENT MODULE");
			displayAppointmentInList(appointment, appointSize);
		}
		else if (choice == '2'){
			
			appointSize = addAppointment(appointment, appointSize);
		}
		else if (choice == '3') {
			header("SEARCH APPOINTMENT MODULE");
			int i = searchAppointment(appointment, appointSize);
			if (i != -1)
				displayAppointmentDetail(appointment[i]);
		}
		else if (choice == '4'){
			header("MODIFY APPOINTMENT MODULE");
			modifyAppointment(appointment, appointSize);
		}
		else if (choice == '5'){
			header("DELETE APPOINTMENT MODULE");
			appointSize = deleteAppointment(appointment, appointSize);
		}
		else if (choice == '6') {
			Appointment matchedList[20];
			header("DISPLAY DOCTOR SCHEDULE");
			int listSize = generateList(NULL, appointment, appointSize, matchedList, -1);
			printf("\n");
			displayAppointmentInList(matchedList, listSize);
		}

		system("pause");
		system("cls");

	} while (choice != '7');
		
	fp = vfopen("Appointment.dat", "wb");
	fwrite(&appointment[0], sizeof(Appointment), appointSize, fp);
	fclose(fp);

	return 0;
}

void displayAppointmentInList(Appointment list[], const int size) {

	int i;

	printf("%20c+----------------------+-----------------+-----------+-----------------+-------+\n",' ');
	printf("%20c|%22s|%17s|%11s|%17s|%7s|\n", ' ', "APPOINT. TIME", "NAME", "ID", "DOCTOR", "REMARKS");
	printf("%20c+----------------------+-----------------+-----------+-----------------+-------+\n",' ');

	for (i = 0;i < size;i++)
		printf("%20c|%10s %5s-%5s|%17s|%11s|%17s|%7s|\n",
			' ',list[i].appointStart.date, list[i].appointStart.time, list[i].appointEnd.time,
			list[i].patientName, list[i].patientId, list[i].preferedDoc,
			strcmp(list[i].remark, "N/A") == 0 ? "N/A" : "AVAIL.");

	printf("%20c+----------------------+-----------------+-----------+-----------------+-------+\n",' ');
	printf("\n");
}

int addAppointment(Appointment appoint[], const int appointSize) {

	char choice;
	int listSize;
	Appointment temp, list[20];
	time_t today;
	struct tm *todayDate = NULL;

	do {
		system("cls");
		header("ADD APPOINTMENT MODULE");

		listSize = generateList(&temp, appoint, appointSize, list, -1);
		printf("\n");
		displayAppointmentInList(list, listSize);

		printf("%-30s: ", "Add appointment ? y/n ");
		scanf(" %c", &choice);

		while (choice != 'n' && choice != 'y'){
			printf("INVALID INPUT!\n");

			rewind(stdin);
			printf("%-30s: ", "Add appointment ? y/n ");
			scanf(" %c", &choice);
		}
		if(choice == 'n')
			return appointSize;
	} while (checkTimeOverlap(&temp, list, listSize) == 0); //to go back enter the date again

	printf("%-30s: ", "Enter the patient name ");
	scanf(" %[^\n]", temp.patientName);

	printf("%-30s: ", "Enter the patient ID ");
	scanf(" %s", temp.patientId);

	printf("%-30s: ", "Enter remarks (x to skip) ");
	scanf(" %[^\n]", temp.remark);
	if (strcmp(temp.remark, "x") == 0)
		strcpy(temp.remark, "N/A");

	printf("%-30s: ", "Enter your name ");
	scanf(" %[^\n]", temp.name);

	time(&today);                   //Calculate calender time in second since 1970
	todayDate = localtime(&today);  //Encode into tm type
	sprintf(temp.today.date, "%02d/%02d/%04d",
		todayDate->tm_mday, todayDate->tm_mon + 1, todayDate->tm_year + 1900);
	sprintf(temp.today.time, "%02d:%02d",
		todayDate->tm_hour, todayDate->tm_min);

	appoint[appointSize] = temp;   //Assign into the array
	printf("ADD SUCCESSFULLY!\n\n");
	return appointSize + 1;
}

int searchAppointment(Appointment appoint[], const int size) {
	int i;
	char search[9];

	printf("Enter the patient ID to search : ");
	scanf(" %s", search);

	for (i = 0;i < size;i++) 
		if (strcmp(appoint[i].patientId, search) == 0) 
			return i;

	printf("RECORD NOT FOUND!\n\n");
	return -1;
}

void displayAppointmentDetail(Appointment appoint) {
	printf("The detail of the appointment is as below\n\n");
	printf("\t%-30s:%30s\n", "NAME", appoint.patientName);
	printf("\t%-30s:%30s\n", "PATIENT ID", appoint.patientId);
	printf("\t%-30s:%14s%10s %5s\n", "APPOINT. TIME", "", appoint.appointStart.date, appoint.appointStart.time);
	printf("\t%-30s:%30s\n", "PREFERRED DOC", appoint.preferedDoc);
	printf("\t%-30s:%30s\n", "REMARKS", appoint.remark);
	printf("\t%-30s:%30s\n", "REGISTERED BY", appoint.name);
	printf("\t%-30s:%14s%10s %5s\n\n", "REGISTERED ON", "", appoint.today.date, appoint.today.time);
}

void modifyAppointment(Appointment appoint[], int appointSize) {
	char input;
	Appointment temp;  //Temporary variable to store the data 

	const int i = searchAppointment(appoint, appointSize);

	if (i == -1)
		return;        //Exit function if not found

	temp = appoint[i]; //Any changes will just on temp first
	do {
		system("cls");
		header("MODIFY APPOINTMENT MODULE");

		displayAppointmentDetail(temp);

		printf("1.Patient Name\n");
		printf("2.Prefered Doctor and Appointment Time\n");
		printf("3.Remarks\n");
		printf("4.Save and Exit\n");
		printf("5.Discard and Exit\n");
		printf("Please choose what to modify: ");
		scanf(" %c", &input);

		if (input == '1') {
			printf("%-30s: ", "Enter the patient name ");
			scanf(" %[^\n]", temp.patientName);
		}
		else if (input == '2') {
			Appointment list[20];
			int listSize;
			do {
				listSize = generateList(&temp, appoint, appointSize, list, i);
				printf("\n");
				displayAppointmentInList(list, listSize);
			} while (checkTimeOverlap(&temp, list, listSize) == 0);
		}
		else if (input == '3') {
			printf("%-30s: ", "Enter remarks (x to skip)");
			scanf(" %[^\n]", temp.remark);
			if (strcmp(temp.remark, "x") == 0)
				strcpy(temp.remark, "N/A");
		}
		else if (input == '4') {
			appoint[i] = temp; //Assign the changed data back into the array
			printf("Appointment modify!\n\n");
		}
		else if (input == '5')
			printf("Discarding changes!\n\n");
		else
			printf("Invalid Input!\n");
	} while (input != '4'&&input != '5');
}

int deleteAppointment(Appointment appoint[], int size) {
	char choice;

	int i = searchAppointment(appoint, size); //Searching for the ID

	if (i == -1)
		return size; //Exit function if record does not exist

	displayAppointmentDetail(appoint[i]);

	printf("Are you sure want to delete ? (y/n) : ");
	scanf(" %c", &choice);

	if (choice != 'y')
		return size;
	else  
		while (i < size - 1) {
			appoint[i] = appoint[i + 1];   //Shifting the member
			i++;
		}
	return size-1;
}

int generateList(Appointment* temp, Appointment appoint[], const int size, Appointment list[], int current) {
	/*Variable current is passed so that the appointment wont be stored in list
	**So application such as an appointment is to be postpone 30minutes is allowed
	**Storing -1 means all matching result will be stored
	**/
	int i = 0, j = 0;
	int day, month, year;
	char date[11], doctor[20];

	rewind(stdin);
	printf("%-40s: ", "Enter appointment date(dd/mm/yyyy) ");
	scanf("%d%*c%d%*c%d", &day, &month, &year);
	
	while (getValidDate(day, month, year) == 0){ //When it is not valid
		printf("Invalid!\n");
		printf("%-40s: ", "Enter appointment date(dd/mm/yyyy) ");
		scanf("%d%*c%d%*c%d", &day, &month, &year);
	}

	sprintf(date, "%02d/%02d/%04d", day, month, year);

	printf("%-40s: ", "Enter preferred doctor ");
	scanf(" %[^\n]", doctor);

	for (i = 0; i < size; i++)
		if(i == current)
			continue; //The appointment being modified wont stored inside
		else if (strcmp(date, appoint[i].appointStart.date) == 0 && strcmp(doctor, appoint[i].preferedDoc) == 0)
			list[j++] = appoint[i]; //Copy the matched struct into another array

	if (temp != NULL) {             //If temp is not NULL, assign string into it
		strcpy(temp->appointStart.date, date);
		strcpy(temp->preferedDoc, doctor);
	}

	return j;
}

int checkTimeOverlap(Appointment *source, Appointment list[], const int size) {
	/*Get the start time and end time and check does the period overlapped other appointment*/
	int hour, min;
	Appointment temp = *source;

	printf("%-30s: ", "Enter the start time hh:mm ");
	scanf("%d%*c%d", &hour, &min);
	
	while (getValidTime(hour, min) == 0){
		printf("Invalid!\n");
		printf("%-30s: ", "Enter the start time hh:mm ");
		scanf("%d%*c%d", &hour, &min);
	}

	sprintf(temp.appointStart.time, "%02d:%02d", hour, min);

	printf("%-30s: ", "Enter the end time hh:mm ");
	scanf("%d%*c%d", &hour, &min);
	sprintf(temp.appointEnd.time, "%02d:%02d", hour, min);
	
	while (getValidTime(hour, min) == 0 || strcmp(temp.appointEnd.time, temp.appointStart.time) != 1){
		printf("Invalid!\n");
		printf("%-30s: ", "Enter the end time hh:mm ");
		scanf("%d%*c%d", &hour, &min);
		sprintf(temp.appointEnd.time, "%02d:%02d", hour, min);
	}

	for (int i = 0;i < size;i++) {
		//(StartA <= EndB)  and  (EndA >= StartB)
		if ((strcmp(temp.appointStart.time, list[i].appointEnd.time) == -1) && (strcmp(temp.appointEnd.time, list[i].appointStart.time) == 1)) {
			printf("TIME SLOT OCCUPIED!!\n\n");
			system("pause");
			return 0; //return false
		}
	}

	*source = temp;   //If does not return from above, assign back
	return 1;        //return true
}