#include<stdio.h>
#include<stdlib.h>

typedef struct _elem
{
	char car;
	struct _elem *next;
} car_t;

typedef car_t *lista;

void inserisci(char c, lista *l);
void carica(char filename[], lista *l);
void salva(char filename[], lista l);

int main(){

	lista list = NULL;
	carica("lista_input.txt", &list);
	inserisci('g', &list);
	salva("lista_output.txt", list);
	return 0;
}

void inserisci(char c, lista *l){
	lista cur, pre, p;
	
	cur = *l;
	pre = NULL;
	while(cur!=NULL&& c > cur->car){
		pre = cur;
		cur = cur->next;
	}

	p = (lista)malloc(sizeof(car_t));
	p->car=c;
	p->next=cur;
	if(pre!=NULL)
		pre->next = p;
	else
		*l = p;
}

void carica(char filename[], lista *l){

	FILE *f;
	char c;
	int n,i;

	f = fopen(filename,"r");
	if(f!=NULL){
		while(fscanf(f, "%c%d",&c,&n)==2){
			for(i=0;i<n;i++)
				inserisci(c,l);
		}
	}
	else 
		printf("Il file indicato non esiste\n");
	fclose(f);
}

void salva(char filename[], lista l){
	FILE *f;
	char c;
	int n;
	lista cur;
	cur = l;
	f = fopen(filename, "w");
	if(f!=NULL){
		while(cur!=NULL){
			if(cur==l){
				c = cur->car;
				n=1;
			}else if(c!=cur->car){
				fprintf(f, "%c%d", c, n);
				c = cur->car;
				n = 1;
			}else{
				n++;
			}
			cur = cur->next;
		}
		if(l!=NULL){
			fprintf(f, "%c%d", c, n);
		}
		fclose(f);
	}
}
