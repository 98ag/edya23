#include<stdio.h>
#include<time.h>

void insertionSort(int* arr, int length) {
  int aux;
  for (int i = 0; i < length; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (arr[j] > arr[j+1]){
        aux = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = aux;
      }
    }
  }
}

void insertionSortMod(int* arr, int length) {
  int aux, cont = 0;
  
  for (int i = 1; i < length; i++) {
    cont = 0;
    aux = arr[i];

    // Por cada elemento anterior a arr[i] que es mayor a el, aumento el contador
    for (int j = i - 1; j >= 0; j--) {
      if (arr[j] > arr[i]) {
        cont++;
      }      
      else 
        // Utilizo break ya que no tiene sentido seguir comparando si alguno no es mayor
        // (ya que el array esta ordenado antes del indice i)
        break;  
    }

    // Si contador > 1 muevo los elementos anteriores 1 a la derecha y el 
    // elemento a ordenar en la posicion correcta
    if (cont > 1) {
      for (int k = i; k >= i - cont + 1; k--) {
        arr[k] = arr[k - 1];
      }
      arr[i - cont] = aux;
    }

    // Si contador = 1 entonces solo hay que mover una posicion (el anterior)
    else if (cont == 1) {
      arr[i] = arr[i - 1];
      arr[i - 1] = aux;
    }
  }
}


int main() {
  clock_t start, end;
  double execution_time;

  int arr [200] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, -2, -1, 0, 1};

  start = clock();
  insertionSortMod(arr, 200);  
  end = clock();

  execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
  printf("Mod Insertion Sort Time: %f\n", execution_time);
  puts("");
  return 0;
}