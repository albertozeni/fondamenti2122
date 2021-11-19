#include <stdio.h>
 
void fun(FILE *f1, FILE *f2)
{
  int r,x;
  r = fseek(f1, -sizeof(int), SEEK_END);
  while(r==0)
  {
    if ( fread(&x,sizeof(int),1,f1)!=0  && (x%2==0) )
      fwrite(&x,sizeof(int),1,f2);
    r = fseek(f1, -2*sizeof(int), SEEK_CUR);
  }
}
 
int main() 
{
 
  int v[5] = {1,2,3,4,5}, v2[5]={0},n,i;
  FILE *out = fopen("numeri.dat","wb"); 
  fwrite(v,sizeof(int),5,out);
  fclose(out);
 
  FILE *in = fopen("numeri.dat","rb");
  out = fopen("pari.dat","wb");
 
  fun(in,out);
 
  fclose(in);
  fclose(out);
 
  in = fopen("pari.dat","rb");
  n = fread(v2,sizeof(int),5,in);
 
  for (i=0; i<n; i++)
    printf("%d ",v2[i]);
  printf("\n");
 
	return 0;
}
