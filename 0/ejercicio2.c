#define PI 3.1415
#define VOLUMEN_ESFERA(r) ((PI * 4 / 3) * (r) * (r) * (r))
#include <stdio.h>

int main(){
    printf("  Radio  |  Volumen\n");

    for (int i = 1; i < 11; i++){
        printf("    %d  |  %.2f\n", i, VOLUMEN_ESFERA(i));
    }

    return 0;
}