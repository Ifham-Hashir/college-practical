#include<stdio.h>

int main()
{
  int arraySize;
  printf("Enter the size of the array: ");
  scanf("%d", &arraySize);

  int arr[arraySize];
  printf("Enter the %d elements in the ascending order: ", arraySize);
  for(int i = 0; i < arraySize; i++)
  {
    scanf("%d", &arr[i]);
  }

  int item;
  printf("Enter the item you want to find in the array: ");
  scanf("%d", &item);

  int index;
  int left = 0;
  int right = arraySize-1;

  while(left <= right)
  {
    int mid = (left+right)/2;
    if(arr[mid] == item)
    {
      printf("Item found at index: %d", mid+1);
      return 0;
    }
    else if (arr[mid] < item)
    {
      left = mid+1;
    }
    else
    {
      right = mid-1;
    }
    
  }
  printf("Item not found in the array.");
  return 0;
}