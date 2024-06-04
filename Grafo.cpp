//PROGRAMA QUE IMPLEMENTA ORDEM TOPOLOGICA//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTDVERTICES 715

void criar(int grafo[QTDVERTICES][QTDVERTICES], int sorteio){
	
	//DECLARA��O DE VARIAVEIS
	int i = 0;
	int j = 0;
	
	//INICIALIZA��O DE ESTRUTURA
	for (i = 0; i < QTDVERTICES; i++){
		for (j = 0; j < QTDVERTICES; j++){
			grafo[i][j] = 0;
		}
	}
	
	//CRIA��O PROPRIAMENTE DITA
	for (i = 0; i < QTDVERTICES; i++){
		for (j = 0; j < QTDVERTICES; j++){
			if (sorteio){
				grafo[i][j] = (((rand() % 5)< 0) ? 1:0);
			} else {
				printf("Digite <l> para arco entre %d e %d: ", i,j);
				scanf("%d", &grafo[i][j] );
			}
		}
	}
}

//FUNC QUE ORDENA TOPOLOGICAMENTE UM GRAFO//

void ordenarTopologicoRecursivo(int grafo[QTDVERTICES][QTDVERTICES], int visitado[QTDVERTICES],int vertice){
	int i;
	
	visitado[vertice] = 1;
	
	for (i = 0; i < QTDVERTICES; i++){
		if (grafo[vertice][i]) {
			if(! visitado[i]) {
				ordenarTopologicoRecursivo(grafo, visitado, i);
			}
		}
	}
	printf("%d\t", vertice);
}

void ordenarTopologico(int grafo[QTDVERTICES][QTDVERTICES]) {
	int vertice;
	int visitado[QTDVERTICES];
	
	for (vertice = 0; vertice < QTDVERTICES; vertice++){
		visitado[vertice] = 0;
	}
	for (vertice = 0; vertice <QTDVERTICES; vertice++){
		if(! visitado[vertice]) {
			ordenarTopologicoRecursivo(grafo, visitado, vertice);
		}
	}
	printf("\n");
}

//FUNC PRINCIPAL DE EXE DO PROGRAM//

int main(){
	
	//Declara��o de var
	int grafo[QTDVERTICES][QTDVERTICES];
	
	//Inicializa��o de aleatoriedade
	time_t t;
	srand(time(&t));
	
	
	//cria��o de grafo
	criar(grafo, 1);
	
	ordenarTopologico(grafo);
}
