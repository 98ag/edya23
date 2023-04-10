#ifndef __DLIST_H__
#define __DLIST_H__

typedef struct _DNodo {
  int dato;
  struct _DNodo* sig;
  struct _DNodo* ant;
} DNodo;

typedef struct _DList{
  DNodo* primero;
  DNodo* ultimo;
} *DList;

typedef enum {
  DLIST_ADELANTE,
  DLIST_ATRAS
} DListOrdenDeRecorrido;

DList dlist_crear();

void dlist_agregar_inicio(DList lista, int dato);

void dlist_agregar_final(DList lista, int dato);

void dlist_destruir(DList lista);

void dlist_recorrer(DList lista, DListOrdenDeRecorrido rec);
#endif