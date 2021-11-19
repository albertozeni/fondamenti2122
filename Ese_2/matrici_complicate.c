#include <stdio.h>

#define MAX 9


int main(){


	float A[MAX][MAX], B[MAX][MAX];


	int righe_a, colonne_a, righe_b, colonne_b, i, j;

	int select_righe_a[MAX], select_col_a[MAX];

	printf("Inserisci numero righe A\n");
	scanf("%d", &righe_a);
	printf("Inserisci numero colonne A\n");
	scanf("%d", &colonne_a);

	for(i=0; i<righe_a;i++){
		for(j=0; j<colonne_a;j++){
			scanf("%f", &A[i][j]);
		}
	}

	printf("Quante righe di A vuoi selezionare?\n");
	scanf("%d", &righe_b);
	printf("Quante colonne di A vuoi selezionare?\n");
        scanf("%d", &colonne_b);

	printf("Quali righe di A vuoi selezionare?\n");
	for(i=0; i<righe_b; i++){
		scanf("%d", &select_righe_a[i]);
	}
	printf("Quali colonne di A vuoi selezionare?\n");
        for(i=0; i<colonne_b; i++){
                scanf("%d", &select_col_a[i]);
        }

	for(i=0; i<righe_b; i++){
		for(j=0; j<colonne_b;j++){
			B[i][j] = A[select_righe_a[i]][select_col_a[j]];
		}
	}

	printf("Matrice B:\n");
	for(i=0; i<righe_b; i++){
                for(j=0; j<colonne_b;j++){
                        printf("%f ", B[i][j]);
                }
		printf("\n");
        }





}
