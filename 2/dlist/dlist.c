#include<stdlib.h>
#include<stdio.h>
#include"dlist.h"

DList dlist_crear() {
  DList new = malloc(sizeof(struct _DList));
  new->primero = NULL;
  new->ultimo = NULL;
  return new;
}

void dlist_agregar_inicio(DList lista, int dato){
  DNodo *new = malloc(sizeof(DNodo));
  new->dato = dato;
  new->ant = NULL;

  if (lista->primero == NULL) {
    new->sig = NULL;
    lista->ultimo = new;
  }
  else 
    new->sig = lista->primero;
  
  lista->primero = new;
}

void dlist_agregar_final(DList lista, int dato) {
  DNodo *new = malloc(sizeof(DNodo));
  new->dato = dato;
  new->sig = NULL;

  if (lista->ultimo == NULL) {
    new->ant = NULL;
    lista->primero = new;
  }
  else{
    lista->ultimo->sig = new;
    new->ant = lista->ultimo;
  }    

  lista->ultimo = new;
}

void dlist_destruir(DList lista) {
  DNodo *aux = lista->primero;
  DNodo *auxFree;

  while (aux != NULL) {
    auxFree = aux;
    aux = aux->sig;
    free(auxFree);
  }

  free(lista);
}

void dlist_recorrer(DList lista, DListOrdenDeRecorrido rec) {
  DNodo *aux;
  if (rec) {
    aux = lista->ultimo;
    while (aux != NULL) {
      printf("%d ", aux->dato);
      aux = aux->ant;
    }
  }
  else {
    aux = lista->primero;
    while (aux != NULL) {
      printf("%d ", aux->dato);
      aux = aux->sig;
    }
  }
  puts("");
}