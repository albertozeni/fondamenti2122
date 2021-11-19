#include <stdio.h>

#define N 100

int main(){

	int a[N], b[N], i = 0, n_val;

	printf("Inserisci un numero maggiore di zero\n");
	scanf("%d", &a[0]);
	for (i = 1; i < N && a[i-1] > 0; i++){
		printf("Inserisci un numero\n");
		scanf("%d", &a[i]);
	}
	n_val = i - 1;

	for(i=0; i<n_val;i++){
		b[i] = a[i];
	}

	for(i=n_val-1; i >= 0; i--){
		a[n_val-i-1] = b[i];
	}

	for(i = 0; i < n_val; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
