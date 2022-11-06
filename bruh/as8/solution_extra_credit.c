#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ArrayAny{
  void* data;
  size_t length;
  size_t data_size;
} ArrayAny;

ArrayAny* new_array(size_t len, int data_size)
{
  ArrayAny* arr = malloc(sizeof(ArrayAny));
  arr->data = malloc(len * data_size);
  arr->length = len;
  arr->data_size = data_size;

  for(int i = 0; i < len; i++){
      //*(arr->data + i*data_size) = -1;
      memset(arr->data + i*data_size, -1, data_size);
  }

  return arr;
}

void* array_get(ArrayAny* arr, int index, int data_size)
{
  void* value;
  memset(value, *(int*)(arr->data + index*data_size), data_size);
  return value;
}

/*
void array_set(ArrayAny* arr, int index, void* data, int data_size)
{
  //pointer math dref
  //*(arr->data + index) = value;
  memset(arr->data + index*data_size, data, data_size);
} */

void delete_array(ArrayAny* arr)
{
  free(arr);
}

void main()
{
    typedef struct testStruct{
      int num;
      char* myName;
    } testStruct;

    char* myName = "jimmy :)";
    testStruct myTestCase = {5, myName};

    size_t dataSize = 5;
    ArrayAny *myArr = new_array(1, dataSize);
  
}
