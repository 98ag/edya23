#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void *int_copiar(void *dato) {
  int *new = malloc(sizeof(int));
  *new = *(int *)dato;
  return (void *)new;
}

static int int_comparar(void *dato1, void *dato2) {
  return *(int *)dato1 - *(int *)dato2;
}

static void int_destruir(void *dato) {
  free((int *)dato);
}

static void int_printear(void *dato) {
  printf("%d ", *(int *)dato);
}

int main() {
  srand(time(NULL));

  int **arr = malloc(sizeof(int *) * 10);

  for (int i = 0; i < 10; i++) {
    arr[i] = malloc(sizeof(int));
    *arr[i] = rand() % 20;
  }

  BHeap heap = bheap_crear_desde_arr((void *)arr, 10, int_copiar, int_comparar, int_printear);
  bheap_recorrer(heap, int_printear);
  puts("");
  for (int i = 0; i < 10; i++) {
    free(arr[i]);
  }
  free(arr);

  bheap_destruir(heap, int_destruir);

  return 0;
}