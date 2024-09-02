#include <stdio.h>
#include <stdlib.h>

int main(){
	char string[100];
	 int i, ascii, cont = 0;
	
	while(1){
		printf("Ingresa la cadena: ");
		fgets(string, sizeof(string), stdin);
		string[strcspn(string, "\n")] = 0;
		i = 0;
		while(string[i]!='\0') {
			ascii = string[i];
			if(ascii>64 && ascii<91){
				cont = cont + 1;
			}
	    	i++;
		}
		printf("Hay %d letras mayusculas en tu cadena\n\n", cont);
	}
	
	return 0;
}