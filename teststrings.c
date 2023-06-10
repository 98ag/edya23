#include <stdio.h>
#include <stdlib.h>

int main() {
  char *str = malloc(4);
  str[0] = 'a';
  str[1] = 'b';
  str[2] = 'k';
  str[3] = '\0';

  printf("%s\n", str);

  free(str);
  return 0;
}