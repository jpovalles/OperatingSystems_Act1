#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct Nodo {
    float Nota;
    float porcentaje;
    char *mensaje;
    struct Nodo *siguiente;
} Nodo;

Nodo* crearNodo(const char *mensaje, float porcentajeN) {
    Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->mensaje = strdup(mensaje);
    nuevoNodo->Nota = 0.0;
    nuevoNodo->porcentaje = porcentajeN;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

void agregarMensajeP(Nodo **inicio, const char *mensaje, float porcen) {
    Nodo *nuevoNodo = crearNodo(mensaje, porcen);
    if (*inicio == NULL) {
        *inicio = nuevoNodo;
    } else {
        Nodo* actual = *inicio;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

void modificarNota(Nodo *inicio, int indice, float notaN) {
    int ind = -1;
    Nodo *actual = inicio;
    while (actual != NULL && ind != indice) {
        actual = actual->siguiente;
        ind++;
    }
    if (actual != NULL) {
        actual->Nota = notaN;
        printf("Nota Modificada Con Éxito\n");
    } else {
        printf("Índice no válido\n");
    }
}

void imprimirMensaje(Nodo *inicio, int indiceBusqueda) {
    int indice = -1;
    Nodo *actual = inicio;
    while (actual != NULL && indice != indiceBusqueda) {
        actual = actual->siguiente;
        indice++;
    }
    if (actual != NULL) {
        printf("%s", actual->mensaje);
        printf("%.2f\n", actual->Nota);
    }
}

float calcularDEFINITIVA(Nodo *inicio) {
    float notaCal = 0.0;
    Nodo *actual = inicio;
    while (actual != NULL) {
        notaCal += (actual->Nota * actual->porcentaje);
        actual = actual->siguiente;
    }
    return notaCal;
}

void liberarMemoria(Nodo *inicio) {
    Nodo *actual = inicio;
    Nodo *temp;
    while (actual != NULL) {
        temp = actual;
        actual = actual->siguiente;
        free(temp->mensaje);
        free(temp);
    }
}

int main() {
    int opcion;
    bool ban = true;
    int in;
    char con[30];
    float notaN = 0;
    Nodo *mensajes = NULL;
    agregarMensajeP(&mensajes, "Laboratorio 1 Retomando C : ", 0.5);
    agregarMensajeP(&mensajes, "Parcial 1 Procesos : ", 0.25);
    agregarMensajeP(&mensajes, "Laboratorio 2 Hilos y Sincronizacion : ", 0.2);
    agregarMensajeP(&mensajes, "Parcial 2 Memoria : ", 0.15);
    agregarMensajeP(&mensajes, "Laboratorio 3 Planificacion : ", 0.15);
    agregarMensajeP(&mensajes, "Parcial 3 Entrada/Salida : ", 0.2);

    do {
        printf("_____________________Sistemas Operativos APP_______________________\n");
        printf("1. Mostrar Notas\n");
        printf("2. Modificar Notas\n");
        printf("3. Nota Definitiva\n");
        printf("0. Salir\n");
        scanf("%d", &opcion);
        switch(opcion) {
            case 1:
                printf("Curso de Sistemas Operativos 2024/2\n ______________________>* NOTAS *<_______________________\n");
                for (int i = 0; i < 6; i++) {
                    printf("%d) ", i + 1);
                    imprimirMensaje(mensajes, i);
                }
                break;
            case 2:
                do {
                    printf("Curso de Sistemas Operativos 2024/2\n ______________________>* MODIFICADOR DE NOTAS *<______________________\n");
                    for (int i = 0; i < 6; i++) {
                        printf("%d) ", i + 1);
                        imprimirMensaje(mensajes, i);
                    }
                    printf("Ingrese el Id de la Nota que desea modificar: ");
                    scanf("%d", &in);

                    if (in >= 1 && in <= 6) {
                        do {
                            printf("\nIngrese la nueva Nota: ");
                            scanf("%f", &notaN);
                            if (notaN >= 0 && notaN <= 5) {
                                modificarNota(mensajes, in - 1, notaN);
                                ban = false;
                            } else {
                                printf("Nota fuera de rango\n Desea seguir intentando [Y/N]: ");
                                scanf("%s", con);
                                if (con[0] >= 'A' && con[0] <= 'Z') {
                                    con[0] = con[0] + 32;
                                }
                                if (con[0] != 'y') {
                                    ban = false;
                                }    
                            }
                        } while (ban);
                    } else {
                        printf("Id de la Nota no existe\n Desea seguir intentando [Y/N]: ");
                        scanf("%s", con);
                        if (con[0] >= 'A' && con[0] <= 'Z') {
                            con[0] = con[0] + 32;
                        }
                        if (con[0] != 'y') {
                            ban = false;
                        }
                    }
                } while (ban);
                break;
            case 3:
                printf("Curso de Sistemas Operativos 2024/2\n______________________>* NOTA DEFINITIVA DEL CURSO *<______________________\n");
                float def = calcularDEFINITIVA(mensajes);
                printf("La nota definitiva del curso es: %.2f\n", def);
                break;
            case 0:
                printf("Saliendo del programa...\n");
                liberarMemoria(mensajes);
                break;
            default:
                printf("Opción no válida. Inténtalo de nuevo.\n");
        }
    } while(opcion != 0);

    return 0;
}