////////////////////////////////////////////////////
/////Programa que Implementa a Ordena��o Direta/////
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
	
	//// Ordena��o propriamente dita////
	
	for (i=0; i<9; i++){ //Do primeiro ao pen�ltimo
		for (j=(i+1); j<10; j++){ //Do pr�ximo ao  �ltimo
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
