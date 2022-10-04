#include <stdlib.h>

typedef struct {
int* array;
int used;
int size;
} dynmArray;

void initArray(dynmArray* a, int size)
{
	a->array = malloc(size * sizeof(int));
	a->used = 0;
	a->size = size;
}

void insertArray(dynmArray* a, int element)
{
	if(a->size == a->used)
	{
		a->size = a->size*2;
		a->array = realloc(a->array, a->size * sizeof(int));
	}
	a->array[a->used++] = element;
}


