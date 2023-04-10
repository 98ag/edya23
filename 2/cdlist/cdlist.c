#include<stdlib.h>
#include"cdlist.h"

CDList cdlist_crear() {
  CDList new = malloc(sizeof(struct _CDList));
  new->primero = NULL;
  new->ultimo = NULL;
  return new;
}

int cdlist_es_vacia(CDList lista) {
  return (lista->primero == NULL || lista->ultimo == NULL) ? 1 : 0;
}

void cdlist_agregar(CDList lista, int dato, PosicionAgregado pos) {
  CDNodo *new = malloc(sizeof(CDNodo));
  new->dato = dato;
  
  if (cdlist_es_vacia(lista)) {
    new->sig = new->ant = NULL;
    lista->primero = lista->ultimo = new;
  }
  else{
    lista->ultimo->sig = new;
    new->sig = lista->primero;
    new->ant = lista->ultimo;
    (pos) ? (lista->ultimo = new) : (lista->primero = new);
  }
}

void cdlist_destruir(CDList lista) {
  CDNodo *aux = lista->primero;
  CDNodo *auxfree;

  while (aux != lista->ultimo) {
    auxfree = aux;
    aux = aux->sig;
    free(auxfree);
  }
  free(lista->ultimo);
  free(lista);
}

void cdlist_recorrer(CDList lista, FuncionVisitante visit) {
  CDNodo *aux = lista->primero;
  while(aux != lista->ultimo) {
    visit(aux->dato);
    aux = aux->sig;
  }
  visit(aux->dato);
}