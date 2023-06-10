#include "gbtree.h"
#include "gpila_node.h"
#include "gqueue_node.h"
#include <stdlib.h>

GBTree gbtree_crear() {
  return NULL;
}

void gbtree_destruir(GBTree arbol, FuncionDestructora destroy) {
  if (arbol != NULL) {
    gbtree_destruir(arbol->left, destroy);
    gbtree_destruir(arbol->right, destroy);
    destroy(arbol->dato);
    free(arbol);
  }
}

int gbtree_empty(GBTree arbol) {
  return arbol == NULL;
}

GBTree gbtree_unir(void *dato, GBTree left, GBTree right, FuncionCopia copy) {
  GBTNodo *new = malloc(sizeof(GBTNodo));
  new->dato = copy(dato);
  new->left = left;
  new->right = right;
  return new;
}

void gbtree_recorrer_dfs_R(GBTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitante visit) {
  if (gbtree_empty(arbol))
    return;

  if (orden == 0)
    visit(arbol->dato);
  gbtree_recorrer_dfs_R(arbol->left, orden, visit);
  if (orden == 1)
    visit(arbol->dato);
  gbtree_recorrer_dfs_R(arbol->right, orden, visit);
  if (orden == 2)
    visit(arbol->dato);
  return;
}

void gbtree_recorrer_I(GBTree arbol, FuncionVisitante visit) {
  if (gbtree_empty(arbol))
    return;

  GPilaNode stack = gpilanode_crear();
  stack = gpilanode_push(stack, (void *)arbol->dato);

  while (!(gpilanode_isempty(stack))) {
    GBTree actual = (GBTree)gpilanode_pop(stack);
    visit(actual->dato);

    if (actual->right != NULL) {
      stack = gpilanode_push(stack, actual->right);
    }
    if (actual->left != NULL) {
      stack = gpilanode_push(stack, actual->left);
    }
  }
}

int gbtree_nnodos(GBTree arbol) {
  if (arbol != NULL)
    return 1 + gbtree_nnodos(arbol->left) + gbtree_nnodos(arbol->right);

  return 0;
}

int gbtree_buscar(GBTree arbol, void *dato, FuncionComparadora comp) {
  if (arbol == NULL)
    return 0;
  if (comp(arbol->dato, dato))
    return 1;

  return gbtree_buscar(arbol->left, dato, comp) + gbtree_buscar(arbol->right, dato, comp);
}

GBTree gbtree_copiar(GBTree arbol, FuncionCopia copy) {
  if (arbol == NULL)
    return NULL;

  return gbtree_unir(arbol->dato, gbtree_copiar(arbol->left, copy), gbtree_copiar(arbol->right, copy), copy);
}

int gbtree_altura(GBTree arbol) {
  if (arbol == NULL)
    return -1;

  int alturaizq = 1 + gbtree_altura(arbol->left);
  int alturader = 1 + gbtree_altura(arbol->right);

  return alturaizq > alturader ? alturaizq : alturader;
}

int gbtree_nnodos_profundidad(GBTree arbol, int profundidad) {
  if (arbol == NULL)
    return 0;

  return (profundidad == 0) ? 1 : (gbtree_nnodos_profundidad(arbol->left, profundidad - 1) + gbtree_nnodos_profundidad(arbol->right, profundidad - 1));
}

/*
  gbtree_sumar no tiene mucho sentido
*/

void gbtree_recorrer_extra(GBTree arbol, BTreeOrdenDeRecorrido orden,
                           FuncionVisitanteExtra visit, void *extra) {
  if (arbol == NULL)
    return;

  if (orden == 0)
    visit(arbol->dato, extra);
  gbtree_recorrer_extra(arbol->left, orden, visit, extra);
  if (orden == 1)
    visit(arbol->dato, extra);
  gbtree_recorrer_extra(arbol->right, orden, visit, extra);
  if (orden == 2)
    visit(arbol->dato, extra);
  return;
}

void gbtree_recorrer_bfs_I(GBTree arbol, FuncionVisitante visit) {
  if (arbol == NULL)
    return;

  GQueueNode cola = gqueuenode_crear();
  cola = gqueuenode_enqueue(cola, (void *)arbol);

  while (!(gqueuenode_isempty(cola))) {
    GBTree actual = (GBTree)gqueuenode_dequeue(cola);
    cola = gqueuenode_dequeue(cola);
    visit(actual->dato);

    if (actual->left != NULL) {
      cola = gqueuenode_enqueue(cola, actual->right);
    }
    if (actual->right != NULL) {
      cola = gqueuenode_enqueue(cola, actual->left);
    }
  }
}

void gbtree_print_nivel(GBTree arbol, int nivel, FuncionVisitante visit) {
  if (arbol == NULL)
    return;
  if (nivel == 0)
    visit(arbol->dato);
  else {
    gbtree_print_nivel(arbol->left, nivel - 1, visit);
    gbtree_print_nivel(arbol->right, nivel - 1, visit);
  }
}

void gbtree_recorrer_bfs_R(GBTree arbol, FuncionVisitante visit) {
  int altura = gbtree_altura(arbol);

  for (int i = 0; i <= altura; i++)
    gbtree_print_nivel(arbol, i, visit);
}