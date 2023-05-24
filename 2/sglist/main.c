#include"sglist.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int compInt(int *dato1, int *dato2) {
  int num1 = *dato1;
  int num2 = *dato2;
  return (num2 - num1);
}

int* copyInt(int* num) {
  int* ret= malloc(sizeof(int));
  *ret = *num;
  return ret;
}

void printInt(int *num) {
  int dato = *num;
  printf("%d ", dato);
}

void freeInt(int *num) {
  free(num);
}

int main() {
  /**/
  srand(time(0));

  int **ptrNums;
  ptrNums = malloc(sizeof(int*) * 5);

  printf("Array de numeros aleatorios de 1 a 50:\n");
  for(int i = 0; i < 5; i++) {
    ptrNums[i] = malloc(sizeof(int));
    *ptrNums[i] = (rand() % (50)) + 1;
    printf("%d ", *ptrNums[i]);
  }
  puts("");
  /**/

  SGList lista = sglist_arr(
                      (void**)ptrNums, 
                      5, 
                      (FuncionCopia)copyInt, 
                      (FuncionComparadora)compInt);

  sglist_recorrer(lista, (FuncionVisitante)printInt);
  puts("");
  
  printf("Si se encuentra %d printea 1: %d\n", *ptrNums[4], sglist_buscar(lista, (void*)ptrNums[2], (FuncionComparadora) compInt));
  
  sglist_destruir(lista, (FuncionDestructora)freeInt);

  for(int i = 0; i < 5; i++) {
    free(ptrNums[i]);
  }
  free(ptrNums);

  return 0;
}