////////////////////////////////////
//Programa que implemente uma fila//
////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//Declaração da estrutura do ano//

struct no{
	int n;
	struct no *proximo;
};

///////////////////////////////////
//Função que insere um no na fila//
///////////////////////////////////

struct no *inserir(struct no *cabeca, int n){
	
	//Criacao do novo no
	
	struct no *novoNo = (struct no *) malloc (sizeof(struct no));
	novoNo -> n = n;
	
	//Posicionamento do novoNo na entrada da fila
	
	novoNo -> proximo = cabeca;
	cabeca = novoNo;

	return cabeca;
}

//////////////////////////////////
//Função que remove o no da fila//
//////////////////////////////////

struct no *remover(struct no *cabeca){
	// Caso lista vazia
	
	if (cabeca == NULL){
		printf("-99\n");
		return cabeca;
	}
	
	//Caso da lista ter apenas 1 unico no
	
	if (cabeca -> proximo == NULL){
		printf("%d\n", cabeca -> n);
		free(cabeca);
		cabeca = NULL;
		return cabeca;
	}
	
	
	// Caso da lista ter mais de 1 no
	//Posicionar ponteiro no PENULTIMO no da lista
	struct no *ponteiro = cabeca;
	while(ponteiro -> proximo -> proximo != NULL){
		ponteiro = ponteiro -> proximo;
	}
	
	printf("%d\n", ponteiro -> proximo -> n);
	free(ponteiro -> proximo);
	ponteiro -> proximo = NULL;
	return cabeca;
}

//Func principal de execucao do programa//

int main(){
	//declaração de variaveis
	
	struct no *cabeca = NULL;
	int i = 0;
	
	cabeca = remover (cabeca);	
	cabeca = inserir(cabeca, 1);
	cabeca = remover(cabeca);
	
	
	for (i = 0; i <100 ;i++){
		cabeca = inserir(cabeca,i);
	}
	for (i = 0; i<100; i++){
		cabeca = remover(cabeca);
	}
	cabeca = remover(cabeca);
}
