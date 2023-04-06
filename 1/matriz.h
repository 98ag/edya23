#ifndef __MATRIZ_H__
#define __MATRIZ_H__

#include<stdlib.h>
#include<stdio.h>

typedef struct Matriz_ Matriz;

Matriz *matrizCrear(int filas, int columnas);

void matrizDestruir(Matriz * matriz);

void matrizEscribir(Matriz * matriz, int fila, int columna, int dato);

float matrizLeer(Matriz * matriz, int fila, int columna);

int matrizNumFilas(Matriz * matriz);

int matrizNumColumnas(Matriz * matriz);

void matrizIntercambiarFilas(Matriz * matriz, int fila1, int fila2);

void matrizInsertarFila(Matriz * matriz, int pos);

void matrizImprimirEntera(Matriz * matriz);

#endif
