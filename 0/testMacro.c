#define macro_max(a,b) ((a)>(b)?(a):(b))
#include <stdio.h>

int func_max(int a, int b){
    return (a > b ? a : b);
}

int main(){
    int a = 2, b = 3, max;

    printf("max: %d, a; %d, b: %d\n", func_max(a++,b--), a, b);

    return 0;
}