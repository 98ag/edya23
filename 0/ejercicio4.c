#define MINIMUM2(a,b) ((a)<(b) ? (a):(b))
#include <stdio.h>

int main(){
    int a,b;
    printf("Introduzca un numero: ");
    scanf("%d", &a);
    printf("Introduzca un numero: ");
    scanf("%d", &b);
    printf("El menor es %d\n", MINIMUM2(a,b));
    return 0;
}