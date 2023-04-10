#include<stdio.h>
#include"slists.h"

int main() {
  SListS lista = slists_crear();
  slists_agregar_inicio(lista, 1);
  slists_imprimir(lista);

  slists_agregar_final(lista, 2);
  slists_agregar_final(lista, 3);
  slists_imprimir(lista);

  slists_agregar_inicio(lista, 0);
  slists_imprimir(lista);

  slists_destruir(lista);
  return 0;
}