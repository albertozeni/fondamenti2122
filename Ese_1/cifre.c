#include<stdio.h>

int cifre(int n);

int main(){
	int n;
	printf("Inserisci un numero intero positivo\n");
	scanf("%d", &n);
	printf("Il numero aveva %d cifre\n", cifre(n));

}

int cifre(int n){
	if(n<10){
		return 1;
	}
	else{
		return 1+cifre(n/10);
	}

}
