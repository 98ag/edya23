#include "slist.h"
#include <stdlib.h>
#include<stdio.h>

SList slist_crear() { return NULL; }

void slist_destruir(SList lista) {
  SNodo *nodoAEliminar;
  while (lista != NULL) {
    nodoAEliminar = lista;
    lista = lista->sig;
    free(nodoAEliminar);
  }
}

int slist_vacia(SList lista) { return lista == NULL; }

SList slist_agregar_final(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = NULL;

  if (lista == NULL)
    return nuevoNodo;

  SList nodo = lista;
  for (; nodo->sig != NULL; nodo = nodo->sig)
    ;
  /* ahora 'nodo' apunta al ultimo elemento en la lista */

  nodo->sig = nuevoNodo;
  return lista;
}

SList slist_agregar_inicio(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = lista;
  return nuevoNodo;
}

void slist_recorrer(SList lista, FuncionVisitante visit) {
  for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig)
    visit(nodo->dato);
}

int slist_longitud(SList lista) {
  int cont = 0;
  for (; lista != NULL; lista = lista->sig, cont++)
    ;
  return cont;
}

SList slist_concatenar(SList listaDestino, SList listaConcat) {
  SList aux = listaDestino;
  while(aux->sig != NULL){
    aux = aux->sig;
  }
  aux->sig = listaConcat;
  return listaDestino;
}

SList slist_insertar(SList lista, int pos, int dato) {
  SList aux = lista;
  if (pos == 1)
    return slist_agregar_inicio(lista, dato);

  else {
    for (int i = 2; i < pos; i++){
      if (aux->sig == NULL)
        return slist_agregar_final(lista, dato);
      else
        aux = aux->sig;
    }

    SList new = malloc(sizeof(SNodo));
    new->dato = dato;
    new->sig = aux->sig;

    aux->sig = new;
    return lista;
  }
}

SList slist_eliminar(SList lista, int pos){
  SList aux = lista, auxAnterior;
  if (pos != 1) {
    for (int i = 1; i < pos; i++) {
      auxAnterior = aux;
      aux = aux->sig;
    }
    auxAnterior->sig = aux->sig;
  }
  else {
    lista = aux->sig;
  }
  free(aux);
  return lista;
}

int slist_contiene(SList lista, int dato) {
  while(lista != NULL)
    if (lista->dato == dato)
      return 1;
    else
      lista = lista->sig;
  
  return 0;
}

int slist_indice(SList lista, int dato) {
  for (int i = 1; lista != NULL; i++) {
    if (lista->dato == dato)
      return i;
    else
      lista = lista->sig;
  }
  return -1;
}

SList slist_intersecar(SList lista1, SList lista2) {
  SList nueva = slist_crear(), auxL1 = lista1, auxL2 = lista2;

  for ( ; auxL1 != NULL; auxL1 = auxL1->sig) {
    for ( ; auxL2 != NULL; auxL2 = auxL2->sig) {
      if (auxL1->dato == auxL2->dato) {
        nueva = slist_agregar_final(nueva, auxL1->dato);
      }
    }
    auxL2 = lista2; //Importante: volver al primer nodo de la lista 2 para seguir comparando
  }
  return nueva;
}

SList slist_intersecar_custom(SList lista1, SList lista2, int (*FuncionComparadora)(int dato1, int dato2)) {
  SList nueva = slist_crear(), auxL1 = lista1, auxL2 = lista2;

  for ( ; auxL1 != NULL; auxL1 = auxL1->sig) {
    for ( ; auxL2 != NULL; auxL2 = auxL2->sig) {
      if (FuncionComparadora(auxL1->dato, auxL2->dato)) {
        nueva = slist_agregar_final(nueva, auxL1->dato);
      }
    }
    auxL2 = lista2; //Importante: volver al primer nodo de la lista 2 para seguir comparando
  }
  return nueva;
}

SList slist_reverso(SList lista) {
  SList aux, ret = slist_crear();
  int largo = slist_longitud(lista);

  // Si tiene 10 elementos voy de 9 a 0
  for (int i = largo - 1; i >= 0; i--) {  
    aux = lista;
    // Voy al nodo i y copio
    for (int j = 0; j < i; j++)  {
      aux = aux->sig;
    }
    ret = slist_agregar_final(ret, aux->dato);
  }
  return ret;
}

SList slist_intercalar(SList lista1, SList lista2) {
  SList ret = slist_crear();

  while(lista1 != NULL || lista2 != NULL) {
    if(lista1 != NULL) {
      ret = slist_agregar_final(ret, lista1->dato);
      lista1 = lista1->sig;
    }
    
    if(lista2 != NULL) {
      ret = slist_agregar_final(ret, lista2->dato);
      lista2 = lista2->sig;
    }      
  }
  return ret;
}

SList slist_partir(SList lista) {
  int largo = slist_longitud(lista);  
  int indiceMitad = (largo % 2) ? ((largo / 2) + 1) : (largo / 2); 
  for (int i = 0; i < indiceMitad; lista = lista->sig, i++);
  return lista;
}