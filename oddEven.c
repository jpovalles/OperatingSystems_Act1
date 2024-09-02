#include <stdio.h>
#include <stdlib.h>

int main(){
	int num;
	while(1){
		printf("Ingresa el numero entero: ");
		scanf("%d", &num);
		if(num%2==0){
			printf("%d es par!!!!\n\n", num);
		}else{
			printf("%d es impar!!!!\n\n", num);
		}
		
		if(recursive(num)){
			printf("%d es par!!!! (RECURSIVO)\n\n", num);
		}else{
			printf("%d es impar!!!! (RECURSIVO)\n\n", num);
		}
	}
	return 0;
}


int recursive(int num){
	if(num==1){
		return 0;
	}else if(num==0){
		return 1;
	}else{
		return recursive(num-2);
	}
}