#ifndef __SGLIST_H__
#define __SGLIST_H__

typedef void (*FuncionDestructora)(void *dato);
typedef void *(*FuncionCopia)(void *dato);
typedef void (*FuncionVisitante)(void *dato);
typedef int (*Predicado) (void *dato);

typedef struct _GNode {
  void *data;
  struct _GNode *next;
} GNode;

typedef struct _SGList {
  GNode *first;
  GNode *last;
} *SGList;

/**
 * Devuelve una lista vacía.
 */
SGList sglist_crear();

/**
 * Destruccion de la lista.
 */
void sglist_destruir(SGList lista, FuncionDestructora destruir);

/**
 * Determina si la lista es vacía.
 */
int sglist_vacia(SGList lista);

/**
 * Agrega un elemento al inicio de la lista.
 */
void sglist_agregar_inicio(SGList lista, void *dato, FuncionCopia copiar);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void sglist_recorrer(SGList lista, FuncionVisitante visitar);

/**
 * @brief Agrega un elemento al final de la lista
 * 
 * @param copy Funcion que retorna una copia fisica del dato.
 */
void sglist_agregar_final(SGList list, void *data, FuncionCopia copy);
/**
 * @brief Retorna una nueva lista con los elementos que cumplen con el predicado
 * 
 * @param lista 
 * @param c Funcion que copia los datos
 * @param p Predicado
 * @return SGList
 */
SGList glist_filtrar(SGList lista, FuncionCopia c, Predicado p);

#endif /* __SGLIST_H__ */
