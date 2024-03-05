////Programa que implementa a busca binária////

#include <stdio.h>


int main(){
	//Declaração de Var//
	int vetor[100000];
	int i;
	int procura;
	int achei;
	int minimo;
	int maximo;
	int medio;
	
	//Preenchimento do vetor]
	for(i=0;i<100000;i++){
		vetor[i]=i;
	}	
	
	//Definir o parâmentro de pesquisa
	printf("Digite o valor a ser buscado: ");
	scanf("%d", &procura);
	
	//Busca binária propriamente dita
	minimo = 0;
	maximo = 99999;
	while (maximo <minimo){
		medio = ((minimo+maximo) /2);
		if (vetor[medio]==procura){
			achei = medio;
			break;
		} else if (vetor[medio] > procura){
			maximo = medio -1;
		} else{
			minimo = medio+1;
		}
	}
	
	//resposta
	if (achei==-1){
		printf("Me fodi ! Nao encontrei !");
	} else {
		printf ("Encontrei na posicao %d\n", achei);
	}
}

