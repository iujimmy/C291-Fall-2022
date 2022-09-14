
#include <stdio.h>
#include <stdbool.h>

int main(){
	int number = 0;
	printf("Please enter number of rows: ");
	scanf("%d", &number);
	
	if(number < 1 || number % 2 == 0) {
		printf("Error: cannot make a star  of a negatvie or even number: %d",number);
		return 1;
	}

	for(int line = 0; line < (number/2)+1; line++)
	{
	for(int i = 0; i<(number/(2))-line; i++)
	{
		printf(" ");
	}
	for(int s = 0; s < 1+(line*2); s++)
	{
		printf("*");
	}
	for(int i = 0; i<(number/(2))-line; i++)
	{
		printf(" ");
	}
	printf("\n");
	}

	
	for(int line = (number/2)+2; line <= number; line++)
	{
	for(int i = 0; i<(line-((number/2)+1)); i++)
	{
		printf(" ");
	}
	for(int s = 0; s < number-((line-((number/2)+1))*2); s++)
	{
		printf("*");
	} 
	for(int i = 0; i<(line-((number/2)+1)); i++)
	{
		printf(" ");
	}
	printf("\n");
	}
		
}
