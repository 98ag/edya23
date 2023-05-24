#include<stdlib.h>
#include"gpila.h"
#include"contacto.h"
#include<stdio.h>

GList glist_invertir_orden(GList lista) {
  GNode *auxlist = lista;
  if (lista != NULL) {
    GNode *auxsig = lista->next;    
    lista->next = NULL;
    lista = auxsig;
    while (lista != NULL) {
      auxsig = lista->next;
      lista->next = auxlist;
      auxlist = lista;
      lista = auxsig;
    }
  }
  return auxlist;
}

int main() {
  GList lista = glist_crear();
  Contacto *contactos[6];
  contactos[0] = contacto_crear("Pepe Argento", "3412695452", 61);
  contactos[1] = contacto_crear("Moni Argento", "3412684759", 60);
  contactos[2] = contacto_crear("Coqui Argento", "3415694286", 32);
  contactos[3] = contacto_crear("Paola Argento", "3416259862", 29);
  contactos[4] = contacto_crear("Maria Elena Fuseneco", "3416874594", 59);
  contactos[5] = contacto_crear("Dardo Fuseneco", "3416894526", 64);

  for (int i = 0; i < 6; ++i) {
    lista =
        glist_agregar_inicio(lista, contactos[i], (FuncionCopia)contacto_copia);
    contacto_destruir(contactos[i]);
  }

  printf("Lista:\n");
  glist_recorrer(lista, (FuncionVisitante)contacto_imprimir);
  puts("");

  lista = glist_invertir_orden(lista);
  printf("Lista invertida:\n");
  glist_recorrer(lista, (FuncionVisitante)contacto_imprimir);

  glist_destruir(lista, (FuncionDestructora)contacto_destruir);

  return 0;
}