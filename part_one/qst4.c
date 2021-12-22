#include<stdio.h>
#include<stdlib.h>
//multiple de 2 pour que ca soit une taille exponentielle a lire
//du coup ca va se faire machine bonne => debit memoire eleve.
#define N 100000000
#define n1 128000

long long int memoire(float* A, int n);//n est une variable allouée automatique
//ment(variable de contexte).

int main(int argc, char* argv[]){
  float* A=(float*)calloc(N,sizeof(float));//allocation dynamique.(dans le tas)
  long long int a=memoire(A,n1);long long int b;
  for(int i=1;i<20;i++){
    b=memoire(A,n1);
    if(a>b) a=b;
  }
  printf("Meilleur timing en terme de nombre de cycles est:%lld\n",a);
  float f=2963.590;
  float rslt0=(float)(a/f);float rslt00=(float)(f/a);
float rslt1=4*n1/rslt0;float rslt11=rslt00*(4*n1);
printf("Meilleur debit en Mo/s est:  %.5f\n -- %.5f\n",rslt1,rslt11);
  return 0;
}
