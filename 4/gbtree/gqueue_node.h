#ifndef __GQUEUE_NODE_H__
#define __GQUEUE_NODE_H__

typedef struct DGNodo {
  void *dato;
  struct DGNodo *prev;
  struct DGNodo *next;
} DGNodo;

typedef DGNodo *GQueueNode;

GQueueNode gqueuenode_crear();

int gqueuenode_isempty(GQueueNode cola);

GQueueNode gqueuenode_enqueue(GQueueNode cola, void *ptr);

void *gqueuenode_peek(GQueueNode cola);

GQueueNode gqueuenode_dequeue(GQueueNode cola);

#endif