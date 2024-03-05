////////////////////////////////////////////////////
/////Programa que Implementa Bubble Sort/////
////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
////////Declar de var//////////

int vet[1000];
int i;
int j;
int troquei;

////////////////////////////////////////////////////
//Func principal de execução do programa////////////
////////////////////////////////////////////////////

int main (){
	//iniciar aleatoriedade//
	time_t t;
	srand (time(&t));
	
	//preenchimento do vetor//
	
	for (i=0; i<1000; i++){
		vet[i] = (rand() % 1000);
	}
	
	//impressão de vetor
	
	for (i=0; i<1000; i++){
		printf("%d\t", vet[i]);
	}
	
	//Ordenação propriamente dita
	troquei = 1;
	while(troquei){
		troquei = 0;
		for (i=0; i<1000;i++){
			if (vet[i] > vet[i+1]) {
				int temp = vet[i];
				vet[i] = vet[i+1];
				vet[i+1] = temp;
				
				troquei =1;
			}
		}
	}
	
	//impressão de vetor
	printf("\n=======================================================================================================================================\n");
	for (i=0; i<1000; i++){
		printf("%d\t", vet[i]);
	}
}


