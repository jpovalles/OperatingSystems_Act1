#include <stdio.h>
#include <stdlib.h>
int esBisiesto(int anio) {
    return ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0));
}

int main() {
    int anioInicio, anioFin, temp;
    int *aniosBisiestos = NULL;
    int count;
    char opcion;

    do {
        count = 0;

        printf("Ingresa el primer año del rango: ");
        scanf("%d", &anioInicio);
        printf("Ingresa el segundo año del rango: ");
        scanf("%d", &anioFin);

        if (anioInicio > anioFin) {
            temp = anioInicio;
            anioInicio = anioFin;
            anioFin = temp;
        }

        aniosBisiestos = (int *)malloc((anioFin - anioInicio + 1) * sizeof(int));

        for (int anio = anioInicio; anio <= anioFin; anio++) {
            if (esBisiesto(anio)) {
                aniosBisiestos[count] = anio;
                count++;
            }
        }

        if (count > 0) {
            printf("Los años bisiestos entre %d y %d son:\n", anioInicio, anioFin);
            for (int i = 0; i < count; i++) {
                printf("%d ", aniosBisiestos[i]);
            }
            printf("\n");
        } else {
            printf("No hay años bisiestos en este rango.\n");
        }

        free(aniosBisiestos);

        printf("¿Deseas ingresar otro rango de años? (s/n): ");
        scanf(" %c", &opcion);

    } while (opcion == 's' || opcion == 'S');

    printf("Programa terminado.\n");
    return 0;
}