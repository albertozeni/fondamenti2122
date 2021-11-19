#include <stdio.h>

#define N 5

int main(){

	int A[N], B[N], C[N*2];

	float media_a = 0, media_b = 0; 
	int i = 0;
	int max_a, max_b, min_a, min_b;
	
	int prod = 0; 
	
	printf("Inserisci i valori dell'array A\n");
	for(i=0; i<N; i++){
		printf("Inserisci il valore in posizione %d di %d di A\n",i,N);
		scanf("%d", &A[i]);
	}

	printf("Inserisci i valori dell'array B\n");
        for(i=0; i<N; i++){
                printf("Inserisci il valore in posizione %d di %d di B\n",i,N);
                scanf("%d", &B[i]);
        }

	for(i = 0; i < N; i++){
		media_a += A[i];
		media_b += B[i];
	}

	media_a /= N;
	media_b /= N;

	if(media_a > media_b){
		printf("A ha una media piu' alta\n");
	}else{
		printf("B ha una media piu' alta\n");
	}

	for(i=0;i<N;i++){
		C[i]=A[i];
		C[i+N]=B[i];
	}

	for(i=0;i<2*N;i++){
		printf("%d ", C[i]);
	}
	printf("\n");

	max_a = min_a = A[0];

	max_b = min_b = B[0];

	for(i = 1; i < N; i++){
		if(max_a < A[i]){
			max_a = A[i];
		}
		if(min_a > A[i]){
			min_a = A[i];
		}
		if(max_b < B[i]){
                        max_b = B[i];
                }
                if(min_b > B[i]){
                        min_b = B[i];
                }
	}

	if(max_a > max_b){
		printf("Il max e' in A e vale %d\n", max_a);
	}else{
		printf("Il max e' in B e vale %d\n", max_b);
	}

	if(min_a < min_b){
                printf("Il min e' in A e vale %d\n", min_a);
        }else{
                printf("Il min e' in B e vale %d\n", min_b);
        }

	for(i=0; i<N; i++){
		prod += A[i]*B[i];
	}

	printf("Il prodotto vale %d\n", prod);

	return 0;
}
