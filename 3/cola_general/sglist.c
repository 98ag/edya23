#include "sglist.h"
#include <assert.h>
#include <stdlib.h>
#include<stdio.h>

/**
 * Devuelve una lista vacía.
 */
SGList sglist_crear() { 
  SGList new = malloc(sizeof(struct _SGList));
  new->first = NULL;
  new->last = NULL;
  return new;
 }

/**
 * Destruccion de la lista.
 * destroy es una función que libera el dato almacenado.
 */
void sglist_destruir(SGList list, FuncionDestructora destroy) {
  GNode *nodeToDelete;
  while (list->first != NULL) {
    nodeToDelete = list->first;
    list->first = list->first->next;
    destroy(nodeToDelete->data);
    free(nodeToDelete);
  }
  free(list);
}

/**
 * Determina si la lista es vacía.
 */
int sglist_vacia(SGList list) { return (list->first == NULL); }

/**
 * Agrega un elemento al inicio de la lista.
 * copy es una función que retorna una copia física del dato.
 */
void sglist_agregar_inicio(SGList list, void *data, FuncionCopia copy) {
  GNode *newNode = malloc(sizeof(GNode));
  assert(newNode != NULL);
  newNode->next = list->first;
  newNode->data = copy(data);
  list->first = newNode;
  if (list->last == NULL)
    list->last = newNode;
}

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void sglist_recorrer(SGList list, FuncionVisitante visit) {
  for (GNode *node = list->first; node != NULL; node = node->next)
    visit(node->data);
}

/**
 * @brief Agrega un elemento al final de la lista
 * 
 * @param copy Funcion que retorna una copia fisica del dato.
 */
void sglist_agregar_final(SGList list, void *data, FuncionCopia copy) {
  GNode *newNode = malloc(sizeof(GNode));
  newNode->data = copy(data);
  newNode->next = NULL;

  if (list->first == NULL)
    list->first = newNode;
  else
    list->last->next = newNode;

  list->last = newNode;
}

/**
 * @brief Retorna una nueva lista con los elementos filtrados segun la funcion Predicado
 * 
 * @param lista 
 * @param c Funcion copia, que retorna una copia fisica del dato
 * @param p Funcion predicado, que retorna 1 si cumple la condicion o 0 si no
 * @return GList 
 */
SGList glist_filtrar(SGList lista, FuncionCopia c, Predicado p) {
  SGList new = sglist_crear();
  GNode *node = lista->first;
  while (node != NULL) {
    if (p(node->data)) {
      sglist_agregar_final(new, node->data, c);
    }
    node = node->next;
  }
  return new;
}
