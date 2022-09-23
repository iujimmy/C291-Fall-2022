
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
bool isPerfectNumber(int num)
{
	int totalFactors = 0;
	for(int i = 1; i < num; i++)
	{
		if(num % i == 0)
		{
			totalFactors += i;
		}
	}
	return (totalFactors == num);
}

int main()
{
	int num;

	printf("Enter a postive integer value: ");
	scanf("%d", &num);

	bool isPerfect =  isPerfectNumber(num);
	printf("%d",num);
	printf(isPerfect ? (" is a perfect number\n") : (" is not a perfect number\n"));
} 


