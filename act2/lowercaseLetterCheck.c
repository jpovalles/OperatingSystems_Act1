/* Write a program in C to function to check lowercase letter*/
#include <stdio.h>

int main(){

	char letter;
	printf("Ingrese una letra:");
	scanf("%c", &letter);
	printf("Esta es la letra leida: %c\n", letter);
	int ascii = (int)letter;
	if(letter <= 122 && letter >= 97){
		printf("El caracter ingresado es minuscula\n");
	}
	else{
		printf("El caracter NO es una minuscula");
	}
	
	return 0;

}
