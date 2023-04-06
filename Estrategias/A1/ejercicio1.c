#include<stdio.h>
#include<time.h>

unsigned long fibIter(int num) {
    unsigned long sum, aux1 = 0, aux2 = 1;
    for (int i = 1; i < num; i++) {
        sum = aux1 + aux2;
        aux1 = aux2;
        aux2 = sum;
    }
    return sum;
}

unsigned long fibRecur(int num) {
    if (num <= 1)
        return num;

    return fibRecur(num - 2) + fibRecur (num - 1);
    }

int main(void){
    unsigned long fib1 = 0, fib2 = 0;
    clock_t start, end;
    double duration;

    start = clock();
    fib1 = fibIter(45);
    end = clock();

    duration = ((double) end - start)/CLOCKS_PER_SEC;
    printf("Fibonacci Iterativo: Res %ld | Tiempo %lf\n", fib1, duration);
      
    start = clock();
    fib2 = fibRecur(45);
    end = clock();

    duration = ((double) end - start)/CLOCKS_PER_SEC;
    printf("Fibonacci Recursivo: Res %ld | Tiempo %lf\n", fib2, duration);
    
    return 0;
}