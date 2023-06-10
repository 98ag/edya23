#include "gpila.h"
#include <stdlib.h>

Pila pila_crear() {
  return glist_crear();
}

void pila_destruir(Pila pila, FuncionDestructora f) {
  glist_destruir(pila, f);
}

int pila_es_vacia(Pila pila) {
  return glist_vacia(pila);
}

void *pila_tope(Pila pila) {
  return pila->data;
}

Pila pila_apilar(Pila pila, void *dato, FuncionCopia c) {
  return glist_agregar_inicio(pila, dato, c);
}

Pila pila_apilar_nodo(Pila pila, void *ptr) {
  return glist_agregar_inicio_nodo(pila, ptr);
}

Pila pila_desapilar(Pila pila, FuncionDestructora f) {
  if (pila != NULL) {
    GNode *aux = pila;
    f(pila->data);
    pila = pila->next;
    free(aux);
  }
  return pila;
}

Pila pila_desapilar_nodo(Pila pila) {
  if (pila != NULL) {
    GNode *auxFree = pila;
    pila = pila->next;
    free(auxFree);
  }
  return pila;
}

void pila_imprimir(Pila pila, FuncionVisitanteList v) {
  glist_recorrer(pila, v);
}