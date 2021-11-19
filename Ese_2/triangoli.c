#include <stdio.h>
#include <math.h>

#define N 10.0

typedef struct {
	float x;
	float y;
}punto;

typedef struct{

	punto A;
	punto B;
	punto C;

}triangolo;


void stampaT(triangolo T);
triangolo inserisciTriangolo();
punto inserisciPunto(char c);
float distanza(punto p1, punto p2);
int degenere(triangolo T);
int ugualiAbbastanza(float d1, float d2);

int main(){

	triangolo T;
	int ab, bc, ac;
	float a, b, c;
	int coppie_uguali;
	T = inserisciTriangolo();
	stampaT(T);
	a = distanza(T.B,T.C);
	b = distanza(T.C,T.A);
	c = distanza(T.B,T.A);

	ab = ugualiAbbastanza(a,b);
	bc = ugualiAbbastanza(b,c);
	ac = ugualiAbbastanza(a,c);

	coppie_uguali = ab+bc+ac;

	if(coppie_uguali==3){
		printf("Il triangolo e' equilatero\n");
	}else if(coppie_uguali>=1){
		printf("Il triangolo e' isoscele\n");
	}else{
		printf("Il triangolo e' scaleno\n");
	}

	return 0;
}

int ugualiAbbastanza(float d1, float d2){

	float max, min;
	int uguali = 0;
	float diff;
	max = d1;
	min = d1;
	if(max < d2){	
		max = d2;
	}
	if(min > d2){
		min = d2;
	}
	diff = max-min;
	if(diff < (max/100)*N){
		uguali=1;
	}
	return uguali;
}

float distanza(punto p1, punto p2){

	float dist;

	float diffx, diffy;

	diffx = p1.x-p2.x;
	diffy = p1.y-p2.y;

	dist = sqrtf(diffx*diffx+diffy*diffy);

	return dist;
}

int degenere(triangolo T){
	int res=0;//res vale 1 se il triangolo è degenere

	if(distanza(T.A, T.B)==0||distanza(T.B,T.C)==0||distanza(T.A,T.C)==0){
		res=1;
	}
	else{
		res=0;
	}

	return res;

}

punto inserisciPunto(char c){

	punto p;

	printf("Inserisci le coordinate del punto %c\n", c);
	printf("Inserisci X\n");
	scanf("%f", &p.x);
	printf("Inserisci Y\n");
        scanf("%f", &p.y);

	return p;

}

triangolo inserisciTriangolo(){

	triangolo temp;
	int deg;
	do{
		temp.A = inserisciPunto('A');
		temp.B = inserisciPunto('B');
		temp.C = inserisciPunto('C');
		deg = degenere(temp);
		if(deg==1){
			printf("Il triangolo inserito e' degenere, inseriscine un altro\n");
		}
	}while(deg==1);
	return temp;
}

void stampaT(triangolo T){

	printf("Il triangolo inserito e':\n");

	printf("Il punto A ha -  X %.2f, Y %.2f\n", T.A.x, T.A.y);
	printf("Il punto B ha -  X %.2f, Y %.2f\n", T.B.x, T.B.y);
	printf("Il punto C ha -  X %.2f, Y %.2f\n", T.C.x, T.C.y);
}
