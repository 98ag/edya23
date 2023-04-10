#ifndef __SLIST_H__
#define __SLIST_H__

#include <stddef.h>

typedef void (*FuncionVisitante)(int dato);

typedef struct _SNodo {
  int dato;
  struct _SNodo *sig;
} SNodo;

typedef SNodo *SList;

/**
 * Devuelve una lista vacía. O(1)
 */
SList slist_crear();

/**
 * Destruccion de la lista. O(n)
 */
void slist_destruir(SList lista);

/**
 * Determina si la lista es vacía. O(1)
 */
int slist_vacia(SList lista);

/**
 * Agrega un elemento al final de la lista. O(n)
 */
SList slist_agregar_final(SList lista, int dato);

/**
 * Agrega un elemento al inicio de la lista. O(1)
 */
SList slist_agregar_inicio(SList lista, int dato);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void slist_recorrer(SList lista, FuncionVisitante visit);

/**
 * Retorna la longitud de la lista. O(n)
 **/
int slist_longitud(SList lista);

/**
 * Retorna la listaDestino con la listaConcat concatenada. O(m) donde m es largo
 *  de la primera lista
 **/
SList slist_concatenar(SList listaDestino, SList listaConcat);

/**
 * Retorna la lista con el elemento dato agregado en la posicion pos. 
 *  O(n) en el peor de los casos (elemento al final)
 **/
SList slist_insertar(SList lista, int pos, int dato);

/**
 * Retorna la lista con el elemento en la posicion pos eliminado
 *  O(n) en el peor de los casos (elemento al final)
 */
SList slist_eliminar(SList lista, int pos);

/**
 * Retorna 1 si el valor dato esta en la lista, de lo contrario
 *  retorna 0. O(n) en el peor de los casos (elemento al final)
 */
int slist_contiene(SList lista, int dato);

/**
 * Retorna la posición del elemento dato en la lista,
 *  o -1 si el elemento no está en ella. O(n) en el peor de los casos (elemento al final)
 */
int slist_indice(SList lista, int dato);

/**
 * Retorna una nueva lista con los elementos en comun de
 *  lista1 y lista2. O(m*n) donde m y n son los largos de las listas
 */
SList slist_intersecar(SList lista1, SList lista2);

/**
 * Retorna la lista lista revertida en una nueva lista
 * 1 + 2 + ... + n = (n^2 + n) / 2 => O(n^2)
 */
SList slist_reverso(SList lista);

/**
 * Retorna una lista resultado de intercalar lista1 y lista2
 *  O(m+n)
 */
SList slist_intercalar(SList lista1, SList lista2);

/**
 * Si la lista tiene numero de elementos n par, retorna un puntero al elemento n/2
 *  de lo contrario retorna un puntero al elemento floor(n / 2) + 1. 
 *   O(n)
 */
SList slist_partir(SList lista);

#endif /* __SLIST_H__ */
