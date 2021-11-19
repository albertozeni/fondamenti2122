#include <stdio.h>

int cifre(int num);

int main(){

	int n;
	scanf("%d", &n);
	printf("Il numero ha %d cifre\n", cifre(n));
	return 0;
}

int cifre(int num){

	if(num<10){

		return 1;
	}else{

		return 1+cifre(num/10);
	}

}
