#include <stdio.h>

float min(float *v, int dim);

int main(){

	float arr[6]={1.1,5.2,0.6,8.7,0.2,10.3};

	printf("Il minimo vale: %f\n", min(arr,6));

	return 0;
}

float min(float *v, int dim){

	if(dim==1){
		return v[0];
	}else{
		float m = min(v+1,dim-1);
		if(v[0]<m){
			return v[0];
		}else{
			return m;
		}
	}

}
