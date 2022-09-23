#include <stdio.h>
#include <math.h>

static int commonDivider = -1;
int findGCD(int num1, int num2,int startingNum)
{
	//if incr is big than nums return highest value
	//set highest value when u gety a good %
	//inc
	if(num1 % startingNum == 0 && num2 % startingNum == 0) 
	{
		commonDivider = startingNum;
//	printf("set commondiv!\n");
	}
	if(startingNum > num1 || startingNum > num2)
	{
		return commonDivider;
	}
//	printf("recirsion!\n");
	return findGCD(num1,num2,startingNum+1);
}

int main()
{
	int num1, num2;

	printf("Enter first postive integer value: ");
	scanf("%d", &num1);
	printf("Enter second positve integer value: ");
	scanf("%d", &num2);

	int startingNum = 1;
	int gcd = findGCD(num1, num2, startingNum);
	printf("GCD of %d and %d is %d", num1, num2, gcd);
}
