///////////////////////////////////////////////////////
//PROGRAMA QUE IMPLEMENTA UMA ARVORE DE ORDEM SIMPLES//
///////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct no{
	int n;
	struct no *filho1;
	struct no *filho2;
	struct no *filho3;
	struct no *filho4;
	struct no *filho5;
};

//FUNC QUE INSERE NO NA ARVORE//

struct no *inserir(struct no *raiz, int n){
	if (raiz == NULL) {

		//Caso facil, arvore vazia inserir novo no na raiz
		raiz = (struct no *) malloc(sizeof(struct no));
		raiz -> n = n;
		raiz -> filho1 = NULL;
		raiz -> filho2 = NULL;
		raiz -> filho3 = NULL;
		raiz -> filho4 = NULL;
		raiz -> filho5 = NULL;
	} else {
		//Caso dificil, arvore NAO vazia, sortear filho
		
		int sorteioFilho = (rand() % 5); 
		
		switch (sorteioFilho){
			case 0:
				raiz -> filho1 = inserir(raiz -> filho1, n);
				break;
			case 1:
				raiz -> filho2 = inserir(raiz -> filho2, n);
				break;
			case 2:
				raiz -> filho3 = inserir(raiz -> filho3, n);
				break;
			case 3:
				raiz -> filho4 = inserir(raiz -> filho4, n);
				break;
			case 4:
				raiz -> filho5 = inserir(raiz -> filho5, n);
				break;
			
		}
	}
	return raiz;
	
}

//FUNC QUE IMPRIME A ARVORE//

void imprimir(struct no *raiz, char *indentacao, char *filho){
	
	if (raiz != NULL){
		//IMPRIMIR O N DA RAIZ
		printf("%s(%s)%d\n", indentacao,filho, raiz -> n);
		
		//AJUSTAR A INDENTACAO
		char * novaIndentacao = (char *) malloc(sizeof(1048576));
		strcpy (novaIndentacao, "---");
		strcat (novaIndentacao, indentacao);
		
		//IMPRIMIR OS FILHOS
		imprimir(raiz -> filho1, novaIndentacao, "f1");
		imprimir(raiz -> filho2, novaIndentacao, "f2");
		imprimir(raiz -> filho3, novaIndentacao, "f3");
		imprimir(raiz -> filho4, novaIndentacao, "f4");
		imprimir(raiz -> filho5, novaIndentacao, "f5");
	}
}

int main(){

	//Declaracao de variaveis
	struct no *raiz = NULL;
	int i = 0;
	
	//inicializacao aleatoria
	time_t t;
	srand(time(&t));
	
	
	//impressao da nos
	for( i = 0; i < 10; i++){
		raiz = inserir(raiz, i);
	}
	
	//impressao da arvore
	imprimir(raiz,"", "raiz");
}

