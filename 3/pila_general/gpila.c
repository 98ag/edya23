#include<stdlib.h>
#include"gpila.h"

Pila pila_crear() {
  return glist_crear();
}

void pila_destruir(Pila pila, FuncionDestructora f) {
  glist_destruir(pila, f);
}

int pila_es_vacia(Pila pila) {
  return glist_vacia(pila);
}

void* pila_tope(Pila pila) {
  return pila->data;
}

Pila pila_apilar(Pila pila, void* dato, FuncionCopia c) {
  return glist_agregar_inicio(pila, dato, c);
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

void pila_imprimir(Pila pila, FuncionVisitante v) {
  glist_recorrer(pila, v);
}