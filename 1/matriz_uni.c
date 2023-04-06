#include "matriz.h"

struct Matriz_ {
  int filas;
  int columnas;
  float *direccion;
};

Matriz *matrizCrear(int filas, int columnas) {
  Matriz *ret = malloc(sizeof(Matriz));
  ret->direccion = malloc(sizeof(float) * (filas * columnas));
  ret->filas = filas;
  ret->columnas = columnas;
  return ret;
}

void matrizDestruir(Matriz * matriz) {
  free(matriz->direccion);
  free(matriz);
}

void matrizEscribir(Matriz * matriz, int fila, int columna, int dato) {
  matriz->direccion[(fila - 1) * matriz->columnas + (columna - 1)] = dato;
}

float matrizLeer(Matriz * matriz, int fila, int columna) {
  return matriz->direccion[(fila - 1) * matriz->columnas + (columna - 1)];
}

int matrizNumFilas(Matriz * matriz) {
  return matriz->filas;
}

int matrizNumColumnas(Matriz * matriz) {
  return matriz->columnas;
}

void matrizIntercambiarFilas(Matriz * matriz, int fila1, int fila2) {
  int columnas = matriz->columnas;
  int pos1 = columnas * (fila1 - 1);
  int pos2 = columnas * (fila2 - 1);
  float aux;

  for (int i = 0; i < columnas; i++) {
    aux = matriz->direccion[pos1 + i];
    matriz->direccion[pos1 + i] = matriz->direccion[pos2 + i];
    matriz->direccion[pos2 + i] = aux;
  }
}

void matrizInsertarFila(Matriz * matriz, int pos) {
  int newFilas = matriz->filas + 1;
  int columnas = matriz->columnas;
  int nuevaFilaPos = columnas * (pos - 1);
  float *newMatriz = malloc(sizeof(float) * (newFilas * matriz->columnas));

  for (int i = 0; i < newFilas * columnas; i++) {
    if (i < nuevaFilaPos)
      newMatriz[i] = matriz->direccion[i];
    else if (i > nuevaFilaPos + columnas)
      newMatriz[i] = matriz->direccion[i - columnas];
  }

  free(matriz->direccion);
  matriz->filas = newFilas;
  matriz->direccion = newMatriz;
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
