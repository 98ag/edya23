#include<stdlib.h>
#include<stdio.h>

int* merge(int *arr1, int len1, int *arr2, int len2) {
  int *new = malloc(sizeof(int) * (len1 + len2));
  int index1 = 0, index2 = 0;
  int doneleft = 0, doneright = 0;

  for (int i = 0; i < len1 + len2; i++) {
    if (doneleft || (!doneright && (arr1[index1] <= arr2[index2]))) {
      new[i] = arr1[index1];
      index1++;
    }
    else {
      new[i] = arr2 [index2];
      index2++;
    }
    doneleft = (index1 == len1) ? 1 : 0;
    doneright = (index2 == len2) ? 1 : 0;
  }
    /* if (index1 == index2) {
      nuevo[i] = arr2[index2];
      index2++;
    }
    else if (index2 == len2) {
      nuevo[i] = arr1[index1];
      index1++;
    }
    else if (arr1[index1] < arr2[index2]) {
      nuevo[i] = arr1[index1];
      index1++;
    }
    else {
      nuevo[i] = arr2[index2];
      index2++;
    }
  } */
  if (len1 > 1) free(arr1);
  if (len2 > 1) free(arr2);
  return new;
}

int* mergeSort(int *arr, int length) {
  if (length < 2)
    return arr;
  else {
    int mid = length/2;
    int *midarr = &(arr[mid]);
    int *B1 = mergeSort(arr, mid);
    int *B2 = mergeSort(midarr, length - mid);
    return merge(B1, mid, B2, length - mid);
  }
}

int main() {
  int arr1[] = {5, 9, 2, 1, 4, 0, 6, 3, 8, 7};
  int len = 10;

  int *sorted = mergeSort(arr1, len);

  for(int i = 0; i < len; i++) {
    printf("%d ", sorted[i]);
  }
  puts("");
  free(sorted);
  return 0;
}