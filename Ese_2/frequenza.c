#include <stdio.h>

#define N_MAX 100
#define NUM_MAX 10

int main(){

	int a[N_MAX], freq[NUM_MAX], i = 0;
	int N = 0;
	int frq_max = 0;
	do{
		printf("Inserisci un numero da 1 a 100\n");
		scanf("%d", &N);
	}while(N<1||N>100);

	for(i=0; i < N; i++){
		do{
			printf("Inserisci un valore da 0 a 9\n");
			scanf("%d", &a[i]);
		}while(a[i]<0||a[i]>9);
	}

	for(i = 0; i < NUM_MAX; i++){
		freq[i]=0;
	}

	for(i = 0; i < N; i++){
		freq[a[i]]++;
	} 

	for(i=0; i<NUM_MAX;i++){
		if(frq_max < freq[i]){
			frq_max = freq[i];
		}
	}
	for(i=0; i<NUM_MAX;i++){
		if(frq_max == freq[i]){
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;

}
