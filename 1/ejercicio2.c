#include <stdio.h>

int string_len(char *str) {
  int i;
  for (i = 0; str[i] != '\0'; i++);
  return i;
}

// a  b  c
// 0  1 -1

// a     b     c     d      e      f   len = 5 -> len / 2 = 2
// 0     1     2     3      4      5
//                  len-3  len-2  len-1

//a  b  c  d  e  f  g       len = 6 -> len /2 = 3
//0  1  2  3  l-3 l-2 l-1 
//         l-4

void string_reverse(char *str) {
  int length = string_len(str);

  for (int i = 0; i < length / 2; i++) {
    char aux = str[i];
    int reverseIndex = length - i - 1;
    str[i] = str[reverseIndex];
    str[reverseIndex] = aux;
  }
}


int string_concat(char *str1, char *str2, int max) {
  int str1Len = string_len(str1);

  for (int i = 0; i < max; i++) {
    char aux = str2[i];
    str1[str1Len + i] = aux;

    if (aux == '\0')
      return i;
  }
  str1[str1Len + max] = '\0';
  return max;
}

int string_subcadena(char *str1, char *str2) {
  int len1 = string_len(str1);  // 7
  int len2 = string_len(str2);  // 2
  int index = 0;

  for (int i = 0; i < len1; i++) {      // 7 - 2 = 5
    if (str1[i] == str2[index])
      index++;                  // Si dos letras son iguales, aumenta index
    else                        //  y compara siguiente en prox loop
      index = 0;                // Si no se vuelve a comparar la primer letra
    //  de la segunda palabra prox loop
    if (index == len2)
      return i - len2 + 1;      // Retornar el index de la primera letra que coincide
    if (len1 - i < len2)
      return -1;                // Retornar -1 si hay lo que queda de palabra 1
  }                             //  es menor a palabra 2
}

void string_unir(char *arregloStrings[], int n, char *sep, char *res) {
  int len;

  for (int i = 0; i < n; i++) {
    len = string_len(arregloStrings[i]);
    string_concat(res, arregloStrings[i], len);
    if (i < n - 1) {
      len = string_len(sep);
      string_concat(res, sep, len);
    }
  }
}



int main() {

  char strTest[30];
  printf("Ingrese string:");
  scanf("%s", strTest);

  // Test len
  //printf("Largo de 'abc' es: %d\n", string_len(strTest));

  // Test reverse
  /*
     string_reverse(strTest);
     printf("La cadena 'abcdef' invertida es: %s\n", strTest);
   */

  // Test concat
  /*
     char strTestConcat[30];
     printf("Ingrese string a concatenar:");
     scanf("%s", strTestConcat);

     printf("Se concatenan %d caracteres a str1 y resulta %s\n",
     string_concat(strTest, strTestConcat, 5), strTest);
   */

  // Test subcadena
  /*
     char strTestSubcadena[30];
     printf("Ingrese string a buscar:");
     scanf("%s", strTestSubcadena);

     int resultado = string_subcadena(strTest, strTestSubcadena);
     printf("Resultado: %d\n", resultado);
   */

  // Test unir
  char res[50];
  char *cadenas[3] = { "abc", "def", "gih" };

  string_unir(cadenas, 3, strTest, res);

  printf("Resultado: %s\n", res);


  return 0;
}
