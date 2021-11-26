#include <stdio.h>
#include <stdlib.h>

int valori(int ar[], int dim);

int main(){

	int *arr;
	int i, dim;
	printf("Inserisci la dimensione:\n");
	scanf("%d", &dim);
	arr = malloc(dim*sizeof(int));
	for(i=0; i<dim; i++){
		scanf("%d", &arr[i]);
	}
	printf("Valori: %d\n", valori(arr, dim));
}

int valori(int ar[], int dim) {

	int max, min, i;
	max=min=ar[0];
	for(i=1;i<dim;i++){
		if(ar[i]>max)
			max=ar[i];
		if(ar[i]<min)
			min=ar[i];
	}
	return min+max;
}
