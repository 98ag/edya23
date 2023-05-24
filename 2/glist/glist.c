#include "glist.h"
#include <assert.h>
#include <stdlib.h>
#include<stdio.h>

/**
 * Devuelve una lista vacía.
 */
GList glist_crear() { return NULL; }

/**
 * Destruccion de la lista.
 * destroy es una función que libera el dato almacenado.
 */
void glist_destruir(GList list, FuncionDestructora destroy) {
  GNode *nodeToDelete;
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
int glist_vacia(GList list) { return (list == NULL); }

/**
 * Agrega un elemento al inicio de la lista.
 * copy es una función que retorna una copia física del dato.
 */
GList glist_agregar_inicio(GList list, void *data, FuncionCopia copy) {
  GNode *newNode = malloc(sizeof(GNode));
  assert(newNode != NULL);
  newNode->next = list;
  newNode->data = copy(data);
  return newNode;
}

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void glist_recorrer(GList list, FuncionVisitante visit) {
  for (GNode *node = list; node != NULL; node = node->next)
    visit(node->data);
}

/**
 * @brief Agrega un elemento al final de la lista
 * 
 * @param copy Funcion que retorna una copia fisica del dato.
 */
GList glist_agregar_final(GList list, void *data, FuncionCopia copy) {
  GNode *newNode = malloc(sizeof(GNode));
  GList auxLista = list;

  assert(newNode != NULL);
  newNode->next = NULL;
  newNode->data = copy(data);

  if(glist_vacia(list)) {
    return newNode;
  }
  else {
    while (list->next != NULL) {
        list = list->next;
    }
    list->next = newNode;
    return auxLista;
  }
}

/**
 * @brief Retorna una nueva lista con los elementos filtrados segun la funcion Predicado
 * 
 * @param lista 
 * @param c Funcion copia, que retorna una copia fisica del dato
 * @param p Funcion predicado, que retorna 1 si cumple la condicion o 0 si no
 * @return GList 
 */
GList glist_filtrar(GList lista, FuncionCopia c, Predicado p) {
  GList new = glist_crear();
  while (lista != NULL) {
    if (p(lista->data)) {
      new = glist_agregar_final(new, lista->data, c);
    }
    lista = lista->next;
  }
  return new;
}
