#include <stdio.h>

void scambia(float *a, float *b);

int main(){

	float a, b;

	printf("Inserisci a\n");
	scanf("%f", &a);
	printf("Inserisci b\n");
        scanf("%f", &b);
	scambia(&a, &b);
	printf("a: %f, b: %f", a, b);
	return 0;
}

void scambia(float *p1, float *p2){

	float tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;

}
