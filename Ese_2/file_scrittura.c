#include <stdio.h>

void fun(FILE *f1, FILE *f2);

int main(){

	FILE *input, *output;

	int coppie[6]={'c',10,'g',2,'a',1};
	input = fopen("dati.dat","wb");
	fwrite(coppie, sizeof(int), 6, input);
	fclose(input);

	input = fopen("dati.dat", "rb");
	output = fopen("risultato.txt","w");
	fun(input,output);
	fclose(input);
	fclose(output);
	return 0;
}

void fun(FILE *f1, FILE *f2){

	int v1,v2;
	int v[2];
	int i;

	while(fread(v,sizeof(int),2,f1)!=0){
		//fread(&v2,sizeof(int),1,f1);
		for(i=0;i<v[1];i++){
			fprintf(f2,"%c",v[0]);
		}
		fprintf(f2," ");
	}
}
