////Programa que implementação da Busca Exaustiva////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/////////////////////////////////////////////////////
//Func Principal de execução do programa/////////////
/////////////////////////////////////////////////////

int main() {
	// declaração de var
	
	int vetor [100000];
	int i;
	int achei;
	int procura;
	
	//INICIALIZAÇÃO da aleatoriedade//
	
	time_t t;
	srand(time(&t));
	
	// Preenchimento do vetor
	for (i=0; i< 100000; i++){
		vetor[i] = (rand() % 100000);
	}
	
	//Definir o parâmetro de pesquisa
	printf("Digite o valor a ser buscado: ");
	scanf("%d", &procura);
	
	//Busca exaustiva propriamente dita
	achei = -1;
	for (i=0; i<100000; i++){
		if (vetor[i]==procura){
			achei = i;
			break;
		}
	}
	
	//resposta
	if (achei==-1){
		printf("Me fodi ! Nao encontrei !");
	} else {
		printf ("Encontrei na posicao %d\n", achei);
	}
	
}

