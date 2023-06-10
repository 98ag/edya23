#ifndef __GPILA_NODE_H__
#define __GPILA_NODE_H__

typedef struct _GNode {
  struct _GNode *next;
  void *dato;
} GNode;

typedef GNode *GPilaNode;

GPilaNode gpilanode_crear();

int gpilanode_isempty(GPilaNode pila);

GPilaNode gpilanode_push(GPilaNode pila, void *ptr);

GPilaNode gpilanode_pop(GPilaNode pila);

void *gpilanode_peek(GPilaNode pila);

#endif