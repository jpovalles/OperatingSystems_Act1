/* Find the greater of three numbers*/

#include <stdio.h>
#include <stdlib.h>



int main() {
    int *arr;
    int i, max;

    arr = (int *)malloc(3 * sizeof(int));

    if (arr == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    printf("Introduce 3 numeros:\n");
    for (i = 0; i < 3; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    max = arr[0];
    for (i = 1; i < 3; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("El numero mayor es: %d\n", max);

    free(arr);

    return 0;
}