#include <stdio.h>
void checkSet(int arr[], int arrSize)
{
	if(arrSize < 1) printf("Array cannot be enmpty!\n");
	return;
}

int findIntersection(int arr1[], int arrSize1, int arr2[], int arrSize2)
{
	int intersec = 0;
	for(int i = 0; i < arrSize1; i++)
	{
		for(int j = 0; j < arrSize2; j++)
		{
			if(arr1[i] == arr2[j] && arr1[i] != -1)
			{
				intersec++;
				arr1[i] = -1;
				arr2[j] = -1;
			}
		}
	}
	return intersec;
}

int findUnion(int arr1[], int arrSize1, int arr2[], int arrSize2)
{
	int distinct = 0;
	int checkArr[arrSize1 + arrSize2];
	int checkIndex = 0;
	for(int i = 0; i < arrSize1; i++)
	{
		for(int j = 0; j < (arrSize1+arrSize2); j++)
		{
			if(arr1[i] == checkArr[j]) break;
			checkArr[checkIndex] = arr1[i];
			checkIndex++;
			distinct++;
			break;
		}
	}
	for(int i = 0; i < arrSize2; i++)
	{
		for(int j = 0; j < (arrSize1+arrSize2); j++)
		{
			if(arr2[i] == checkArr[j]) break;
			checkArr[checkIndex] = arr2[i];
			checkIndex++;
			distinct++;
			break;
		}
	}
	return distinct;
}

void calculateJaccard(int arr1[], int arrSize1, int arr2[], int arrSize2)
	{

	checkSet(arr1, arrSize1);
	checkSet(arr2, arrSize2);

	int intersect = findIntersection(arr1, arrSize2, arr2, arrSize2);
	int distinct = findUnion(arr1, arrSize2, arr2, arrSize2);
	printf("Jaccard Similarity is %f", (float)(intersect/distinct));
	}

void main()
{
	int arrSize1, arrSize2 = 0;
	printf("Input size of set 1: ");
	scanf("%d", &arrSize1);
	
	int arr1[arrSize1];
	printf("Input Set 1: ");
	for(int i = 0; i < arrSize1; i++)
	{
		scanf("%d", &arr1[i]);
	}

	printf("Input size of set 2: ");
	scanf("%d", &arrSize2);

	int arr2[arrSize2];
	printf("Input Set 2: ");
	for(int i = 0; i < arrSize2; i++)
	{
		scanf("%d", &arr2[i]);
	}
	
	calculateJaccard(arr1, arrSize1, arr2, arrSize2);
}
