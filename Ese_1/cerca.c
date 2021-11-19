#include <stdio.h>

int *cerca(int a[], int cerca, int dim);
int cercalitutti(int a[], int cerca, int dim, int pos[]);

int main(){
	int i;
	int elementi[10]={0,1,2,3,4,5,6,3,8,9};
	int dacercare1=3, dacercare2=9;
	int *trovato1, *trovato2;
	int trovatonvolte;
	int posizioni[10];
	trovato1 = cerca(elementi, dacercare1, 10);
	trovato2 = cerca(elementi, dacercare2, 10);

	if(trovato1==NULL){
		printf("%d non trovato\n", dacercare1);
	}else{
		printf("%d trovato in posizione %d\n", dacercare1, trovato1-elementi);
	}

	trovatonvolte = cercalitutti(elementi, dacercare1,10,posizioni);
	if(trovatonvolte > 0){
		for(i = 0; i < trovatonvolte;i++){
			printf("%d ", posizioni[i]);
		}
	}
	printf("\n");
	if(trovato2==NULL){
                printf("%d non trovato\n", dacercare2);
        }else{
                printf("%d trovato in posizione %d\n", dacercare2, trovato2-elementi);
        }

	return 0;
}


int *cerca(int a[], int cerca, int dim){
	int i=0;
	for(i=0; i<dim; i++){
		if(a[i]==cerca)
			return a+i;
	}
	return NULL;
}
int cercalitutti(int a[], int cerca, int dim, int pos[]){
	int i=0;
	int n=0;

	for(i=0; i<dim; i++){
		if(a[i]==cerca){
			pos[n]=i;
			n++;
		}
	}

	return n;
}
