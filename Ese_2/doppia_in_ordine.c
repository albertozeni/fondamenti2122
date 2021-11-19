#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodo{
	int dato;
	struct nodo *suc;
	struct nodo *prec;
};

typedef struct nodo elem;
typedef elem *lista;

lista inserisci_in_ordine(lista l, int dato);
void stampa(lista l);

int main(){

	lista l = NULL;
	int i;

	srand(time(NULL));
	
	for(i=0; i<7; i++){
		int temp = rand()%100;
		if(i<5){
			printf("Inserisco %d\n",temp);
			l = inserisci_in_ordine(l,temp);
		}else{
			printf("Inserisco 38\n");
			l = inserisci_in_ordine(l,38);
		}
	}
	stampa(l);
	return 0;
}

lista inserisci_in_ordine(lista l, int dato){

	elem *ins, *cur, *pre;
	//lista ins, cur, pre;
	pre = NULL;
	cur = l;
	while(cur!=NULL&&cur->dato < dato){
		pre = cur;
		cur = cur->suc;
	}

	if(cur==NULL||dato!=cur->dato){//entro per inserire un nuovo nodo
		ins = malloc(sizeof(elem));
		ins->dato = dato;
		ins->prec = pre;
		ins->suc = cur;
		if(cur!=NULL)
			cur->prec = ins;
		if(pre!=NULL)
			pre->suc = ins;
		else
			l = ins;


	}
	return l;
}

void stampa(lista l){

	if(l==NULL){
		printf("La lista e' vuota\n");
	}
	else{
		while(l!=NULL){
			printf("%d ", l->dato);
			if(l->prec==NULL)
				printf("(prec = NULL, ");
			else
				printf("(prec = %d, ",l->prec->dato);
			if(l->suc==NULL)
				printf("suc = NULL)\n");
			else
				printf("suc = %d)\n", l->suc->dato);
			l = l->suc;
		}
	}

}


