#include <stdio.h>
#include <stdlib.h>

int main(){
	int pos;
	while(1){
		printf("Ingrese el numero a consultar: ");
		scanf("%d", &pos);
		int ans;
		for(int i=0; i<=pos; i++){
			ans = fibonacci(i);
			printf("%d ", ans);n
		}
		printf("\n");
	}
	return 0;
}

int fibonacci(int num){
	if(num==1 || num==0){
		return num;
	}else{
		return fibonacci(num-1)+fibonacci(num-2);
	}
}