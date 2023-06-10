#include "gqueue.h"
#include <stdio.h>
#include <stdlib.h>

typedef CGList GQueue;

GQueue cola_crear() {
  return cglist_crear();
}

void cola_destruir(GQueue cola, FuncionDestructora destruir) {
  cglist_destruir(cola, destruir);
}

int cola_es_vacia(GQueue cola) {
  return cglist_vacia(cola);
}

void *cola_inicio(GQueue cola) {
  return (cola == NULL) ? NULL : cola->prev->data;
}

GQueue cola_encolar(GQueue cola, void *dato, FuncionCopia copia) {
  return cglist_agregar_inicio(cola, dato, copia);
}

GQueue cola_encolar_nodo(GQueue cola, void *ptr) {
  CGNode *newNode = malloc(sizeof(CGNode));

  if (cola != NULL) {
    newNode->prev = cola->prev;
    cola->prev = newNode;
    newNode->next = cola;
    newNode->prev->next = newNode;
  } else {
    newNode->prev = newNode->next = newNode;
  }

  newNode->data = ptr;
  return newNode;
}

GQueue cola_desencolar(GQueue cola, FuncionDestructora destruir) {
  if (cola != NULL && cola->prev != NULL) {
    CGNode *aux = cola->prev;
    cola->prev = cola->prev->prev;
    cola->prev->next = cola;
    destruir(aux->data);
    free(aux);
    return cola;
  } else if (cola != NULL) {
    destruir(cola->data);
  }
  return NULL;
}

GQueue cola_desencolar_nodo(GQueue cola) {
  if (cola == NULL)
    return NULL;

  if (cola != NULL && cola->prev == cola) {
    free(cola);
    return NULL;
  }

  CGNode *aux = cola->prev;
  cola->prev = cola->prev->prev;
  cola->prev->next = cola;
  free(aux);
  return cola;
}

void *cola_inicio_nodo(GQueue cola) {
  if (cola == NULL)
    return NULL;

  return cola->prev->data;
}

void cola_imprimir(GQueue cola, FuncionVisitante visitar) {
  cglist_recorrer(cola, visitar, CGLIST_ATRAS);
}