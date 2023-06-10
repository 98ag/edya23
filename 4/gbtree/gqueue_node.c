#include "gqueue_node.h"
#include <stdlib.h>

GQueueNode gqueuenode_crear() {
  return NULL;
}

int gqueuenode_isempty(GQueueNode cola) {
  return cola == NULL;
}

GQueueNode gqueuenode_enqueue(GQueueNode cola, void *ptr) {
  DGNodo *new = malloc(sizeof(DGNodo));
  new->dato = ptr;

  if (cola != NULL) {
    new->prev = cola->prev;
    cola->prev = new;
    new->prev->next = new;
    new->next = cola;
  } else {
    new->prev = new->next = new;
  }

  return new;
}

void *gqueuenode_peek(GQueueNode cola) {
  return cola == NULL ? NULL : cola->dato;
}

GQueueNode gqueuenode_dequeue(GQueueNode cola) {
  if (cola == NULL)
    return NULL;

  if (cola != NULL && cola->prev == cola) {
    free(cola);
    return NULL;
  }

  DGNodo *aux = cola->prev;
  cola->prev = cola->prev->prev;
  cola->prev->next = cola;
  free(aux);
  return cola;
}