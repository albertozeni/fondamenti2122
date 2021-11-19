#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct nodo{
	int dato;
	struct nodo *pre;
	struct nodo *suc;
};

typedef struct nodo elem;
typedef elem *lista;

lista inserisci_in_ordine(lista l, int dato);
void stampa(lista l);


int main(){

	lista l = NULL;
	int i;
	srand(time(NULL));
	
	for(i = 0 ; i < 5; i++){
		int tmp = rand()%100;
		printf("Inserisco %d\n",tmp);
		l = inserisci_in_ordine(l,tmp);
	}
	stampa(l);
	return 0;
}

lista inserisci_in_ordine(lista l, int dato){
	elem *cur, *pre, *p;
	pre = NULL;
	cur = l;
	while(cur!=NULL && dato > cur->dato){
		pre = cur;
		cur = cur->suc;
	}

	if(cur==NULL||dato!=cur->dato){
		p = malloc(sizeof(elem));
		p->suc = cur;
		p->pre = pre;
		p->dato = dato;
		if(cur!=NULL){//se non sono l'ultimo
			cur->pre = p;
		}
		if(pre!=NULL){//se non sono il primo
			pre->suc = p;
		}
		else{
			l = p;
		}
	}
	return l;
}

void stampa(lista l){
	if(l==NULL)
		printf("La lista e' vuota\n");
	else{
		while(l!=NULL){
			printf("%d ",l->dato);
			if(l->pre == NULL)
				printf("(pre=NULL, ");
			else
				printf("(pre=%d, ",l->pre->dato);
			if(l->suc == NULL)
				printf("suc=NULL)\n");
			else
				printf("suc=%d)\n",l->suc->dato);		
			l=l->suc;
		}
	}
}


