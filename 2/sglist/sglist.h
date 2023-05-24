#ifndef __SGLIST_H__
#define __SGLIST_H__

typedef void (*FuncionDestructora)(void *dato);
typedef void *(*FuncionCopia)(void *dato);
typedef void (*FuncionVisitante)(void *dato);
typedef int (*FuncionComparadora)(void *, void*);

typedef struct _GNode {
  void *data;
  struct _GNode *next;
} GNode;

typedef GNode *SGList;

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
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void sglist_recorrer(SGList lista, FuncionVisitante visitar);

/**
 * @brief Inserta un dato en la lista ordenada segun la funcion comparadora
 * 
 * @param lista 
 * @param dato 
 * @param copy Funcion que retorna una copia fisica del dato
 * @param comp Funcion comparadora que retorna un entero segun criterio de comparacion
 * @return SGList 
 */
SGList sglist_insertar(SGList lista, void *dato, FuncionCopia copy, FuncionComparadora comp);

/**
 * @brief Busca un dato en la lista ordenada, retornando 1 si lo encuentra y 0 en caso contrario
 * 
 * @param lista 
 * @param dato 
 * @param c Funcion comparadora
 * @return int 
 */
int sglist_buscar(SGList lista, void *dato, FuncionComparadora c);

/**
 * @brief Construye una lista ordenada a partir de un arreglo de elementos y su longitud
 * 
 * @param arr Arreglo de elementos
 * @param length Largo del arreglo
 * @param copy Funcion que retorna una copia fisica del dato
 * @param comp Funcion comparadora que retorna un entero segun criterio de comparacion
 * @return SGList 
 */
SGList sglist_arr(void ** arr, int length, FuncionCopia copy, FuncionComparadora comp);

#endif