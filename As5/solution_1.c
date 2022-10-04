#include <stdio.h>

void printKGrams(int l, int k, char kGrams[][k+1])
{
	
	for(int i = 0; i < l - k + 1; i++)
	{
		for(int j = 0; j < k; j++)
		{
			printf("%c", kGrams[i][j]);
		}
		printf("\n");
	}
}

void generateKGrams(int n, int k, char kGrams[][k+1], char input[], int l)
{
	n = l - k + 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < k; j++)
		{
			kGrams[i][j] = input[(i*k)+(j)];
		}
	}	
	printKGrams(l, k, kGrams);
}

int length(char str[])
{
	for(int i = 0; str[i] != "\0"; i++)
	{
	if(str[i] == "\0" || str[i] == 0) return i+1;	
	}
	return 0;
}

void main()
{
	char str[256] = {0};
	printf("Input a string: ");
	scanf("%s", str);
	int k = 0;
	printf("Input value of k: ");
	scanf("%d",&k);

	int strLen = length(str);
	char kGrams[(strLen-k)+1][k+1];

	generateKGrams(0, k, kGrams, str, strLen);

}
