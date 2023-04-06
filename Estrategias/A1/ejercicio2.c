#include<stdio.h>

long expn(int b, int n) {
    switch (n){
        case 0:
            return 1;
        case 1:
            return b;
        default:
            long res = b;
            for(int i = 1; i < n; i++)
                res *= b;
            return res;
    }
}

int main(void){
    printf("8 al cubo es %ld\n", expn(8, 3));
    printf("8 a la 0 es %ld\n", expn(8, 0));
    return 0;
}