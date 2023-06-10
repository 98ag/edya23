#ifndef __GLIST_H__
#define __GLIST_H__

typedef void (*FuncionDestructora)(void *dato);
typedef void *(*FuncionCopia)(void *dato);
typedef void (*FuncionVisitanteList)(void *dato);
typedef int (*Predicado)(void *dato);

typedef struct _GNode {
  void *data;
  struct _GNode *next;
} GNode;

typedef GNode *GList;

/**
 * Devuelve una lista vacía.
 */
GList glist_crear();

/**
 * Destruccion de la lista.
 */
void glist_destruir(GList lista, FuncionDestructora destruir);

/**
 * Determina si la lista es vacía.
 */
int glist_vacia(GList lista);

/**
 * Agrega un elemento al inicio de la lista.
 */
GList glist_agregar_inicio(GList lista, void *dato, FuncionCopia copiar);

GList glist_agregar_inicio_nodo(GList list, void *ptr);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void glist_recorrer(GList lista, FuncionVisitanteList visitar);

/**
 * @brief Retorna una nueva lista con los elementos que cumplen con el predicado
 *
 * @param lista
 * @param c Funcion que copia los datos
 * @param p Predicado
 * @return GList
 */
GList glist_filtrar(GList lista, FuncionCopia c, Predicado p);

#endif /* __GLIST_H__ */
