#include"sglist.h"
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>

/**
 * Devuelve una lista vacía.
 */
SGList sglist_crear() { return NULL; }

/**
 * Destruccion de la lista.
 * destroy es una función que libera el dato almacenado.
 */
void sglist_destruir(SGList list, FuncionDestructora destroy) {
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
int sglist_vacia(SGList list) { return (list == NULL); }

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void sglist_recorrer(SGList list, FuncionVisitante visit) {
  for (GNode *node = list; node != NULL; node = node->next)
    visit(node->data);
}

SGList sglist_insertar(SGList lista, void *dato, FuncionCopia copy, FuncionComparadora comp) {
  SGList auxLista = lista, auxAnterior = NULL;

  while(auxLista != NULL && comp(auxLista->data, dato) > 0) {
    auxAnterior = auxLista;
    auxLista = auxLista->next;
  }

  GNode *new = malloc(sizeof(GNode));
  new->data = copy(dato);

  if(auxAnterior == NULL) {
    new->next = lista;
    return new;
  }
  else if(auxLista == NULL){
    auxAnterior->next = new;
    new->next = NULL;
  }
  else {
    auxAnterior->next = new;
    new->next = auxLista;
  }

  return lista;
}

int sglist_buscar(SGList lista, void *dato, FuncionComparadora c) {
  while(lista != NULL) {
    if(c(dato, lista->data) == 0)
      return 1;
    lista = lista->next;
  }
  return 0;
}

SGList sglist_arr(void** arr, int length, FuncionCopia copy, FuncionComparadora comp) {
  SGList new = sglist_crear();

  for(int i = 0; i < length; i++) {
    new = sglist_insertar(new, arr[i], copy, comp);
  }

  return new;
}
