#include <stdio.h>

int main()
{
	int arrSize1, arrSize2 = 0;
	printf("Input size of array 1: ");
	scanf("%d", &arrSize1);
	
	int arr1[arrSize1];
	printf("Input Array 1: ");
	for(int i = 0; i < arrSize1; i++)
	{
		scanf("%d", &arr1[i]);
	}

	printf("Input size of array 2: ");
	scanf("%d", &arrSize2);

	int arr2[arrSize2];
	printf("Input Array 2: ");
	for(int i = 0; i < arrSize2; i++)
	{
		scanf("%d", &arr2[i]);
	}

	int i = 0;
	int j = 0;
	int sortedIndex = 0;
	int sortedArr[arrSize1 + arrSize2];
	do
	{
			if(arr1[i] < arr2[j])
			{
				sortedArr[sortedIndex] = arr1[i];
				sortedIndex += 1;
				i++;
			}else if(arr2[j] < arr1[i]){
				sortedArr[sortedIndex] = arr2[j];
				sortedIndex += 1;
				j++;
			}else if(arr1[i] == arr2[j]){
				sortedArr[sortedIndex] = arr1[i];
				sortedIndex++;
				i++;
				sortedArr[sortedIndex] = arr2[j];
				sortedIndex++;
				j++;
			}
	printf("%d", sortedArr[i]);
	} while(i+1 < arrSize1);
}

