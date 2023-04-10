#include<stdlib.h>
#include<stdio.h>
#include"slists.h"

SListS slists_crear() {
  SListS ret;
  ret = malloc(sizeof(struct _SListS));
  ret->primero = NULL;
  ret->ultimo = NULL;
  return ret;
}

void slists_agregar_inicio(SListS lista, int dato) {
    SNodo* new = malloc(sizeof(SNodo));
    new->dato = dato;
    new->sig = lista->primero;
    lista->primero = new;

    if (lista->ultimo == NULL)
      lista->ultimo = new;
}

void slists_agregar_final(SListS lista, int dato) {
    SNodo* new = malloc(sizeof(SNodo));
    new->dato = dato;
    new->sig = NULL;

    if (lista->ultimo != NULL)
      lista->ultimo->sig = new;

    lista->ultimo = new;

    if (lista->primero == NULL)
      lista->primero = new;
}

void slists_imprimir(SListS lista) {
  SNodo *aux = lista->primero;

  while (aux != NULL) {
    printf("%d ", aux->dato);
    aux = aux->sig;
  }
  puts("");
}

void slists_destruir(SListS lista) {
  SNodo *aux = lista->primero;
  SNodo *auxFree;

  while (aux != NULL) {
    auxFree = aux;
    aux = aux->sig;
    free(auxFree);
  }

  free(lista);
}