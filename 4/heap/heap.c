#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

BHeap bheap_crear(int capacidad, FuncionComparadora comp,
                  FuncionCopiadora copy) {
  BHeap newHeap = malloc(sizeof(struct _BHeap));
  newHeap->capacidad = capacidad + 1;
  newHeap->ultimo = 0; // No utilizo el lugar 0 del array, cuento desde indice 1
  newHeap->comp = comp;
  newHeap->copy = copy;
  newHeap->arr = malloc(sizeof(void *) * newHeap->capacidad);
  return newHeap;
}

void bheap_destruir(BHeap heap, FuncionDestructora destroy) {
  if (heap->arr != NULL) {
    if (heap->ultimo != 0) {
      for (int i = 1; i <= heap->ultimo; i++)
        destroy(heap->arr[i]);
    }
    free(heap->arr);
  }
  free(heap);
}

int bheap_es_vacio(BHeap heap) {
  return (heap->ultimo <= 0) ? 1 : 0;
}

void bheap_recorrer(BHeap heap, FuncionVisitante visit) {
  for (int i = 1; i <= heap->ultimo; i++)
    visit(heap->arr[i]);
}

void bheap_insertar(BHeap heap, void *dato) {
  // Si el array esta lleno, no hago nada
  if (heap->ultimo == heap->capacidad - 1)
    return;

  // Crear copia de dato, incremento ultimo y agrego al final del array
  heap->arr[++heap->ultimo] = heap->copy(dato);

  // Hago 'trepar' al elemento hasta su posicion correcta
  for (int j = heap->ultimo;
       j > 1 && heap->comp(heap->arr[j], heap->arr[j / 2]) > 0;
       j = j / 2) {
    void *aux = heap->arr[j];
    heap->arr[j] = heap->arr[j / 2];
    heap->arr[j / 2] = aux;
  }
}

void *bheap_getmax(BHeap heap) {
  if (heap->ultimo == 0)
    return NULL;

  return heap->arr[1];
}

static void bheap_acomodar_arriba_a_abajo(BHeap heap, int index, FuncionVisitante visit) {
  int esMayor = 1; // Variable de control

  while (2 * index <= heap->ultimo && esMayor) {
    int k = 2 * index; // Hijo izquierdo

    // Si tiene hijo derecho y ademas es mas grande que el izquierdo, voy a el
    if (k + 1 <= heap->ultimo && heap->comp(heap->arr[k + 1], heap->arr[k]) > 0)
      k = k + 1;

    // Si arr[index] es mayor o igual que su hijo mayor, termino
    if (heap->comp(heap->arr[index], heap->arr[k]) >= 0)
      esMayor = 0;

    // De lo contrario, lo cambio por su hijo mayor (baja en el arbol)
    else {
      void *aux = heap->arr[index];
      heap->arr[index] = heap->arr[k];
      heap->arr[k] = aux;
      index = k;
    }
  }
}

void bheap_eliminar_max(BHeap heap, FuncionDestructora destroy) {
  // Si el array esta vacio, no hago nada
  if (heap->ultimo == 0)
    return;

  void *max = heap->arr[1];
  destroy(max);                             // Elimino elemento mas grande del heap
  heap->arr[1] = heap->arr[heap->ultimo--]; // Traigo el ultimo elemento al principio

  bheap_acomodar_arriba_a_abajo(heap, 1, NULL);
}

BHeap bheap_crear_desde_arr(void **arr, int largo, FuncionCopiadora copiar,
                            FuncionComparadora comp, FuncionVisitante visit) {
  BHeap new = bheap_crear(largo, comp, copiar);
  for (int i = 0; i < largo; i++) {
    new->arr[++new->ultimo] = copiar(arr[i]);
  }
  int ultimoNodoNoHoja = new->ultimo / 2;

  // arr[largo] es la ultima hoja del heap, luego su padre arr[largo/2]
  //  es el ultimo nodo con hijos (por virtud de ser un arbol completo)

  // Luego de copiar los elementos, acomodo todos los 'no hojas' para armar el heap
  for (int i = ultimoNodoNoHoja; i > 0; i--) {
    bheap_acomodar_arriba_a_abajo(new, i, visit);
  }
  return new;
}

/* Parte de eliminar max
    int esMayor = 1; // Variable que utilizo para seguir operando
    int j = 1;

    // Mientras haya hijo izquierdo y ademas arr[j] sea mayor
    while (2 * j <= heap->ultimo && esMayor) {
      int k = 2 * j; // Hijo izquierdo

      // Si tiene hijo derecho y ademas el mas grande que el hijo izquierdo
      //  elijo ese
      if (k + 1 <= heap->ultimo && heap->comp(heap->arr[k + 1], heap->arr[k]))
        k++;

      // Si arr[j] es mayor que su hijo mayor, termino
      if (comp(heap->arr[j], heap->arr[k]))
        esMayor = 0;

      // De lo contrario, lo cambio por su hijo mayor (baja en el arbol)
      else {
        void *aux = heap->arr[j];
        heap->arr[j] = heap->arr[k];
        heap->arr[k] = aux;
      }
    }
    */

/* Parte de armar de array
int esMayor = 1;

while (2 * i <= new->ultimo && esMayor) {
  int k = 2 * i; // Hijo izquierdo

  // Si tiene hijo derecho y ademas el mas grande que el hijo izquierdo
  //  elijo ese
  if (k + 1 <= new->ultimo &&new->comp(new->arr[k + 1], new->arr[k]))
    k++;

  // Si arr[j] es mayor que su hijo mayor, termino
  if (comp(new->arr[i], new->arr[k]))
    esMayor = 0;

  // De lo contrario, lo cambio por su hijo mayor (baja en el arbol)
  else {
    void *aux = new->arr[i];
    new->arr[i] = new->arr[k];
    new->arr[k] = aux;
  }
}
*/