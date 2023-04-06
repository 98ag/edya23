#include <stdio.h>
#include "matriz.h"

int main() {
  Matriz *mat = matrizCrear(3, 3);

  matrizEscribir(mat, 1, 1, 1);
  matrizEscribir(mat, 2, 2, 2);
  matrizEscribir(mat, 3, 3, 3);
  matrizImprimirEntera(mat);
  puts("");

  matrizIntercambiarFilas(mat, 1, 3);
  matrizImprimirEntera(mat);
  puts("");

  matrizInsertarFila(mat, 2);
  matrizImprimirEntera(mat);

  matrizDestruir(mat);
  return 0;
}
