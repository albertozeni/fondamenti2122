#include <stdio.h>

#define N 5

int main(){

	int a[N], b[N], c[N*2];

	int i;

	printf("Inserisci i valori di A\n");
	for(i = 0; i < N; i++){
		printf("Inserisci l'elemento in posizione %d a A\n", i);
		scanf("%d", &a[i]);
	}

	printf("Inserisci i valori di B\n");
        for(i = 0; i < N; i++){
                printf("Inserisci l'elemento in posizione %d a B\n", i);
                scanf("%d", &b[i]);
        }

	float media_a = 0, media_b = 0;

	for(i = 0; i < N; i++){
		media_a += a[i];
		media_b += b[i];
	}
	media_a /= N;
	media_b /= N;

	if(media_a > media_b){
		printf("L'array A ha una media piu' alta\n");
	}else{
		printf("L'array B ha una media piu' alta\n");
	}

	for(i = 0; i < N; i++){
		c[i] = a[i];
		c[i+N] = b[i];
	}
	printf("Stampa dell'array concatenato: \n");
	for(i = 0; i < 2*N; i++){
		printf("%d ", c[i]);
	}
	printf("\n");

	int max_a = a[0], min_a = a[0];
	int max_b = b[0], min_b = b[0];
	for(i = 1; i < N;i++){
		if(max_a < a[i]){
			max_a = a[i];
		}
		if(min_a > a[i]){
			min_a = a[i];
		}
		if(max_b < b[i]){
			max_b = b[i];
		}
		if(min_b > b[i]){
			min_b = b[i];                                                                                                         
		}
	}
	if(max_a > max_b){
		printf("Il massimo e' in A, e vale %d\n", max_a);
	}else{
		printf("Il massimo e' in B, e vale %d\n", max_b);
	}	
	if(min_a < min_b){
		printf("Il minimo e' in A, e vale %d\n", min_a);
	}else{
		printf("Il minimo e' in B, e vale %d\n", min_b);	
	}
	int prod=0;
	for(i = 0; i < N; i++){
		prod += a[i]*b[i];
	}
	printf("Il prodotto vale %d\n", prod);
	return 0;
}
