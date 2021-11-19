#include <stdio.h>

void fun(FILE *f1, FILE *f2);


int main(){

	FILE *output, *input;

	output = fopen("esercizio.dat", "wb");
	int coppie_da_scrivere[8] = {'a',1,'b',2,'c',3,'d',4};
	fwrite(coppie_da_scrivere,sizeof(int),8,output);
	fclose(output);

	input = fopen("esercizio.dat","rb");
	output = fopen("output_esecizio.txt", "w");
	fun(input,output);
}

void fun(FILE *f1, FILE	*f2){
	int i, v1, v2;
	while(fread(&v1, sizeof(int), 1, f1)!=0){
		fread(&v2, sizeof(int), 1, f1);
		for(i=0; i<v2; i++){
			fprintf(f2,"%c",v1);
		}
		fprintf(f2, " ");
	}
}
