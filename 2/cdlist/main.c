#include"cdlist.h"
#include<stdio.h>

static void imprimir_entero(int dato) { printf("%d ",dato); }

int main() {
  CDList lista = cdlist_crear();
  cdlist_agregar(lista, 1, AGREGAR_INICIO);
  cdlist_agregar(lista, 2, AGREGAR_FINAL);
  cdlist_agregar(lista, 3, AGREGAR_FINAL);

  cdlist_recorrer(lista, imprimir_entero);
  puts("");
  cdlist_destruir(lista);
  return 0;
}