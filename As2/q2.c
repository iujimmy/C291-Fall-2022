#include <stdbool.h>
#include <stdio.h>

int main()
{
	int ang1;

	printf("Please enter a first angle: ");
	scanf("%d",&ang1);
	
	int ang2;

	printf("Please enter a second angle: ");
	scanf("%d",&ang2);

	int ang3;

	printf("Please enter a thrid angle: ");
	scanf("%d",&ang3);
	
	bool isValid = false;
	bool isAcute = false;
	bool isEqual = false;
	bool isIso = false;
	bool isRight = false;
	if(ang1 > 0 && ang2 > 0 && ang3 > 0) {
		if(ang1 + ang2 + ang3 == 180) isValid = true;

		isAcute = false;
		if(ang1 < 90 && ang2 < 90 && ang3 < 90){
			isAcute = true;
		}
		isAcute = false;
		if(ang1 == ang2 || ang1 == ang3 || ang2 == ang3){
		isIso = true;
		}		
		isRight = false;
		if(ang1 == 90 || ang2 == 90 || ang3 == 90){
			isRight = true;
		}
		isEqual = false;
		if(ang1 == ang2 == ang3){
		isEqual = true;
		isIso = false;
		isRight = false;
		}
	}
	if(!isValid){
		printf("Triangle is invalid!\n");
		return;
	}
	if(isAcute){
		printf("Triangle is acute!\n");
	}
	if(isRight){
		printf("Triangle is right!\n");
	}
	if(isIso){
		printf("Triangle is Isosceles!\n");
	}

}
		
