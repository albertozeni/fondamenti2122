#include <stdio.h>
#include <string.h>

typedef char stringa[30];

typedef struct
{
	stringa colore;
	stringa modello;
	char targa[8];
	float prezzo;
} macchina;

void inserisciStringa(char s[]);

int main(){

	int i, num_macchine;
	int trovato = 0;
	char targa_da_cercare[8];

	macchina garage[100];

	printf("Quante macchine vuoi inserire?\n");
	scanf("%d", &num_macchine);

	for(i=0; i < num_macchine; i++){
		printf("Inserisci modello\n");
		inserisciStringa(garage[i].modello);
		printf("Inserisci colore\n");
                inserisciStringa(garage[i].colore);
		printf("Inserisci targa\n");
                inserisciStringa(garage[i].targa);
		printf("Inserisci prezzo\n");
                scanf("%f", &garage[i].prezzo);
	}

	printf("Inserisci la targa da cercare\n");
	inserisciStringa(targa_da_cercare);

	for(i = 0; i < num_macchine && trovato==0; i++){
		if(strcmp(garage[i].targa,targa_da_cercare)==0)
			trovato=1;
	}

	if(trovato==1){
		printf("Modello: %s\n", garage[i-1].modello);
		printf("Colore: %s\n", garage[i-1].colore);
		printf("Targa: %s\n", garage[i-1].targa);
		printf("Prezzo: %f\n", garage[i-1].prezzo);
	}else{
		printf("La macchina non e' nel garage");
	}

	return 0;

}

void inserisciStringa(char s[]){
	scanf("%s", s);
}
