
#include <stdio.h>

int main()
{
	int prime = 0;
	printf("Please enter a prime number: ");
	scanf("%d", &prime);

	if(prime == 0 || prime == 1)
	{
		printf("0 and 1 have no prime factors!\n");
		return 1;
	}

	printf("The prime factors for %d : ", prime);
	for(int i = 2; i <= prime; i++)
	{
		if(prime % i == 0){
			printf("%d ",i);
			prime = prime / i;
			i--;
		}
	}
	return 1;
}

