#include <stdio.h>
#include <math.h>


typedef struct{
	float x;
	float y;
} punto;


typedef struct{
	punto 	punti[50];
	int 	n_punti;
} spezzata;


float distanza(punto p1, punto p2);

int main(){

	int i;
	float distanza_spezzata = 0;
	spezzata s;

	printf("Quanti punti ha la spezzata?\n");
	scanf("%d", &s.n_punti);

	for(i=0; i<s.n_punti; i++){
		printf("Inserisci la x del punto %d\n", i);
		scanf("%f", &s.punti[i].x);
		printf("Inserisci la y del punto %d\n", i);
		scanf("%f", &s.punti[i].y);
	}

	for(i=0; i<s.n_punti - 1; i++){
		distanza_spezzata += distanza(s.punti[i],s.punti[i+1]);
	}
	printf("La lunghezza della spezzata vale %f\n", distanza_spezzata);

	return 0;
}


float distanza(punto p1, punto p2){

	float dx, dy;
	float dist;
	dx = p1.x - p2.x;
	dy = p1.y - p2.y;

	dist = sqrtf((dx*dx)+(dy*dy)); //radice di (x1-x2)^2+(y1-y2)^2
	return dist;
}
