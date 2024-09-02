#include <stdio.h>
#include <limits.h>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int desbordamiento(int n) {
    int ans = 0;
    unsigned long long resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
        if (resultado > ULLONG_MAX / i) {
            ans = 1; // Puede causar desbordamiento
        }
    }
    return ans; 
}

int main() {
    int numero;
    char opcion;

    do {
        printf("Ingresa un numero para calcular su factorial: ");
        scanf("%d", &numero);

        if (numero < 0) {
            printf("El factorial no está definido para números negativos.\n");
        } else if (desbordamiento(numero)) {
            printf("El factorial de %d es demasiado grande y puede causar desbordamiento.\n", numero);
        } else {
            printf("El factorial de %d es %llu\n", numero, factorial(numero));
        }

        printf("¿Deseas calcular otro factorial? (s/n): ");
        scanf(" %c", &opcion);
    } while (opcion == 's' || opcion == 'S');

    printf("Programa terminado.\n");
    return 0;
}