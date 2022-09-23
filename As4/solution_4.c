
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int rollDice(void) {
	return (rand()%7)+1;
}

int getSum(int a,int b){
	return a + b;
}

void checkCraps(int point){
	printf("Your point is %d....\n", point);
	int prevScore = 0;
	int dice1 = rollDice();
	int dice2 = rollDice();
	int currentSum = getSum(dice1, dice2);
	printf("Score on dice are %d and %d\n", dice1, dice2);
	while(currentSum != prevScore){
		if(currentSum == 7)
		{
		printf("You lost because you rolled a 7\n");
		return;
		}
		if(currentSum == point)
		{
			printf("You rolled %d and won!\n", currentSum);
			return;
		}
		if(prevScore == currentSum){
			printf("You win with consecutive same score\n!");
			return;
		}
		prevScore = currentSum;
	}
}

void main()
{
	char ans;
	printf("Would you like to play a game of craps? Y or N: ");
	scanf("%c", &ans);
	if(ans != 'y') return;

	srand(time(NULL));
	printf("Dice are rolling....\n");

	int dice1 = rollDice();
	int dice2 = rollDice();
	int currentSum = getSum(dice1, dice2);

	printf("Score on dice are %d and %d\n", dice1, dice2);
	
	if(currentSum == 7 || currentSum == 11){
		printf("You are the winner!\n");
		return;
	}else if (currentSum == 2 || currentSum == 3 || currentSum == 12){
		printf("House is the winner!\n");
		return;
	}
	checkCraps(currentSum);
	return;
	
}

