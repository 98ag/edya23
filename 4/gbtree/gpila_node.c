#include "gpila_node.h"
#include <stdlib.h>

GPilaNode gpilanode_crear() {
  return NULL;
}

int gpilanode_isempty(GPilaNode pila) {
  return pila == NULL;
}

GPilaNode gpilanode_push(GPilaNode pila, void *ptr) {
  GNode *new = malloc(sizeof(GNode));
  new->dato = ptr;
  new->next = pila;
  return new;
}

GPilaNode gpilanode_pop(GPilaNode pila) {
  if (pila == NULL)
    return NULL;

  GNode *aux = pila;
  pila = pila->next;
  free(aux);
  return pila;
}

void *gpilanode_peek(GPilaNode pila) {
  return pila == NULL ? NULL : pila->dato;
}