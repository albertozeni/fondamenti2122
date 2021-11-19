#include <stdio.h>

#define MAX 10


int main(){

	float mat[MAX][MAX], diag=0, sopra_d=0, sotto_d=0;

	int i,j,r,c;


	printf("Inserisci il numero di righe\n");
	scanf("%d", &r);
	printf("Inserisci il numero di colonne\n");
	scanf("%d", &c);

	for(i=0;i<r;i++){
		for(j=0; j<c; j++){
			scanf("%f", &mat[i][j]);
		}
	}

	for(i=0;i<r;i++){
		for(j=0;j<c;j++){

			if(i==j)
				diag+=mat[i][j];
			if(i<j)
				sopra_d += mat[i][j];
			if(i>j)
				sotto_d += mat[i][j];
		}
	}

	printf("Somma diag: %f\nSomma sopra %f\nSomma sotto %f\n", diag, sopra_d, sotto_d);

	return 0;

}
