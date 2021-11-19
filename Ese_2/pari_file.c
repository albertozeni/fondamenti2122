#include <stdio.h>

void fun(FILE *f1, FILE *f2);

int main(){

	int valori[10]={2491,124,53,63,44,76,10,463267,46,40};
	int valori_pari[10];
	int i, n;

	FILE *input, *output;
	input = fopen("input.dat", "wb");
	fwrite(valori, sizeof(int), 10, input);
	fclose(input);

	input = fopen("input.dat", "rb");
	output = fopen("output.dat", "wb");
	fun(input,output);
	fclose(input);
	fclose(output);

	output = fopen("output.dat", "rb");
	n = fread(valori_pari, sizeof(int), 10, output);
	for(i=0;i<n;i++){
		printf("%d ",valori_pari[i]);
	}
	printf("\n");
	fclose(output);
	return 0;
}

void fun(FILE *f1, FILE *f2){

	int num_letto, r;

	r = fseek(f1, -sizeof(int), SEEK_END);
	while(r == 0){
		if(fread(&num_letto, sizeof(int), 1, f1)!=0 && num_letto%2==0){
			fwrite(&num_letto, sizeof(int), 1, f2);
		}
		r = fseek(f1, -2*sizeof(int), SEEK_CUR);
	}
}
