#include<stdio.h>

int maxIndex(int arr[], int length){
    int index = 0, elem = arr[0], aux;

    for(int i = 0; i < length; i++) {
        aux = arr[i];
        if (aux > elem) {
            elem = aux;
            index = i;
        }
    }
    return index;   
}

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    printf("El elemento maximo esta en el indice %d\n", maxIndex(arr, 5));
    return 0;
}
