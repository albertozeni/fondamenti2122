#include <stdio.h>
#include <stdlib.h>

int valori(int *ar, int dim);

int main(){

	int dim_ar;
	int i;
	printf("Quanto e' grande l'array?\n");
	scanf("%d", &dim_ar);
	int *array = (int *)malloc(sizeof(int)*dim_ar);
	for(i=0; i < dim_ar; i++){
		scanf("%d", &array[i]);
	}
	printf("Valori: %d\n", valori(array,dim_ar));
}

int valori(int *ar, int dim){

	int i, min, max;
	max=min=ar[0];
	for(i=0; i<dim; i++){
		if(ar[i]>max)
			max=ar[i];
		if(ar[i]<min)
			min=ar[i];
	}
	return min+max;
}
