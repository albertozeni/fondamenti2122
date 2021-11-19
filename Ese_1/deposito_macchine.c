#include <stdio.h>
#include <string.h>

typedef char stringa[50];

typedef struct{

	stringa colore;
	stringa modello;
	float   prezzo;
	char    targa[8];

} automobile;

void inserisciStringa(char s[]);

int main(){

	int num_macchine, i;
	int trovata = 0;

	char targa_da_cercare[8];

	automobile macchine[100];

	printf("Inserisci il num di macchine da inserire\n");
	scanf("%d", &num_macchine);

	for(i=0; i< num_macchine;i++){
		printf("Inserisci modello\n");
		inserisciStringa(macchine[i].modello);
		printf("Inserisci colore\n");
		inserisciStringa(macchine[i].colore);
		printf("Inserisci targa\n");
		inserisciStringa(macchine[i].targa);
		printf("Inserisci prezzo\n");
		scanf("%f", &macchine[i].prezzo);
	}

	printf("Inserisci una targa da cercare\n");
	inserisciStringa(targa_da_cercare);

	for(i=0; i<num_macchine && trovata == 0; i++){
		if(strcmp(macchine[i].targa,targa_da_cercare)==0)
			trovata = 1;
	}
	if(trovata == 1){
		printf("Colore: %s\n", macchine[i-1].colore);
		printf("Modello: %s\n", macchine[i-1].modello);
		printf("Targa: %s\n", macchine[i-1].targa);
		printf("Prezzo: %f\n", macchine[i-1].prezzo);
	}else{
		printf("Macchina non trovata\n");
	}

	return 0;
}

void inserisciStringa(char s[]){
	scanf("%s", s);
}
