#include "btree.h"
#include "gpila.h"
#include "gqueue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct _BTNodo {
  int dato;
  struct _BTNodo *left;
  struct _BTNodo *right;
};

/**
 * Devuelve un arbol vacío.
 */
BTree btree_crear() { return NULL; }

/**
 * Destruccion del árbol.
 */
void btree_destruir(BTree nodo) {
  if (nodo != NULL) {
    btree_destruir(nodo->left);
    btree_destruir(nodo->right);
    free(nodo);
  }
}

/**
 * Indica si el árbol es vacío.
 */
int btree_empty(BTree nodo) { return nodo == NULL; }

/**
 * Crea un nuevo arbol, con el dato dado en el nodo raiz, y los subarboles dados
 * a izquierda y derecha.
 */
BTree btree_unir(int dato, BTree left, BTree right) {
  BTree nuevoNodo = malloc(sizeof(struct _BTNodo));
  assert(nuevoNodo != NULL);
  nuevoNodo->dato = dato;
  nuevoNodo->left = left;
  nuevoNodo->right = right;
  return nuevoNodo;
}

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden,
                    FuncionVisitanteInt visit) {
  if (arbol == NULL)
    return;

  if (orden == 0)
    visit(arbol->dato);
  btree_recorrer(arbol->left, orden, visit);
  if (orden == 1)
    visit(arbol->dato);
  btree_recorrer(arbol->right, orden, visit);
  if (orden == 2)
    visit(arbol->dato);
  return;
}

/*  Recorrer Preorder Iterativo
      Crear cola vacia
      Pushear raiz del arbol

      Mientras cola no este vacia:
        Popear item de la cola y leer dato
        Pushear hijo derecho
        Pushear hijo izquierdo
*/

void btree_recorrer_iterativo(BTree arbol, FuncionVisitanteInt visit) {
  if (arbol == NULL)
    return;

  Pila pila_de_nodos = pila_crear();
  pila_de_nodos = pila_apilar_nodo(pila_de_nodos, (void *)arbol);

  while (!(pila_es_vacia(pila_de_nodos))) {
    BTree actual = (BTree)pila_tope(pila_de_nodos);
    visit(actual->dato);

    pila_de_nodos = pila_desapilar_nodo(pila_de_nodos);

    if (actual->right != NULL)
      pila_de_nodos = pila_apilar_nodo(pila_de_nodos, (void *)actual->right);

    if (actual->left != NULL)
      pila_de_nodos = pila_apilar_nodo(pila_de_nodos, (void *)actual->left);
  }
}

int btree_nnodos(BTree arbol) {
  if (arbol != NULL)
    return 1 + btree_nnodos(arbol->left) + btree_nnodos(arbol->right);

  return 0;
}

int btree_buscar(BTree arbol, int num) {
  if (arbol == NULL)
    return 0;
  if (arbol->dato == num)
    return 1;

  return (btree_buscar(arbol->left, num) + btree_buscar(arbol->right, num) == 0 ? 0 : 1);
}

BTree btree_copiar(BTree arbol) {
  if (arbol == NULL)
    return NULL;

  return btree_unir(arbol->dato, btree_copiar(arbol->left), btree_copiar(arbol->right));
}

int btree_altura(BTree arbol) {
  if (arbol == NULL)
    return -1;

  int alturaizq = 1 + btree_altura(arbol->left);
  int alturader = 1 + btree_altura(arbol->right);

  return alturaizq > alturader ? alturaizq : alturader;
}

int btree_nnodos_profundidad(BTree arbol, int profundidad) {
  if (arbol == NULL)
    return 0;

  return (profundidad == 0) ? 1 : (btree_nnodos_profundidad(arbol->left, profundidad - 1) + btree_nnodos_profundidad(arbol->right, profundidad - 1));
}

int btree_profundidad(BTree arbol, int num) {
  return 0;
}

int btree_sumar(BTree arbol) {
  if (arbol == NULL)
    return 0;

  return arbol->dato + btree_sumar(arbol->left) + btree_sumar(arbol->right);
}

void btree_recorrer_extra(BTree arbol, BTreeOrdenDeRecorrido orden,
                          FuncionVisitanteExtra visit, void *extra) {
  if (arbol == NULL)
    return;

  if (orden == 0)
    visit(arbol->dato, extra);
  btree_recorrer_extra(arbol->left, orden, visit, extra);
  if (orden == 1)
    visit(arbol->dato, extra);
  btree_recorrer_extra(arbol->right, orden, visit, extra);
  if (orden == 2)
    visit(arbol->dato, extra);
  return;
}

void btree_recorrer_bfs(BTree arbol, FuncionVisitanteInt visit) {
  if (arbol == NULL)
    return;

  GQueue cola = cola_crear();
  cola = cola_encolar_nodo(cola, (void *)arbol);

  while (!(cola_es_vacia(cola))) {
    BTree actual = (BTree)cola_inicio_nodo(cola);
    visit(actual->dato);

    cola = cola_desencolar_nodo(cola);

    if (actual->left != NULL) {
      cola = cola_encolar_nodo(cola, actual->left);
    }
    if (actual->right != NULL) {
      cola = cola_encolar_nodo(cola, actual->right);
    }
  }
}

void btree_print_nivel(BTree arbol, int nivel, FuncionVisitanteInt visit) {
  if (arbol == NULL)
    return;
  if (nivel == 0)
    visit(arbol->dato);
  else {
    btree_print_nivel(arbol->left, nivel - 1, visit);
    btree_print_nivel(arbol->right, nivel - 1, visit);
  }
}

void btree_recorrer_bfs_R(BTree arbol, FuncionVisitanteInt visit) {
  int altura = btree_altura(arbol);
  for (int i = 0; i <= altura; i++)
    btree_print_nivel(arbol, i, visit);
}
