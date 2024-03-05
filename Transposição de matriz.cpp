//transposição de matriz//

#include <stdio.h>

//declar de var//

int matriz[2][3];
int transposta[3][2];

int i;
int y;

int main (){
	for (i=0;i<2;i++){
		for(y=0;y<3;y++){
			printf("matriz[%d, %d]= ", i,y);
			scanf("%d",&matriz[i][y]);
		}
	}
	
	for (i=0;i<2;i++){
		for(y=0;y<3;y++){
			transposta[y][i] = matriz[i][y];
		}
	}
	
	for (i=0;i<3;i++){
		for(y=0;y<2;y++){
			printf("%d\t", transposta[i][y]);
		}
		printf("\n");
	}
}

