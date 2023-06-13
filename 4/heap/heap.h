#ifndef __HEAP_H__
#define __HEAP_H__

typedef int (*FuncionComparadora)(void *, void *);
typedef void (*FuncionDestructora)(void *);
typedef void (*FuncionVisitante)(void *);
typedef void *(*FuncionCopiadora)(void *);

typedef struct _BHeap {
  void **arr;
  int capacidad;
  int ultimo;
  FuncionComparadora comp;
  FuncionCopiadora copy;
} *BHeap;

BHeap bheap_crear(int capacidad, FuncionComparadora comp, FuncionCopiadora copy);

void bheap_destruir(BHeap heap, FuncionDestructora destroy);

int bheap_es_vacio(BHeap heap);

void bheap_recorrer(BHeap heap, FuncionVisitante visit);

void bheap_insertar(BHeap heap, void *dato);

void *bheap_getmax(BHeap heap);

void bheap_eliminar_max(BHeap heap, FuncionDestructora destroy);

BHeap bheap_crear_desde_arr(void **arr, int largo, FuncionCopiadora copiar,
                            FuncionComparadora comp, FuncionVisitante visit);

#endif