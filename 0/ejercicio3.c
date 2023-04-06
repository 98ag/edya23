#define SUM(a,b) ((a)+(b))
#include <stdio.h>

int main(){
    int x = 7, y = 6;
    printf("La suma de %d e %d es %d\n", x, y, SUM(x, y));
    return 0;
}