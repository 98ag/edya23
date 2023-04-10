#ifndef __CDLIST_H__
#define __CDLIST_H__

typedef void (*FuncionVisitante)(int dato);

typedef enum {
  AGREGAR_INICIO,
  AGREGAR_FINAL
} PosicionAgregado;

typedef struct _CDNodo {
  int dato;
  struct _CDNodo* sig;
  struct _CDNodo* ant;
} CDNodo;

typedef struct _CDList{
  CDNodo* primero;
  CDNodo* ultimo;
} *CDList;

CDList cdlist_crear();

int cdlist_es_vacia(CDList lista);

//Agregar al inicio o al final es lo mismo para lista circular
void cdlist_agregar(CDList lista, int dato, PosicionAgregado pos);

void cdlist_destruir(CDList lista);

void cdlist_recorrer(CDList lista, FuncionVisitante visit);
#endif