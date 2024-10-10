#include<stdio.h>

int main()
{
  int arraySize;
  printf("Enter the size of the array: ");
  scanf("%d", &arraySize);

  int arr[arraySize];
  printf("Enter the %d elements in the array: ", arraySize);
  for(int i = 0; i < arraySize; i++)
  {
    scanf("%d", &arr[i]);
  }

  int midIndex = (arraySize-1)/2;

  for(int i = midIndex; i < arraySize; i++)
  {
    arr[i] = arr[i+1];
  }

  printf("Array after deleting the mid element: ");
  for(int i = 0; i < arraySize-1; i++)
  {
    printf("%d ", arr[i]);
  }
  
  return 0;
}