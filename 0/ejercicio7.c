#include <stdio.h>
#define PRINTARRAY(arr, len) for(int i = 0; i < len; printf("%d\n", arr[i]), i++)

int main(){
    int arr[5] = {1,2,3,4,5};
    PRINTARRAY(arr, 5);
    return 0;
}