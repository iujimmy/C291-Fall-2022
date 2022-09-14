#include <stdio.h>
#include <stdbool.h>

int main(){
	int number = 0;
	printf("Please input a number to find the reverse binary for: ");
	scanf("%d", &number);
	
	int binList[16] = {-1};
	int binListRev[16];

	if(number < 1) {
		printf("Error: cannot find reverse binary of a negatvie: %d",number);
		return 1;
	}
	for(int i = 0; number > 0; i++)
	{
		binList[i] = number % 2;
		number = number / 2;
	}

	int zeroCounter = 0;
	bool leadingZero = true;
	printf("Output: ");
	for( int j = 15; j >= 0; j--)
	{
		if(binList[j] == 1) leadingZero = false;
		if(binList[j] == 0 && leadingZero == true){
			zeroCounter++;
		       	continue;
		}
	//	printf("%d", binList[j]);
	}
	for (int i = 0; i <= 15-zeroCounter; i++)
	{
		printf("%d", binList[i]);
	}
}	

