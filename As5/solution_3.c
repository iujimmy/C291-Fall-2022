#include <stdio.h>
#include "dynamicArray.h"

dynmArray array;

void printUniqueElements(int elements[], int lenArray){
	for(int i = 0; elements[i] != '\0'; i++)
	{
		for(int j = 0; elements[j] != '\0'; j++)
		{
			if(elements[i] == elements[j] && i != j) break;
			if(elements[j+1] == '\0') {
				printf("%d ", elements[i]);
			}
		}
	}

}

void main()
{
	int size = 100;
	initArray(&array, size);

	printf("Input Size of Array: ");
	scanf("%d", &size);
	printf("Inputs: ");
	for(int i = 0; i < size; i++)
	{
		static int tempInt = 0;
		scanf("%d", &tempInt);
		insertArray(&array, tempInt);
	}
	printUniqueElements(array.array, size);
}
