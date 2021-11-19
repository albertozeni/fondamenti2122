#include <stdio.h>

void risolvi(int n_dischi, char partenza, char arrivo, char temporaneo);

int main(){

	int num_dischi;
	printf("Inserisci il numero di dischi da usare\n");
	scanf("%d", &num_dischi);
	risolvi(num_dischi, 'A', 'C', 'B');
	return 0;
}

void risolvi(int n_dischi, char partenza, char arrivo, char temporaneo){

	if(n_dischi==1){
		printf("Sposto il disco %d da %c a %c\n", n_dischi, 
		partenza, arrivo);
	}
	else{
		risolvi(n_dischi-1, partenza, temporaneo, arrivo);
		printf("Sposto il disco %d da %c a %c\n", n_dischi,
                partenza, arrivo);
		risolvi(n_dischi-1, temporaneo, arrivo, partenza);
	}

}
