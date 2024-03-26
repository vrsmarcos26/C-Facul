/////////////////////////////////////
//PROGRAMA QUE IMPLEMENTA UMA PILHA//
/////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

struct no{
	int n;
	struct no *proximo;
};

struct no *push(struct no *cabeca, int n){
	//Criacao do novo no
	
	struct no *novoNo = (struct no *) malloc (sizeof(struct no));
	novoNo -> n = n;
	
	//Posicionamento do novoNo na pilha
	
	novoNo -> proximo = cabeca;
	cabeca = novoNo;

	return cabeca;
}

////////////////////////////////////
//FUNCAO QUE REMOVE UM NO DA PILHA//
////////////////////////////////////


struct no *pop(struct no *cabeca){
	//CASO LISTA VAZIA
	
	if (cabeca == NULL){
		printf("-99\n");
		return cabeca;
	}
	
	//CASO A PILHA NAO ESTA VAZIA
	
	printf("%d\n", cabeca -> n);
	struct no *ponteiro= cabeca;
	cabeca = cabeca -> proximo;
	free(ponteiro);
	return cabeca;
}

//FUNCAO PRINCIPAL DE EXE DO PROGRAM//

int main (){
	struct no *cabeca = NULL;
	int i =0;
	
	cabeca = pop(cabeca);	
	cabeca = push(cabeca, 1);
	cabeca = pop(cabeca);
	
	
	for (i = 0; i < 100 ;i++){
		cabeca = push(cabeca,i);
	}
	for (i = 0; i < 100; i++){
		cabeca = pop(cabeca);
	}
	cabeca = pop(cabeca);
}
