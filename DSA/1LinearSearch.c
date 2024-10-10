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

  int item;
  printf("Enter the item you want to find in the array: ");
  scanf("%d", &item);


  for(int i = 0; i < arraySize; i++)
  {
    if(arr[i] == item)
    {
      printf("Item found at index: %d", i+1);
      return 0;
    }
  }

  printf("Item not found in the array.");
  return 0;

}