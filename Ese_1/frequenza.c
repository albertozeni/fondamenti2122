#include <stdio.h>

#define N_MAX 100

int main(){

	int A[N_MAX], frequenza[10], N = 0, i = 0;
	int max_freq = 0;
	printf("Inserisci il numero di elementi dell'array\n");
	while(N<1 || N>100){
		scanf("%d", &N);
	}
	for(i=0; i<N; i++){
		printf("Inserisci l'elemento in posizione %d\n",i);
		scanf("%d", &A[i]);
		
		while(A[i]<0 || A[i]>9){
			printf("Inserisci l'elemento in posizione %d\n",i);
                	scanf("%d", &A[i]);
		}
	}

	for(i = 0; i<10;i++){
		frequenza[i]=0;		
	}	
	for(i=0; i <N;i++){
		frequenza[A[i]]++; 
	}


	for(i=0; i<10;i++){
		if(max_freq<frequenza[i]){
			max_freq = frequenza[i];
		}
	}
	for(i=0; i<10;i++){
		if(frequenza[i]==max_freq){
			printf("%d ",i);
		}
	}
	printf("\n");

	return 0;
}
