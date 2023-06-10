#ifndef __GBTREE_H__
#define __GBTREE_H__

typedef void (*FuncionVisitante)(void *dato);
typedef void (*FuncionVisitanteExtra)(void *dato, void *extra);
typedef void (*FuncionDestructora)(void *dato);
typedef int (*FuncionComparadora)(void *dato1, void *dato2);
typedef void *(*FuncionCopia)(void *dato);

typedef enum {
  BTREE_RECORRIDO_IN,
  BTREE_RECORRIDO_PRE,
  BTREE_RECORRIDO_POST
} BTreeOrdenDeRecorrido;

typedef struct _GBTNodo {
  void *dato;
  struct _GBTNodo *left;
  struct _GBTNodo *right;
} GBTNodo;

typedef GBTNodo *GBTree;

#endif