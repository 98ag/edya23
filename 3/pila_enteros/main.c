#include<stdio.h>
#include"pila.h"

int main() {
  Pila pila = pila_crear(3);

  printf("Es vacia?: %d\nCapacidad: %d\n", pila_es_vacia(pila), pila->arr->capacidad);
  printf("Apilo elementos\n");
  pila_apilar(pila, 1);
  pila_apilar(pila, 2);
  pila_apilar(pila, 3);

  pila_imprimir(pila);
  puts("");

  printf("Desapilo el ultimo\n");
  pila_desapilar(pila);
  pila_imprimir(pila);
  puts("");

  printf("Apilo mas elementos para probar aumento de capacidad\n");
  pila_apilar(pila, 3);
  pila_apilar(pila, 4);
  pila_apilar(pila, 5);
  pila_apilar(pila, 6);
  pila_apilar(pila, 7);

  printf("Es vacia?: %d\nCapacidad: %d\n", pila_es_vacia(pila), pila->arr->capacidad);
  pila_imprimir(pila);

  printf("Tope de pila: %d\n", pila_tope(pila));
  
  pila_destruir(pila);
  return 0;
}