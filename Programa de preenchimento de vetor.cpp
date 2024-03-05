///////////////////////////////////////////////
//Programa de preenchimento de vetor///////////
///////////////////////////////////////////////

#include <stdio.h>

///////////////////////////
//declaração de variaveis//
///////////////////////////

int vetor [10];
int i;

/////////////////////////////////////
//fuc principal de exec do programa//
/////////////////////////////////////

int main() {
	//mandar o usr preencher o vetor//
	for (i = 0 ; i < 10 ; i++){
		printf("Digite o valor da posicao %d do vetor", i);
		scanf("%d", &vetor[i]);
	}
	//imprimir o vetor na tela
	
	for (i = 0 ; i < 10 ; i++){
		printf("vetor[%d] = %d\n", i, vetor[i]);
	}
}
