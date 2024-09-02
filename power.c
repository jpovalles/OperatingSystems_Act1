#include <stdio.h>
#include <stdlib.h>

int main(){
	int base;
	int exponente;
	do{
		printf("Ingrese la base: ");
		scanf("%d", &base);
		printf("Ingrese el exponente: ");
		scanf("%d", &exponente);
		if(base==0 && exponente == 0){
			printf("Indefinido\n\n");
		}else{
			float ans;
			if(exponente<0){
				ans = 1.0/potencia(base, exponente*-1);
			}else{
				ans = potencia(base, exponente);
			} 
			printf("El resultado es: %f\n\n", ans);
		}
	}while(1);
	return 0;
}

int potencia(int base, int exponente){
	if (exponente == 0){
		return 1;
	}else{
		return base * potencia(base, exponente-1);
	}
}