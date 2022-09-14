#include <stdio.h>
#include <stdbool.h>

int main(){

	int year;

	printf("Please enter a year: ");
	scanf("%d",&year);
	
	int month;

	printf("Please enter a month: ");
	scanf("%d",&month);

	int day;

	printf("Please enter a day: ");
	scanf("%d",&day);
	
	bool isValid = true;
	bool isLeap = false;
	if((year % 4 == 0) || (year % 400 == 0)){
	isLeap = true; 
	}
	if(day > 31 || day < 1) isValid = false;
	if(month > 12 || month < 1) isValid = false;

	printf("The date is: ");
	printf(isValid ? "valid!\n" : "not valid\n");
	}
