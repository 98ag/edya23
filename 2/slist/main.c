#include "slist.h"
#include <stdio.h>
#include <stdlib.h>

static void imprimir_entero(int dato) { printf("%d ", dato); }

int main(void) {

  SList lista = slist_crear();

  lista = slist_agregar_inicio(lista, 3);
  lista = slist_agregar_inicio(lista, 2);
  lista = slist_agregar_inicio(lista, 1);
  lista = slist_agregar_final(lista, 4);

  printf(" · Parto de una lista\n");
  slist_recorrer(lista, imprimir_entero);
  puts("");
  int longitud = slist_longitud(lista);
  printf("La lista tiene %d elementos\n", longitud);

  // Una vez concatenadas las listas, si modifico esta tambien cambia la primera
  SList lista2 = slist_crear();             // no necesita free ya que es parte de lista
  lista2 = slist_agregar_inicio(lista2, 5);
  lista2 = slist_agregar_final(lista2, 6);
  lista2 = slist_agregar_final(lista2, 7);
  lista2 = slist_agregar_final(lista2, 8);

  printf(" · Concateno lista 2 a lista 1\n");
  lista = slist_concatenar(lista, lista2);
  slist_recorrer(lista, imprimir_entero);
  puts("");

  longitud = slist_longitud(lista);
  printf("La lista concatenada tiene %d elementos\n", longitud);

  printf(" · Inserto 15 posicion 22, elimino posicion 6 (6)\n");
  lista = slist_insertar(lista, 22, 15);
  lista = slist_eliminar(lista, 6);
  slist_recorrer(lista, imprimir_entero);
  puts("");

  int datoABuscar = 20;

  // Se puede responder lo mismo con slist_indice (igualmente esto funciona)
  /*
  slist_contiene(lista, datoABuscar) ? 
    printf("Contiene el dato %d\n", datoABuscar) : 
    printf("No contiene el dato %d\n", datoABuscar);
  */
  
  int indexDato = slist_indice(lista, datoABuscar);
  printf(" · Busco el elemento %d en la lista\n", datoABuscar);

  (slist_indice(lista, datoABuscar) == -1) ?
    printf("No contiene el dato %d\n", datoABuscar) :
    printf("Contiene el dato %d en la posicion %d\n", datoABuscar, indexDato);
  puts("");
  printf(" · Nueva lista testList\n");
  SList testList = slist_crear();
  testList = slist_agregar_final(testList, 2);
  testList = slist_agregar_final(testList, 5);
  testList = slist_agregar_final(testList, 8);
  testList = slist_agregar_final(testList, 22);
  slist_recorrer(testList, imprimir_entero);
  puts("");

  printf(" · Interseco lista y testList (Elementos en comun)\n");
  SList testIntersec = slist_intersecar(lista, testList);
  slist_recorrer(testIntersec, imprimir_entero);
  puts("");

  printf(" · Revierto la lista lista\n");
  SList testRevertir = slist_crear();
  testRevertir = slist_reverso(lista);
  slist_recorrer(testRevertir, imprimir_entero);
  puts("");

  printf(" · Intercalo las listas lista y revertida\n");
  SList testIntercalar = slist_crear();
  testIntercalar = slist_intercalar(lista, testRevertir);
  slist_recorrer(testIntercalar, imprimir_entero);
  puts("");

  printf(" · Parto lista e imprimo la mitad (o la mitad - 1 si es impar)\n");
  SList test = slist_partir(lista);       // no necesita free ya que es parte de lista
  slist_recorrer(test, imprimir_entero);
  puts("");

  slist_destruir(lista);
  slist_destruir(testList);
  slist_destruir(testIntersec);
  slist_destruir(testRevertir);
  slist_destruir(testIntercalar);

  return 0; 
}
