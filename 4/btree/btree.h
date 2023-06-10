#ifndef __BTREE_H__
#define __BTREE_H__

typedef void (*FuncionVisitanteInt)(int dato);

typedef enum {
  BTREE_RECORRIDO_IN,
  BTREE_RECORRIDO_PRE,
  BTREE_RECORRIDO_POST
} BTreeOrdenDeRecorrido;

typedef struct _BTNodo *BTree;
typedef void (*FuncionVisitanteExtra)(int dato, void *extra);

/**
 * Devuelve un arbol vacío.
 */
BTree btree_crear();

/**
 * Destruccion del árbol.
 */
void btree_destruir(BTree nodo);

/**
 * Indica si el árbol es vacío.
 */
int btree_empty(BTree nodo);

/**
 * Crea un nuevo arbol, con el dato dado en el nodo raiz, y los subarboles dados
 * a izquierda y derecha.
 */
BTree btree_unir(int dato, BTree left, BTree right);

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden,
                    FuncionVisitanteInt visit);

void btree_recorrer_iterativo(BTree arbol, FuncionVisitanteInt visit);

int btree_nnodos(BTree arbol);

int btree_buscar(BTree arbol, int num);

BTree btree_copiar(BTree arbol);

int btree_altura(BTree arbol);

int btree_nnodos_profundidad(BTree arbol, int profundidad);

int btree_profundidad(BTree arbol, int num);

int btree_sumar(BTree arbol);

void btree_recorrer_bfs(BTree arbol, FuncionVisitanteInt visit);

void btree_print_nivel(BTree arbol, int nivel, FuncionVisitanteInt visit);

void btree_recorrer_bfs_R(BTree arbol, FuncionVisitanteInt visit);
#endif /* __BTREE_H__ */
