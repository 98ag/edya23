#include "bstree.h"
#include <assert.h>
#include <stdlib.h>

#include <stdio.h>

/**
 * Estructura del nodo del arbol de busqueda binaria.
 * Tiene un puntero al dato (dato),
 * un puntero al nodo raiz del subarbol izquierdo (izq),
 * y un puntero al nodo raiz del subarbol derecho (der).
 */
struct _BST_Nodo {
  void *dato;
  struct _BST_Nodo *izq, *der;
};

/**
 * bstee_crear: Retorna un arbol de busqueda binaria vacio
 */
BSTree bstee_crear() { return NULL; }

/**
 * bstree_destruir: Destruye el arbol y sus datos
 */
void bstree_destruir(BSTree raiz, FuncionDestructora destr) {
  if (raiz != NULL) {
    bstree_destruir(raiz->izq, destr);
    bstree_destruir(raiz->der, destr);
    destr(raiz->dato);
    free(raiz);
  }
};

/**
 * bstree_buscar: Retorna 1 si el dato se encuentra y 0 en caso
 * contrario
 */
int bstree_buscar(BSTree raiz, void *dato, FuncionComparadora comp) {
  if (raiz == NULL)
    return 0;
  else if (comp(dato, raiz->dato) == 0) // raiz->dato == dato
    return 1;
  else if (comp(dato, raiz->dato) < 0) // dato < raiz->dato
    return bstree_buscar(raiz->izq, dato, comp);
  else // raiz->dato < dato
    return bstree_buscar(raiz->der, dato, comp);
}

/**
 * bstree_insertar: Inserta un dato no repetido en el arbol, manteniendo la
 * propiedad del arbol de busqueda binaria
 */
BSTree bstree_insertar(BSTree raiz, void *dato, FuncionCopiadora copia,
                       FuncionComparadora comp) {
  if (raiz == NULL) { // insertar el dato en un nuevo nodo
    struct _BST_Nodo *nuevoNodo = malloc(sizeof(struct _BST_Nodo));
    assert(nuevoNodo != NULL);
    nuevoNodo->dato = copia(dato);
    nuevoNodo->izq = nuevoNodo->der = NULL;
    return nuevoNodo;
  } else if (comp(dato, raiz->dato) < 0) // dato < raiz->dato
    raiz->izq = bstree_insertar(raiz->izq, dato, copia, comp);
  else if (comp(dato, raiz->dato) > 0) // raiz->dato < dato
    raiz->der = bstree_insertar(raiz->der, dato, copia, comp);
  // si el dato ya se encontraba, no es insertado
  return raiz;
}

/**
 * bstree_recorrer: Recorrido DSF del arbol
 */
void bstree_recorrer(BSTree raiz, BSTreeRecorrido orden,
                     FuncionVisitanteExtra visita, void *extra) {
  if (raiz != NULL) {
    if (orden == BTREE_RECORRIDO_PRE)
      visita(raiz->dato, extra);
    bstree_recorrer(raiz->izq, orden, visita, extra);
    if (orden == BTREE_RECORRIDO_IN)
      visita(raiz->dato, extra);
    bstree_recorrer(raiz->der, orden, visita, extra);
    if (orden == BTREE_RECORRIDO_POST)
      visita(raiz->dato, extra);
  }
}

BSTree bstree_sucesor_inorder(BSTree arbol) {

  while (arbol->izq != NULL)
    arbol = arbol->izq;

  return arbol;
}

BSTree bstree_padre_sucesor_inorder(BSTree arbol) {

  while (arbol->izq->izq != NULL)
    arbol = arbol->izq;

  return arbol;
}

BSTree bstree_eliminar(BSTree arbol, void *dato, FuncionComparadora comp, FuncionDestructora destroy) { //, FuncionCopiadora copy
  if (arbol == NULL)
    return NULL;

  int compres = comp(dato, arbol->dato);

  if (compres > 0)
    arbol->der = bstree_eliminar(arbol->der, dato, comp, destroy);

  if (compres < 0)
    arbol->izq = bstree_eliminar(arbol->izq, dato, comp, destroy);

  if (compres == 0) {
    if (arbol->izq == NULL && arbol->der == NULL) {
      destroy(arbol->dato);
      free(arbol);
      return NULL;
    }

    else if (arbol->izq != NULL && arbol->der != NULL) {
      /*
      BSTree sucesor = bstree_sucesor_inorder(arbol->der);
      destroy(arbol->dato);
      arbol->dato = copy(sucesor->dato);
      bstree_eliminar(arbol->der, sucesor->dato, comp, destroy, copy);
      return arbol;
      */
      BSTree padreSucesor = bstree_padre_sucesor_inorder(arbol->der);
      BSTree sucesor = padreSucesor->izq;

      padreSucesor->izq = (sucesor->der == NULL) ? NULL : sucesor->der;
      sucesor->izq = arbol->izq;
      sucesor->der = arbol->der;

      destroy(arbol->dato);
      free(arbol);
      return sucesor;
    }

    else {
      BSTree aux = arbol->izq == NULL ? arbol->der : arbol->izq;
      destroy(arbol->dato);
      free(arbol);
      return aux;
    }
  }

  return arbol;
}

void *bstree_k_esimo_menor(BSTree arbol, int k) {
  static int cont = 0;
  static void *ret = NULL; // Feo, ha de haber mejor manera

  if (arbol == NULL)
    return NULL;

  if (cont <= k) {
    bstree_k_esimo_menor(arbol->izq, k);
    cont++;

    if (cont == k) {
      ret = arbol->dato;
    }

    bstree_k_esimo_menor(arbol->der, k);
  }

  return ret;
}

void *bst_max(BSTree arbol) {
  while (arbol->der != NULL)
    arbol = arbol->der;

  return arbol->dato;
}

void *bst_min(BSTree arbol) {
  while (arbol->izq != NULL)
    arbol = arbol->izq;

  return arbol->dato;
}

int bstree_validar(BSTree arbol, FuncionComparadora comp, FuncionVisitanteExtra visit) {
  if (arbol == NULL)
    return 1;

  void *izqMax = arbol->izq == NULL ? arbol->dato : bst_max(arbol->izq);
  void *derMin = arbol->der == NULL ? arbol->dato : bst_min(arbol->der);

  if (comp(izqMax, arbol->dato) > 0 || comp(derMin, arbol->dato) < 0)
    return 0;

  int checkIzq = bstree_validar(arbol->izq, comp, visit);
  int checkDer = bstree_validar(arbol->der, comp, visit);

  if (checkIzq && checkDer)
    return 1;
  else
    return 0;

  /*
  static void *anterior;
  static int cond = 1;

  if (arbol != NULL) {
    anterior = arbol->dato;
    printf("Anterior es: ");
    visit(anterior, NULL);
    puts("");

    bstree_validar(arbol->izq, comp, visit);

    printf("Validando si actual ");
    visit(arbol->dato, NULL);
    printf("  es menor que anterior ");
    visit(anterior, NULL);
    puts(" (falso)");

    if (comp(arbol->dato, anterior) < 0) // Si actual > dato
      cond = 0;
    bstree_validar(arbol->der, comp, visit);
  }

  return cond;
  */
}

/*
  Validar 2:
    *Lleva un puntero donde guarda un puntero a arbol (para el anterior)

  Siendo: TRUE = 1
          FALSE = 0

  - SI arbol vacio RETORNA TRUE

  - checkIzq = validar(arbol->izq)

  - SI (anterior distinto de NULL) yy (*ANTERIOR > ARBOL)
      RETORNA FALSE
  - anterior = arbol

  - checkDer = validar(arbol->der)

  - SI (izq = TRUE) y (der = TRUE)
      RETURNA TRUE
    DE LO CONTRARIO
      RETORNA FALSE
*/
int bst_validar_2(BSTree arbol, FuncionComparadora comp) {
  BSTree anterior = NULL;
  return bst_validar_r(arbol, &anterior, comp);
}

int bst_validar_r(BSTree arbol, BSTree *anterior, FuncionComparadora comp) {
  if (arbol == NULL)
    return 1;

  int checkIzq = bst_validar_r(arbol->izq, anterior, comp);

  if (*anterior != NULL && comp(arbol->dato, (*anterior)->dato) < 0)
    return 0;

  *anterior = arbol;
  int checkDer = bst_validar_r(arbol->der, anterior, comp);
  if (checkIzq && checkDer)
    return 1;
  else
    return 0;
}