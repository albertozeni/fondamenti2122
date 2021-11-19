#include<stdio.h>

void risolvi(int num_dischi, char partenza, char arrivo, char temporaneo);

int main(){
	int dischi;
	printf("Con quanti dischi vuoi giocare?\n");
	scanf("%d", &dischi);
	risolvi(dischi, 'A', 'C', 'B');
}

void risolvi(int num_dischi, char partenza, char arrivo, char temporaneo){

	if(num_dischi==1){
		printf("Sposto il disco %d da %c a %c\n", num_dischi, partenza, arrivo);
	}else{
		risolvi(num_dischi-1, partenza, temporaneo, arrivo);
		printf("Sposto il disco %d da %c a %c\n", num_dischi, partenza, arrivo);
		risolvi(num_dischi-1, temporaneo, arrivo, partenza);
	}
}
