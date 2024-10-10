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

  int midItem;
  printf("Enter the item you want to insert in the mid of the array: ");
  scanf("%d", &midItem);

  int midIndex = (arraySize-1)/2;
  arr[midIndex] = midItem;

  printf("Updated Array: ");
  for(int i = 0; i < arraySize; i++)
  {
    printf("%d ", arr[i]);
  }
}