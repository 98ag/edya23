#include<stdio.h>

int binsearch(int a[], int len, int v) {
  int low = 0, high = len - 1, mid;

  while (low <= high) {
    mid = (low + high) / 2;
    if (a[mid] == v)
      return mid;
    else if(a[mid] < v)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

int main() {
  //             0  1  2  3   4    5   6    7    8    9
  int arr[10] = {1, 2, 5, 7, 22, 50, 189, 599, 925, 1095};
  int busq = 925;
  printf("Indice de %d: %d\n", busq, binsearch(arr, 10, busq));
  return 0;
}