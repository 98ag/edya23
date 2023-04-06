#include <stdio.h>
#include <stdlib.h>

void bubble_sort(float arreglo[], int longitud) {
  for (int iter = 0; iter < longitud - 1; iter++) {
    for (int i = 0; i < longitud - iter - 1; i++) {
      if (arreglo[i] > arreglo[i + 1]) {
        float aux = arreglo[i];
        arreglo[i] = arreglo[i + 1];
        arreglo[i + 1] = aux;
      }
    }
  }
}

float mediana(float *arreglo, int longitud) {
    float* arr;
    arr = malloc(sizeof(float) * longitud);
    for(int i = 0; i < longitud; arr[i] = arreglo[i], i++);

    bubble_sort(arr, longitud);

    int halflen = longitud/2;

    float ret = ((longitud % 2) ? (arr[halflen]) : ((arr[halflen] + arr[(halflen) - 1]) / 2));
    free(arr);
    return ret;
}

int main(float argarr[]) {
    float arr[] = {-1.0, 2.2, 2.9, 3.5, 3.5, 4.2};
    printf("Media: %.2f\n", mediana(arr, 6));
    return 0;
}
