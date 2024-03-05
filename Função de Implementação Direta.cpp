////////////////////////////////////////////////////
/////Programa que Implementa a Ordenação Direta/////
////////////////////////////////////////////////////

#include <stdio.h>

////////Declar de var//////////

int vetor[10];
int i;
int j;

//////Func principal de exe//////

int main(){
	//// preenchimento do vetor 
	for (i=0; i<10; i++) {
		printf("Digite o valor da posicao %d: ", i);
		scanf("%d", &vetor[i]);
	}
	
	//// Ordenação propriamente dita////
	
	for (i=0; i<9; i++){ //Do primeiro ao penúltimo
		for (j=(i+1); j<10; j++){ //Do próximo ao  último
			if (vetor[i] > vetor[j]) {
				int temp = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = temp;
			}
		}
	}
	///impress do vetor ordenado///

	for (i=0;i<10;i++){
		printf("%d\t", vetor[i]);
	}

}
