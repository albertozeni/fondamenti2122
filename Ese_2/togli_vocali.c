#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

void riduci_iter(char* s); // versione iterativa che modifica s
void riduci_ric(char* s); // versione ricorsiva che modifica s
char *riduci_ric2(char* s); // versione ricorsiva che NON modifica s e 
 				// restituisce la stringa senza vocali
int vocale(char c);


int main(){

	char s1[MAX], s2[MAX], *s3;

	printf("Inserisci la prima stringa\n");
	scanf("%[^\n]%*c",s1);
	printf("Inserisci la seconda stringa\n");
        scanf("%[^\n]%*c",s2);

	s3 = riduci_ric2(s1);
	printf("%s\n", s3);

	riduci_iter(s1);
	riduci_ric(s2);
	if(strcmp(s1,s2)==0)
		printf("Le due stringhe sono uguali a meno delle vocali\n");
	else
		printf("Le due stringhe sono diverse anche senza vocali\n");


	return 0;
}

int vocale(char c){
	if(c=='a'||c=='i'||c=='e'||c=='o'||c=='u')
		return 1;
	else
		return 0;
}


void riduci_iter(char *s){

	int i, j=0;
	for(i=0;s[i]!='\0';i++){
		if(vocale(s[i])==0){
			s[j]=s[i];
			j++;
		}
	}
	s[j]='\0';
}


void riduci_ric(char *s){

	int i;
	if(strlen(s)==0)
		return;
	riduci_ric(s+1);
	if(vocale(s[0])){
		for(i=1;i<strlen(s)+1;i++){
			s[i-1]=s[i];
		}
	}
}

char *riduci_ric2(char *s){
	
	if(strlen(s)==0)
		return "";
	if(vocale(s[0])){
		return riduci_ric2(s+1);
	}else{
		char *new_s = (char *)malloc(sizeof(char)*(strlen(s)+1));
		char *suff = riduci_ric2(s+1);
		new_s[0] = s[0];
		new_s[1] = '\0';
		strcat(new_s,suff);
		if(strlen(suff)){
			free(suff);
		}
		return new_s;
	}
}
