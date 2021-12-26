#include<stdio.h>
#include<stdlib.h>
#define N 1000 //N**2 === 1 million &-*4=> 4 millions octets
//=>4Mo<6Mo (taille cache L2)

void prod_matrix(float*,float*,float*);


int main(){
  float* A=(float*)malloc(sizeof(float)*N*N);
  float* B=(float*)malloc(sizeof(float)*N*N);
  float* C=(float*)malloc(sizeof(float)*N*N);
  for(int h=0;h<N*N;h++){
    C[h]=0;}
  prod_matrix(A,B,C);
  return 0;
}

void prod_matrix(float* A, float* B, float* C){
