#include <stdio.h>
#include <math.h>

#define ERROR 1.0

typedef struct{

	float x;
	float y;

} punto;

typedef struct{

	punto A;
	punto B;
	punto C;

} triangolo;

punto 	  inserisciPunto(char c);
triangolo inserisciTriangolo();
void	  stampaTriangolo(triangolo T);
float	  distanza(punto p1, punto p2);
int 	  degenere(punto p1, punto p2, punto p3);
int 	  uguale(float d1, float d2);

int main(){

	int ab, bc, ac;	
	float a, b, c;
	int coppie_uguali = 0;
	triangolo T;
	T = inserisciTriangolo();
	stampaTriangolo(T);	
	a = distanza(T.B, T.C);
	b = distanza(T.A, T.C);
	c = distanza(T.B, T.A);

	ab = uguale(a,b);
	bc = uguale(b,c);
	ac = uguale(a,c);

	coppie_uguali = ab+bc+ac;
	if(coppie_uguali == 3){
		printf("Il triangolo e' equilatero\n");
	}else if(coppie_uguali >= 1){
		printf("Il triangolo e' isoscele\n");
	}else{
		printf("Il triangolo e' scaleno\n");
	}
	return 0;
}

int uguale(float d1, float d2){

	int res;
	float max = d1;
	float min = d1;
	float diff;
	if(max<d2){
		max = d2;
	}
	if(min>d2){
		min = d2; 
	}
	diff = max-min;
	if(diff > (max/100)*ERROR){
		res=0;
	}
	else{
		res = 1;
	}
	return res;
}

punto inserisciPunto(char c){

	punto p;
	printf("Inserisci i dati del punto %c\n",c);
	printf("Inserisci x\n");
	scanf("%f",&p.x);
	printf("Inserisci y\n");
        scanf("%f",&p.y);
	return p;
}

int degenere(punto p1, punto p2, punto p3){

	int res;
	
	if(distanza(p1,p2)==0||distanza(p1,p3)==0||distanza(p2,p3)==0){
		res=0;
	}else
		res=1;

	return res;
}

triangolo inserisciTriangolo(){

        triangolo temp;
	int test = 0;
	
	do{
        	temp.A = inserisciPunto('A');
        	temp.B = inserisciPunto('B');
        	temp.C = inserisciPunto('C');
	
		test = degenere(temp.A, temp.B, temp.C);
		if(test==0){
			printf("Il triangolo inserito e' degenere\n");
		}
	}while(test==0);

	
        return temp;
}

float distanza(punto p1, punto p2){

	float dist;

	float diffx, diffy;
	diffx = p1.x - p2.x;//x1-x2
	diffy = p1.y - p2.y;//y1-y2

	dist = sqrtf(diffx*diffx+diffy*diffy); //radice di (x1-x2)^2+(y1-y2)^2

	return dist;

}

void stampaTriangolo(triangolo T){
	printf("Triangolo inserito:\n");
	printf("Punto A - x: %2.2f, y: %2.2f\n", T.A.x, T.A.y);
	printf("Punto B - x: %2.2f, y: %2.2f\n", T.B.x, T.B.y);
	printf("Punto C - x: %2.2f, y: %2.2f\n", T.C.x, T.C.y);
}
