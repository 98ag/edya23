#include "matriz.h"

struct Matriz_ {
  float **direccion;
  int filas;
  int columnas;
};

Matriz *matrizCrear(int filas, int columnas) {
  Matriz *ret = malloc(sizeof(Matriz));
  ret->direccion = malloc(sizeof(float *) * filas);

  for (int i = 0; i < filas; i++)
    ret->direccion[i] = malloc(sizeof(float) * columnas);

  ret->filas = filas;
  ret->columnas = columnas;
  return ret;
}

void matrizDestruir(Matriz * matriz) {
  int filas = matriz->filas;

  for (int i = 0; i < filas; i++)
    free(matriz->direccion[i]);

  free(matriz->direccion);
  free(matriz);
}

void matrizEscribir(Matriz * matriz, int fila, int columna, int dato) {
  matriz->direccion[fila - 1][columna - 1] = dato;
}

float matrizLeer(Matriz * matriz, int fila, int columna) {
  return matriz->direccion[fila - 1][columna - 1];
}

int matrizNumFilas(Matriz * matriz) {
  return matriz->filas;
}

int matrizNumColumnas(Matriz * matriz) {
  return matriz->columnas;
}

void matrizIntercambiarFilas(Matriz * matriz, int fila1, int fila2) {
  int columnas = matriz->columnas;
  float aux;
  for (int i = 0; i < columnas; i++) {
    aux = matriz->direccion[fila1 - 1][i];
    matriz->direccion[fila1 - 1][i] = matriz->direccion[fila2 - 1][i];
    matriz->direccion[fila2 - 1][i] = aux;
  }
}

void matrizInsertarFila(Matriz * matriz, int pos) {
  int filas = matriz->filas + 1;
  float **newMatriz = malloc(sizeof(float *) * filas);
  float *newFila = malloc(sizeof(float) * matriz->columnas);

  for (int i = 0; i < filas; i++) {
    if (i < pos - 1)
      newMatriz[i] = matriz->direccion[i];
    else if (i == pos - 1)
      newMatriz[i] = newFila;
    else
      newMatriz[i] = matriz->direccion[i - 1];
  }

  free(matriz->direccion);      // Libero SOLO direccion ya que reutilizo
  matriz->direccion = newMatriz;        // las columnas
  matriz->filas = filas;
}

void matrizImprimirEntera(Matriz * matriz) {
  int filas = matriz->filas;
  int columnas = matriz->columnas;

  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      printf("%.2f ", matrizLeer(matriz, i + 1, j + 1));
    }
    printf("\n");
  }
}
