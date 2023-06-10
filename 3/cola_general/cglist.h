#ifndef __CGLIST_H__ // Circular General List
#define __CGLIST_H__

typedef void (*FuncionDestructora)(void *dato);
typedef void *(*FuncionCopia)(void *dato);
typedef void (*FuncionVisitante)(void *dato);

typedef struct _CGNode {
  void *data;
  struct _CGNode *next;
  struct _CGNode *prev;
} CGNode;

typedef CGNode *CGList;

typedef enum {
  CGLIST_ADELANTE,
  CGLIST_ATRAS
} CGListOrdenDeRecorrido;

/**
 * Devuelve una lista vacía.
 */
CGList cglist_crear();

/**
 * Destruccion de la lista.
 */
void cglist_destruir(CGList lista, FuncionDestructora destruir);

/**
 * Determina si la lista es vacía.
 */
int cglist_vacia(CGList lista);

/**
 * Agrega un elemento al inicio de la lista.
 */
CGList cglist_agregar_inicio(CGList lista, void *dato, FuncionCopia copiar);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void cglist_recorrer(CGList lista, FuncionVisitante visitar, CGListOrdenDeRecorrido orden);

#endif /* __CGLIST_H__ */
