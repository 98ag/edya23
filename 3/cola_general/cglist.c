#include "cglist.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Devuelve una lista vacía.
 */
CGList cglist_crear() { return NULL; }

/**
 * Destruccion de la lista.
 * destroy es una función que libera el dato almacenado.
 */
void cglist_destruir(CGList list, FuncionDestructora destroy) {
  // printf("Entre a destruir\n");
  CGNode *nodeToDelete;

  if (list != NULL) {
    // printf("%p\n", list->prev->next);
    list->prev->next = NULL;
  }
  // printf("%p\n", list->prev->next);
  list->prev->next = NULL;

  // printf("Hasta aca parece que anda\n");
  while (list != NULL) {
    nodeToDelete = list;
    list = list->next;
    destroy(nodeToDelete->data);
    free(nodeToDelete);
  }
}

/**
 * Determina si la lista es vacía.
 */
int cglist_vacia(CGList list) { return (list == NULL); }

/**
 * Agrega un elemento al inicio de la lista.
 * copy es una función que retorna una copia física del dato.
 */
CGList cglist_agregar_inicio(CGList list, void *data, FuncionCopia copy) {
  CGNode *newNode = malloc(sizeof(CGNode));
  assert(newNode != NULL);

  if (list != NULL) {
    newNode->prev = list->prev;
    list->prev = newNode;
    newNode->next = list;
    newNode->prev->next = newNode;
  } else {
    newNode->prev = newNode->next = newNode;
  }
  newNode->data = copy(data);
  // printf("Ultimo: %p   Actual: %p    Siguiente:%p\n")
  return newNode;
}

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void cglist_recorrer(CGList list, FuncionVisitante visit, CGListOrdenDeRecorrido orden) {
  CGNode *aux;

  if (list != NULL) {

    if (orden) {
      aux = list->prev;
      do {
        printf("Actual: %p   Siguiente: %p\n", aux, aux->next);
        visit(aux->data);
        aux = aux->prev;
      } while (aux != list->prev);
    } else {
      aux = list;
      do {
        printf("Actual: %p   Siguiente: %p\n", aux, aux->next);
        visit(aux->data);
        aux = aux->next;
      } while (aux != list);
    }
  }
}

/**
 * @brief Agrega un elemento al final de la lista
 *
 * @param copy Funcion que retorna una copia fisica del dato.
 */
CGList cglist_agregar_final(CGList list, void *data, FuncionCopia copy) {
  if (list == NULL) {
    return cglist_agregar_inicio(list, data, copy);
  } else {
    CGNode *newNode = malloc(sizeof(CGNode));
    assert(newNode != NULL);

    newNode->data = copy(data);
    newNode->prev = list->prev;
    list->prev->next = newNode;
    newNode->next = list;
    list->prev = newNode;
    return list;
  }
}