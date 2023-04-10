#include "dlist.h"

int main() {
  DList lista = dlist_crear();
  
  dlist_agregar_inicio(lista, 1);
  dlist_agregar_final(lista, 2);
  dlist_agregar_final(lista, 3);
  dlist_recorrer(lista, DLIST_ATRAS);

  dlist_destruir(lista);
  return 0;
}