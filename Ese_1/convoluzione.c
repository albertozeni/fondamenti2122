#include<stdio.h>

void conv(int A[][100], int B[][100], int K[3][3], int nr, int nc);
void stampa_matrice(int mat[][100], int n_righe, int n_col);


int main(){


	int K[3][3] = {{0,-1,0}, {-1, 5, -1}, {0,-1,0}};
	int A[6][100] = {}
