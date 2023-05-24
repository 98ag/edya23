#include<stdio.h>
#include<stdlib.h>

void merge(int* arr, int left, int mid, int right) {
  int i, j, k;
  int size1 = mid - left + 1;
  int size2 = right - mid;

  int arr1[size1], arr2[size2];

  for(i = 0; i < size1; i++)
    arr1[i] = arr[left + i];
  for(j = 0; j < size1; j++)
    arr2[j] = arr[mid + 1 + j];

  i = 0;
  j = 0;
  k = left;

  while (i < size1 && j < size2) {
    if (arr1[i] <= arr2[j]) {
      arr[k] = arr1[i];
      i++;
    }
    else {
      arr[k] = arr2[j];
      j++;
    }
    k++;
  }

  while (i < size1) {
    arr[k] = arr1[i];
    i++;
    k++;
  }

  while (j < size2) {
    arr[k] = arr2[j];
    j++;
    k++;
  }
}

void mergesort(int* arr, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;

    mergesort(arr, left, mid);
    mergesort(arr, mid + 1, right);

    merge(arr, left, mid, right);
  }
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
  int arr[] = {1, 5, 7, 2, 4, 11, 29, 15, 20};
  int length = 9;

  printf("Dado el array \n");
  printArray(arr, length);

  mergesort(arr, 0, 8);

  printf("Ordenado es: \n");
  printArray(arr, length);
  
  return 0;
}