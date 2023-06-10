#ifndef __GPILA_H__
#define __GPILA_H__

#include "glist.h"

typedef GList Pila;

Pila pila_crear();

void pila_destruir(Pila pila, FuncionDestructora f);

int pila_es_vacia(Pila pila);

void *pila_tope(Pila pila);

Pila pila_apilar(Pila pila, void *dato, FuncionCopia c);

Pila pila_apilar_nodo(Pila pila, void *ptr);

Pila pila_desapilar(Pila pila, FuncionDestructora f);

Pila pila_desapilar_nodo(Pila pila);

void pila_imprimir(Pila pila, FuncionVisitanteList v);

#endif