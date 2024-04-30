//ARVORE DE BUSCA//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//DECLARACAO DA ESTRUTURA DO NO DA ARVORE//

struct no{
	int n;
	struct no *esquerda;
	struct no *direita;
};

//FUNCAO QUE BUSCA UM N NA ARVORE//

void buscar(struct no *raiz, int n){
	//ARVORE ESTA VAZIA
	if (raiz == NULL){
		printf("Nao achei...\n");
		return;
	}
	//Cenario de sorte do NUMERO estar na raiz
	if (raiz -> n == n){
		printf("ACHEI!\n");
		return;
	}
	
	//Cenario de bosta
	if (raiz -> n > n){
		buscar(raiz->esquerda, n);
	} else {
		buscar(raiz -> direita, n);
	}
}

//FUNC QUE INSERE UM NO NA ARVORE//
struct no *inserir(struct no *raiz,int n){
	//CASO FACIL: VAZIA
	if(raiz == NULL){
		raiz = (struct no *)malloc(sizeof(struct no));
		raiz -> n = n;
		raiz -> esquerda = NULL;
		raiz -> direita = NULL;
		return raiz;
	}
	
	//CASO DIFICIL: NAO VAZIA
	if(raiz -> n > n){
		raiz -> esquerda = inserir(raiz -> esquerda,n);
	} else {
		raiz -> direita = inserir(raiz -> direita, n);
	}
	
	return raiz;
}

//FUNC QUE REALIZA A NAVEG EM-ORDEM DA ARVORE//

void navegarEmOrdem(struct no *raiz){
	if (raiz == NULL){
		return;
	}
	
	navegarEmOrdem(raiz -> esquerda);
	printf("%d, ", raiz -> n);
	navegarEmOrdem(raiz -> direita);
}

//FUNC DE EXE DE PROGRAM

int main (){
	//DECLAR VAR
	struct no *raiz = NULL;
	int i = 	0;
	
	//ALEATORIEDADE
	time_t t;
	srand(time(&t));
	
	//INSERCAODE VARIOS NOS
	for( i=0; i<100; i++){
		int n = (rand()% 100);
		printf("%d\n", n);
		raiz = inserir(raiz, n);
	}
	
	//NAVE
	navegarEmOrdem(raiz);
	
	//BUSCA
	int busca = 0;
	while(busca != -1){
		printf("Digite um n a ser buscado: ");
		scanf("%d", &busca);
		
		buscar(raiz,busca);
	}
	
}

