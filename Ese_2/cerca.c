#include <stdio.h>

int *cerca(int a[], int dacercare, int dim);
int cercatutti(int a[], int dacercare, int dim, int *pos);

int main(){

	int elem[5]={3,5,41,5,0};
	int posiz[5];
	int dacercare1 = 5;
	int dacercare2 = 0;
	int n_trovati;
	int *trovato1, *trovato2;
	int i;
	trovato1 = cerca(elem,dacercare1,5);
	trovato2 = cerca(elem,dacercare2,5);
	n_trovati = cercatutti(elem, dacercare1, 5, posiz);

	if(trovato1==NULL){
		printf("Il valore %d non e' stato trovato\n", dacercare1);
	}else{
		printf("Il valore %d e' stato trovato, in posizione %d\n", dacercare1, trovato1-elem);
	}

	
	if(n_trovati>0){
		for(i=0; i<n_trovati; i++){
			printf("%d ", posiz[i]);
		}
	}
	printf("\n");

	if(trovato2==NULL){
                printf("Il valore %d non e' stato trovato\n", dacercare2);
        }else{
                printf("Il valore %d e' stato trovato, in posizione %d\n", dacercare2, trovato2-elem);
        }

}

int *cerca(int a[], int dacercare, int dim){


	int i;
	for(i=0; i<dim; i++){
		if(a[i]==dacercare)
			return a+i;
	}
	return NULL;

}
int cercatutti(int a[], int dacercare, int dim, int *pos){

	int i;
	int n=0;
	for(i=0; i<dim;i++){
		if(a[i]==dacercare){
			pos[n]=i;
			n++;
		}
	}
	return n;
}
