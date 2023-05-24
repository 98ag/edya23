#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int estaEnArray(char* arr, int len, char busq) {
  for (int i = 0; i < len; i++) 
    if ((arr[i]) == busq)
      return 1;
  return 0;
}

char* caracteresSimilares(char* arr1, char* arr2) {
  int len1 = strlen(arr1);
  int len2 = strlen(arr2);
  int cont = 0;
  int max = 50;
  char* ret = malloc(sizeof(char) * max);

  for (int i = 0; i < len1; i++) {
    for (int j = 0; j < len2; j++) {
      if (cont == max) {
        max *= 2;
        ret = realloc(ret, sizeof(char) * max);
      }
      else if(arr1[i] == arr2[j] && !(estaEnArray(ret, cont, arr1[i]))) {
        ret[cont] = arr1[i];
        cont++;
      }
    }
  }
  return ret;
}

int main() {
  char *str1 = "A while back I needed to count the amount of letters that a piece of text in an email template had (to avoid passing any character limits). Unfortunately, I could not think of a quick way to do so on my macbook and I therefore turned to the Internet.";
  char *str2 = "You can copy and paste your text with the characters to count in the text area above, or you can type your characters and words into the text area. The counter will be updated instantly, displaying the amount of characters, words, sentences, paragraphs and whitespace in your text, not to mention that the keyword density (which you can configure from the options menu) is also displayed.";

  printf("%s\n", caracteresSimilares(str1, str2));
}