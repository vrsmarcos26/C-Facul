#include <stdio.h>
#include<stdlib.h>

//Programa de teste de ponteiro//

/////////////////////////////////
////////Função principal/////////
/////////////////////////////////

int main(){
	int*ponteiro;
	ponteiro = (int*)malloc(sizeof(int));
	//malloc = memory allocation :)
	*ponteiro = 1;
	printf("%d", &ponteiro);
	printf("\n");
	printf("%d", *ponteiro);
	
}

