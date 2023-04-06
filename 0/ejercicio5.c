#define MINIMUM2(a,b) ((a)<(b) ? (a):(b))
#define MINIMUM3(a,b,c) (MINIMUM2(a,b)<(c) ? MINIMUM2(a,b):(c))
#include <stdio.h>

int main(){
    int a = 5, b = 7, c = 3;
    printf("El minimo es %d\n", MINIMUM3(a,b,c));
    return 0;
}

