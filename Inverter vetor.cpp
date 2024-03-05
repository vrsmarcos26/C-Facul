//Inversão vetor//

#include <stdio.h>

//criação 
int vetor[5];
int i;
int vetorinv[5];

int main(){

	//Preenchendo
	for (i=0;i<5;i++) {
		printf("Digite o valor da posicao %d do vetor", i);
		scanf("%d", &vetor[i]);
	}
	
	//Invertendo vetor
	for (i=0; i<5; i++) {
		vetorinv[4-i] = vetor[i];
	}
	
	//imprimindo
	
	for (i=0;i<5;i++) {
		printf("vetor[%d] = %d\n", i, vetor[i]);
	}
	
	for (i=0;i<5;i++){
		printf("vetorinv[%d] = %d\n", i,vetorinv[i]);
	}
	
}
