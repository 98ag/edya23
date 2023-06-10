#ifndef __GQUEUE_H__
#define __GQUEUE_H__

#include "cglist.h"

typedef CGList GQueue;

GQueue cola_crear();

void cola_destruir(GQueue cola, FuncionDestructora destruir);

int cola_es_vacia(GQueue cola);

void *cola_inicio(GQueue cola);

GQueue cola_encolar_nodo(GQueue cola, void *ptr);

GQueue cola_encolar(GQueue cola, void *dato, FuncionCopia copia);

GQueue cola_desencolar(GQueue cola, FuncionDestructora destruir);

GQueue cola_desencolar_nodo(GQueue cola);

void *cola_inicio_nodo(GQueue cola);

void cola_imprimir(GQueue cola, FuncionVisitante visitar);

#endif