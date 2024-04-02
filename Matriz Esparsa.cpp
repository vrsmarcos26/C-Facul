/* Programa que implementa uma Matriz Esparsa */

#include <stdio.h>
#include <stdlib.h>

//Declaracao de costantes//

const int modulo = 3;

//Declaracao do no//

struct no{
	int n;
	struct no *proximo;
};

//Declaracao do no diretor//

struct dir{
	int resto;
	struct no *proximoNo;
	struct dir *proximoDir;
};

// funcao que procura por um no dir//

struct dir *procurarDir(struct dir *cabeca, int resto){
	//Declaracao de variaveis
	struct dir *ponteiro = cabeca;
	
	//Procura do diretor cujo resto seja igual ao parametro
	while(ponteiro != NULL){
		if(ponteiro -> resto == resto){
			break;
		}
		ponteiro = ponteiro -> proximoDir;
	}
	
	return ponteiro;
	
}

//Func que inserir um no na matriz

struct dir *inserir(struct dir *cabeca, int n){
	
	//Declaracao do ponteiro para o diretor corretor
	struct dir *ponteiroDir = procurarDir(cabeca,n % modulo);
	
	if (ponteiroDir == NULL){
		ponteiroDir = (struct dir *)malloc(sizeof(struct dir));
		ponteiroDir -> resto = (n % modulo);
		ponteiroDir -> proximoNo = NULL;
		ponteiroDir -> proximoDir = cabeca;
		cabeca = ponteiroDir;
	}
	
	//Criacao de novo no
	struct no *novoNo = (struct no *)malloc(sizeof(struct no));
	novoNo -> n = n;
	novoNo -> proximo = ponteiroDir -> proximoNo;
	ponteiroDir -> proximoNo = novoNo;
	
	return cabeca;
}

//func que imprime a matriz esparsa//

void imprimir (struct dir *cabeca){
	struct dir *ponteiroDir = cabeca;
	
	while (ponteiroDir != NULL){
		struct no *ponteiroNo = ponteiroDir -> proximoNo;
		
		printf("%d:\t", ponteiroDir -> resto);
		
		while (ponteiroNo != NULL){
			printf("%d\t ", ponteiroNo -> n);
		
			ponteiroNo = ponteiroNo -> proximo;
		}
		printf("\n");
		ponteiroDir = ponteiroDir -> proximoDir;
	}
}

void remover(struct dir *cabeca,int n){
	struct dir *ponteiroDir = procurarDir(cabeca,n%modulo);
	
	if (ponteiroDir == NULL){
		return;
	}
	
	struct no *ponteiroNo = ponteiroDir -> proximoNo;
	
	if (ponteiroNo -> n == n){
		ponteiroDir -> proximoNo = ponteiroNo -> proximo;
		free(ponteiroNo);
		return;
	}
	
	while ((ponteiroNo -> proximo != NULL) && (ponteiroNo -> proximo -> n != n)){
		ponteiroNo = ponteiroNo -> proximo;
	}
	
	if (ponteiroNo -> proximo != NULL){
		struct no *temp = ponteiroNo -> proximo;
		ponteiroNo -> proximo = ponteiroNo -> proximo -> proximo;
		free(temp);
	}
}

int main(){
	struct dir *cabeca = NULL;
	
	int i = 0;
	
	for (i=0; i<100; i++){
		cabeca = inserir(cabeca, i);
	}
	
	imprimir(cabeca);
	
	for (i = 0; i<100; i++){
		remover(cabeca,i);
	}
	
	imprimir(cabeca);
}


/* 
Ser abismal, vive no porão
Se chamado o tal, verás o apagão
Quando for dormir, vai te consumir
Não falamos do Bruno, não, não, não
Não falamos do Bruno 

Tú me traes un poco loco, un poquititito loco
Estoy adivinando qué quieres y pa' cuándo
Y así estoy celebrando
Que me he vuelto un poco loco
*/
