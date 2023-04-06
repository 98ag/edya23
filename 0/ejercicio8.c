#define SUMARRAY(arr, len) ({int k = 0; for(int i = 0; i < len; (k += arr[i]), i++); k;})
#include <stdio.h>

int main() {
  int a[5] = { 1, 2, 3, 4, 5 };
  int b;
  b = SUMARRAY(a, 5);
  printf("%d\n", b);
  return 0;
}
