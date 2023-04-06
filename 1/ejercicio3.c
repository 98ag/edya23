#include<stdio.h>
#include<stdlib.h>

typedef struct {
  int *direccion;
  int capacidad;
} ArregloEnteros;

ArregloEnteros *arreglo_enteros_crear(int capacidad) {
  ArregloEnteros *ret;
  ret = malloc(sizeof(ArregloEnteros));

  ret->direccion = malloc(sizeof(int) * capacidad);
  ret->capacidad = capacidad;

  return ret;
}

void arreglo_enteros_destruir(ArregloEnteros * arreglo) {
  free(arreglo->direccion);
  free(arreglo);
}

int arreglo_enteros_leer(ArregloEnteros * arreglo, int pos) {
  return arreglo->direccion[pos];
}

void arreglo_enteros_escribir(ArregloEnteros * arreglo, int pos, int dato) {
  arreglo->direccion[pos] = dato;
}

int arreglo_enteros_capacidad(ArregloEnteros * arreglo) {
  return arreglo->capacidad;
}

void arreglo_enteros_imprimir(ArregloEnteros * arreglo) {
  int capacidad = arreglo->capacidad;
  for (int i = 0; i < capacidad; i++) {
    printf("%d\n", arreglo->direccion[i]);
  }
}

void arreglo_enteros_ajustar(ArregloEnteros * arreglo, int capacidad) {
  int *new = malloc(sizeof(int) * capacidad);
  int arrCapacidad = arreglo->capacidad;

  if (arrCapacidad > capacidad)
    for (int i = 0; i < capacidad; new[i] = arreglo->direccion[i], i++);
  else
    for (int i = 0; i < arrCapacidad; new[i] = arreglo->direccion[i], i++);

  free(arreglo->direccion);
  arreglo->direccion = new;
  arreglo->capacidad = capacidad;
}

void arreglo_enteros_insertar(ArregloEnteros * arreglo, int pos, int dato) {
  int cap = arreglo->capacidad;
  int newCap;
  int *new = NULL;

  if (cap > pos) {
    newCap = cap + 1;
    new = malloc(sizeof(int) * (newCap));

    for (int i = 0; i < newCap; i++) {
      if (i > pos)
        new[i] = arreglo->direccion[i - 1];
      else if (i == pos) {
        new[i] = dato;
      } else
        new[i] = arreglo->direccion[i];
    }
  }

  else {
    newCap = pos + 1;
    new = malloc(sizeof(int) * newCap);
    for (int i = 0; i < cap; new[i] = arreglo->direccion[i], i++);
    new[pos] = dato;
  }

  free(arreglo->direccion);
  arreglo->direccion = new;
  arreglo->capacidad = newCap;
}

void arreglo_enteros_eliminar(ArregloEnteros * arreglo, int pos) {
  int cap = arreglo->capacidad;
  int newCap = cap - 1;
  int *newArr = malloc(sizeof(int) * newCap);

  for (int i = 0; i < newCap; i++) {
    if (i >= pos)
      newArr[i] = arreglo->direccion[i + 1];
    else
      newArr[i] = arreglo->direccion[i];
  }

  free(arreglo->direccion);
  arreglo->direccion = newArr;
  arreglo->capacidad = newCap;
}



int main() {
  ArregloEnteros *test = arreglo_enteros_crear(3);
  arreglo_enteros_escribir(test, 0, 1);
  arreglo_enteros_escribir(test, 1, 2);
  arreglo_enteros_escribir(test, 2, 3);
  //arreglo_enteros_escribir(test, 3, 4);
  //arreglo_enteros_escribir(test, 4, 5);
  printf("Arreglo Viejo:\n");
  arreglo_enteros_imprimir(test);


  arreglo_enteros_insertar(test, 5, 8);
  printf("Arreglo Nuevo Insertar:\n");
  arreglo_enteros_imprimir(test);

  arreglo_enteros_eliminar(test, 2);
  printf("Arreglo Nuevo Eliminar:\n");
  arreglo_enteros_imprimir(test);

  return 0;
}
