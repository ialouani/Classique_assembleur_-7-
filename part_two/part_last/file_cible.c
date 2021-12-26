#include<stdio.h>
#include<stdlib.h>
#define N 1000

struct ss{
  double x,y,z,t;
  int* val;
};

struct s{
  double x,y,z,t;
  int val[1024];
};

struct sss{
  double x[N];
  double y[N];
  double z[N];
  double t[N];
  int val[1024];
};

struct sss2{
  double* x;
  double* y;
  double* z;
  double* t;
  int* val;
};


void creation();
void afficher2(struct sss sss10);
void creation2(){
  struct sss sss0;
  for(int k=0;k<N;k++){
    sss0.x[k]=1;}
  // afficher2(sss0);
}

void afficher2(struct sss sss10){
  for(int h=0;h<N;h++){
    printf("%.2f\n",sss10.x[0]);}}

		  
void afficher(struct s ssss[],int len){
  for(int j=0;j<len;j++){
    printf("%.2f--%.2f--%.2f--%.2f\n",ssss[j].x,ssss[j].y,ssss[j].z,ssss[j].t);}
  return ;}

int main(int argc, char* argv[]){
  if(atoi(argv[1])==0){
    creation();}
  else{
    creation2();
  }
  return 0;
}


void creation(){
  struct s s1[N];
  for(int i=0;i<N;i++){
    s1[i].x=1;
  }
  // afficher(s1,N);
  return;}
