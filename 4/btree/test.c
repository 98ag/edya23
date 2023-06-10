#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

static void imprimir_entero(int data) {
  printf("%d ", data);
}

int main() {
  BTree ll = btree_unir(1, btree_crear(), btree_crear());
  BTree l = btree_unir(2, ll, btree_crear());
  BTree r = btree_unir(3, btree_crear(), btree_crear());
  BTree raiz = btree_unir(4, l, r);

  // BTree test = btree_unir(1, btree_crear(), btree_crear());
  /*          4
         2         3
     1     x     x    x
   x   x
  */
  // btree_recorrer(raiz, BTREE_RECORRIDO_PRE, imprimir_entero);
  // puts("");
  puts("Arbol original:");
  btree_recorrer_iterativo(raiz, imprimir_entero);
  puts("");

  printf("Cantidad de nodos: %d\n", btree_nnodos(raiz));

  printf("Se encuentra el 1? %d\n", btree_buscar(raiz, 1));
  puts("");

  BTree copy = btree_copiar(raiz);
  copy = btree_unir(5, copy, btree_copiar(raiz));
  /*                   5
             4                   4
        2        3          2         3
      1   x    x   x      1    x    x   x
    x   x               x   x
  */
  puts("Arbol copiado:");
  btree_recorrer_iterativo(copy, imprimir_entero);
  puts("");
  printf("Cantidad de nodos: %d\n", btree_nnodos(copy));
  printf("Altura del arbol: %d\n", btree_altura(copy));

  // int dato = 3;

  printf("Nodos en profundidad 6: %d\n", btree_nnodos_profundidad(copy, 4));
  // printf("Profundidad del dato %d: %d\n", dato, btree_profundidad(copy, dato));
  printf("Suma de los datos: %d\n", btree_sumar(copy));

  puts("Cola por extension iterativa: ");
  btree_recorrer_bfs(copy, imprimir_entero);
  puts("");
  puts("Cola por extension recursiva: ");
  btree_recorrer_bfs_R(copy, imprimir_entero);
  puts("");

  btree_destruir(raiz);
  btree_destruir(copy);
  return 0;
}
