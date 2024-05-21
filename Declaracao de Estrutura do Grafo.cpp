//Programa que implementa um grafo//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//DELARACAO DE QUANTIDADE DE VERTICES DO GRAFO//

#define VERTICES 500

//FUNÇÃO QUE CRIA O GRAFO//

void criar(int grafo[VERTICES][VERTICES]){
	int i = 0;
	int j = 0;
	int adjacencia = 0;
	
	for (i = 0; i < VERTICES; i++){
		for (j = 0; j < VERTICES; j++){
			grafo[i][j] = 0;
		}
	}
	
	//Definicao dos adjacentes
	for (i = 0; i < (VERTICES - 1); i++){ // DO PRIMEIRO AO PENULTIMO
		for (j = (i + 1); j < VERTICES; j++) { // PROXIMO AO ULTIMO
			//printf("Digite <1> se %d for adjacente a %d: ", i,j);
			
			//scanf("%d", &adjacencia);
			
			adjacencia = (rand() % 2);
			grafo[i][j] = adjacencia;
			grafo[j][i] = adjacencia;
			
		}
	}
}

//FUNCAO QUE IMPRIME O GRAFO//

void imprimir(int grafo[VERTICES][VERTICES]){
	int i = 0;
	int j = 0;
	
	printf("V: Adjacencias \n");
	
	for (i = 0; i < VERTICES; i++){
		printf("%d: ", i);
		for (j = 0; j < VERTICES; j++){
			if (grafo[i][j]){
				printf("%d", j);
			}
		}
		printf("\n");
	}
	printf("\n");
}

//FUNCAO QUE DESCOBRE AH VERTICE DE MAIOR GRAU//

int descobrirMaiorGrau(int grafo[VERTICES][VERTICES]){
	int i = 0;
	int j = 0;
	int grau = 0;
	int maiorGrau = 0;
	int vertice = 0;
	
	for (i = 0; i < VERTICES; i++){
		grau = 0;
		for (j = 0; j < VERTICES; j++){
			if (grafo [i][j]){
				grau++;
			}
		}
		if (grau > maiorGrau){
			maiorGrau = grau;
			vertice = i;
		}
	}
	return vertice;	
}
					
int main(){
	
	int grafo[VERTICES][VERTICES];
	
	time_t t;
	srand(time(&t));
	
	criar(grafo);
	imprimir(grafo);
	
	printf("VERTICE DE MAIOR GRAU: %d\n", descobrirMaiorGrau(grafo));
}
