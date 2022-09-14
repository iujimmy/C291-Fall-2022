#include <stdio.h>

int main()
{
	int number = 0;
	printf("Please input a starting Fizz Buzz number: ");
	scanf("%d", &number);

	if(number < 1) {
		printf("Error: cannot computer Fizz Buzz of: %d",number);
		return 1;
	}

	int printCounter = 0;
	for(int i = number; i>0; i--)
	{
		if(i % 3 == 0 && i % 5 == 0)
		{
			printf("Fizz-Buzz ");
			if(printCounter == 3){
				printf("\n");
				printCounter = 0;
			}else printCounter++;
		continue;
		}
		if(i % 5 == 0){
			printf("Buzz ");
			
			if(printCounter == 3){
				printf("\n");
				printCounter = 0;
			}else printCounter++;
		continue;
		}	
		if(i % 3  == 0){
			printf("Fizz ");
			
			if(printCounter == 3){
				printf("\n");
				printCounter = 0;
			}else printCounter++;
		continue;
		}
		printf("%d ", i);
			if(printCounter == 3){
				printf("\n");
				printCounter = 0;
			}else printCounter++;
	}

	return 1;
}


