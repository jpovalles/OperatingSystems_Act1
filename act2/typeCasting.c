/* Write a program in c to type casting implicit explicit*/

#include <stdio.h>


void explicitCasting(){
	int opcion = -1;
	int varInt;
	double varDou;
	char varChar;
	float varFloat;
	do{
		printf("\tMenu explicit Casting\n");
		printf("1. Type casting explicit Int\n");
		printf("2. Type casting explicit Float\n");
		printf("3. Type casting explicit Double\n");
		printf("4. Type casting explicit Char\n");
		printf("5. Salir\n");
		printf("Digite su opcion:");
		scanf("%d", &opcion);
		if(opcion == 1){
			printf("Ingrese un valor de tipo entero:");
			scanf("%d", &varInt);
			printf("Esta es la conversion de explicita de int a char con (char)varInt: %c\n", (char)varInt);
			printf("Esta es la conversion de explicita de int a double con (double)varInt: %lf\n", (double)varInt);
			printf("Esta es la conversion de explicita de int a float con (float)varInt: %f\n", (float)varInt);
		}
		else if(opcion == 2){
			printf("Ingrese un valor de tipo double:");
			scanf("%lf", &varDou);
			printf("Esta es la conversion de explicita de double a char con (char)varDou: %c\n", (char)varDou);
			printf("Esta es la conversion de explicita de double a int con (int)varDou: %d\n", (int)varDou);
			printf("Esta es la conversion de explicita de double a float con (float)varDou: %f\n", (float)varDou);
		}
		else if(opcion == 3){
			printf("Ingrese un valor de tipo char:");
			scanf("%c", &varChar);
			printf("Esta es la conversion de explicita de char a double con (double)varChar: %lf\n", (double)varChar);
			printf("Esta es la conversion de explicita de char a int con (int)varChar: %d\n", (int)varChar);
			printf("Esta es la conversion de explicita de char a float con (float)varChar: %f\n", (float)varChar);
		}
		else if(opcion == 4){
			printf("Ingrese un valor de tipo flotante:");
			scanf("%f", &varFloat);
			printf("Esta es la conversion de explicita de float a double con (double)varFloat: %c\n", (double)varFloat);
			printf("Esta es la conversion de explicita de float a int con (int)varFloat: %d\n", (int)varFloat);
			printf("Esta es la conversion de explicita de float a char con (char)varFloat: %c\n", (char)varFloat);
		}
		
		else if(opcion != 5){
			printf("Opcion invalida!\n");
		}
		printf("\n\n");
	}while(opcion != 5);
	printf("\t Saliendo... \n");

}


void implicitCasting() {
    int intVal = 65;
    float floatVal = 123.456f;
    double doubleVal = 789.123456;
    char charVal = 'A';
    float resultFloat;
    double resultDouble;
    char resultChar;
    int resultInt;

    resultFloat = intVal;  
    printf("Implicit Casting: int (%d) a float: %.2f\n", intVal, resultFloat);

    resultDouble = intVal;  
    printf("Implicit Casting: int (%d) a double: %.6lf\n", intVal, resultDouble);

    resultChar = intVal;  
    printf("Implicit Casting: int (%d) a char: '%c'\n", intVal, resultChar);

    resultInt = floatVal;  
    printf("Implicit Casting: float (%.3f) a int: %d\n", floatVal, resultInt);

    resultDouble = floatVal;  
    printf("Implicit Casting: float (%.3f) a double: %.6lf\n", floatVal, resultDouble);

    resultChar = floatVal;  
    printf("Implicit Casting: float (%.3f) a char: '%c'\n", floatVal, resultChar);

    resultInt = doubleVal;  
    printf("Implicit Casting: double (%.6lf) a int: %d\n", doubleVal, resultInt);

    resultFloat = doubleVal;  
    printf("Implicit Casting: double (%.6lf) a float: %.3f\n", doubleVal, resultFloat);

    resultChar = doubleVal;  
    printf("Implicit Casting: double (%.6lf) a char: '%c'\n", doubleVal, resultChar);

    resultInt = charVal;  
    printf("Implicit Casting: char ('%c') a int: %d\n", charVal, resultInt);

    resultFloat = charVal;  
    printf("Implicit Casting: char ('%c') a float: %.3f\n", charVal, resultFloat);

    resultDouble = charVal;  
    printf("Implicit Casting: char ('%c') a double: %.6lf\n", charVal, resultDouble);
}

void menu(){
	int opcion = -1;
	do{
		printf("\tMenu\n");
		printf("1. Ver type casting explicit\n");
		printf("2. Ver type casting implicit\n");
		printf("3. Salir\n");
		
		printf("Digite su opcion:");
		scanf("%d", &opcion);
		
		if(opcion == 1){
			printf("\n\n");
			explicitCasting();
		}
		else if(opcion == 2){
			printf("\n\n");
			implicitCasting();
		}
		else if(opcion != 3){
			printf("Opcion invalida!\n");
		}
		
		printf("\n\n");
	}while(opcion != 3);
	printf("\t Saliendo... \n");
}

int main(){
	menu();
	return 0;
}

