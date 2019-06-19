/*
 * Name: shared.c
 * Description: Stores functions shared between modules
 */

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

/*
 * Function name: vfopen
 * Purpose: Accepts a file path and a mode, then open a file and return a pointer to the file. If fail, print the file causing the error and exit.
 */
FILE* vfopen(char filePath[], char mode[])
{
	FILE* fp;
	fp = fopen(filePath, mode);
	if (fp == NULL)
	{
		printf("%s file cannot be opened, please ensure the file exists and you have sufficient permissions\n", filePath);
		system("pause");
		exit(-1);
	}
	return fp;
}

//fp = vfopen("supplies.dat", "wb");

void header(char s[]) {
	int len = strlen(s);
	char str[30];
	strcpy(str,s);
	
	if(strlen(str) % 2 == 1)
		strcat(str," ");
		
	len = (78 - len) / 2;
	
	printf("%20c+------------------------------------------------------------------------------+\n",' ');
	printf("%20c|%*s%s%*s|\n",' ',len," ", str, len, " ");
	printf("%20c+------------------------------------------------------------------------------+\n\n",' ');
}

int getValidDate(int day, int month, int year) {
	int maxDay[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 && year % 3200 != 0))
		maxDay[1]++;

	if (year < 1900 || year > 2019 || month < 1 || month > 12 || day < 1 || day > maxDay[month - 1]) 
		return 0;
	else
		return 1;
}

int getValidTime(int hour, int min) {
	if(hour < 0 || hour>24 || min < 0 || min >= 60) 
		return 0;
	else
		return 1;
}

void homescreen(void) {

	printf("ooooo   ooooo   .oooooo.   ooooo        oooooo   oooo      .oooooo.   oooo   o8o               o8o \n"
		" 888     888   d8P'  `Y8b  `888'         `888.   .8'      d8P'  `Y8b  `888   `\"'               `\"'\n"
		" 888     888  888      888  888           `888. .8'      888           888  oooo  ooo. .oo.   oooo   .ooooo.\n"
		" 888ooooo888  888      888  888            `888.8'       888           888  `888  `888P\"Y88b  `888  d88' `\"Y8\n"
		" 888     888  888      888  888             `888'        888           888   888   888   888   888  888\n"
		" 888     888  `88b    d88'  888       o      888         `88b    ooo   888   888   888   888   888  888   .o8\n"
		"o888o   o888o  `Y8bood8P'  o888ooooood8     o888o         `Y8bood8P'  o888o o888o o888o o888o o888o `Y8bod8P'\n\n\n");
}