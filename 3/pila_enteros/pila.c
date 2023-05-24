#include"pila.h"
#include<stdio.h>
#include<stdlib.h>

Pila pila_crear(int capacidad) {
  Pila new = malloc(sizeof(struct _Pila));
  new->arr = arreglo_enteros_crear(capacidad);
  new->ultimo = 0;
  return new;
}

void pila_destruir(Pila pila) {
  arreglo_enteros_destruir(pila->arr);
  free(pila);
}

int pila_es_vacia(Pila pila) {
  return (pila->ultimo) ? 0 : 1;
}

int pila_tope(Pila pila) {
  return arreglo_enteros_leer(pila->arr, pila->ultimo - 1);
}

void pila_apilar(Pila pila, int dato) {
  int cap = arreglo_enteros_capacidad(pila->arr);
  if (pila->ultimo + 1 == cap) {
    arreglo_enteros_ajustar(pila->arr, cap * 2);
  }

  arreglo_enteros_escribir(pila->arr, pila->ultimo, dato);
  pila->ultimo++;
}

void pila_desapilar(Pila pila) {
  pila->ultimo--;
}

void pila_imprimir(Pila pila) {
  for (int i = pila->ultimo - 1; i >= 0; i--) {
    printf("%d\n", arreglo_enteros_leer(pila->arr, i));
  }
}
