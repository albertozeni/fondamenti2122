#include <stdio.h>

float  min(float v[], int n);

int main(){

	float a[5]={1.1,2.2,3.3,4.4,0.1};

	printf("Il minimo e': %f\n", min(a,5));
}

float min(float v[], int n){

	if(n==1){
		return v[0];
	}
	else{
		float m = min(v+1,n-1);
		if(m<v[0]){
			return m;
		}else{
			return v[0];
		}
	}
}
