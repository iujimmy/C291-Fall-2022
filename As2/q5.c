
#include <stdio.h>

#include <math.h>
int main()
{
	int monthly, hours;
	char type, married;
	printf("Please Enter Employee Type: ");
	scanf("%c",&type);
	printf("Please Enter Monthly Salary: ");
	scanf("%d",&monthly);
	printf("Is the Employee Married?: ");
	scanf("%c",&married);
	printf("--------------------------\n");

	int hoursWorked;
	int income;
	if(!(type == 'H')){
	       	printf("Your salary is %d!\n", monthly*12);
		income = monthly * 12;
	}
	if(type == 'H')
	{
		printf("How many hours did you work per month?\n");
		scanf("%d", &hoursWorked);
		printf("Your slary is %d!\n", hoursWorked*12*15);
		income = hoursWorked*12*15;
	}
	if(married)
	{
		if(income > 32000) printf("You must pay %f in taxes!",income * 0.25);
	}else {
		if(income <= 32000) printf("You must pay %f in taxes!",income * 0.10);

	}
	if(!married)
	{
		if(income > 64000) printf("You must pay %f in taxes!",income * 0.25);
	}else {
		if(income <= 64000) printf("You must pay %f in taxes!",income * 0.10);
	}
}
