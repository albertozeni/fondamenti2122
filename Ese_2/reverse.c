#include <stdio.h>

#define N 100

int main(){

	int a[N], b[N], i=0;
	int n_el;
	printf("Inserisci un elemento\n");
	scanf("%d", &a[0]);
	for(i=1; i<N && a[i-1]>0; i++){
		printf("Inserisci un elemento\n");
        	scanf("%d", &a[i]);
	}
	n_el = i - 1;


	for(i=0; i<n_el;i++){
		b[i]=a[i];
	}
	for(i=0; i<n_el;i++){
		a[i]=b[n_el-1-i];
	}
	for(i=0;i<n_el;i++){	
		printf("%d ", a[i]);
	}
	printf("\n");
}
