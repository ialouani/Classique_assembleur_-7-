

#include<stdio.h>
#include<stdlib.h>
#define N 10000000

int memoire(float* A,int n1);



int main(int argc, char* argv[]){
  float* A=(float*)calloc(N,sizeof(float));
  for(int j=320;j<N;j=(int)(j*1.2)){//while(j<N) avec j=(int)(j+0.2*j=1.2*j)
    //while(j<N) avec a la fin j=(int)(j*1.2)
    //int j=320;while(j<N) avec a chaque fois j=(int)(j*1.2)
    float debit;
    int t,tmin=memoire(A,j);
    for(int i=0;i<20;i++){
      t=memoire(A,j);
      if(t>0 && t>tmin) t=tmin;}
    debit=(j*sizeof(float))/(tmin/2917.092);//*1.e6 pour pow(10,6)../////  .
    printf("%d %f\n",j,debit);
  }
  return 0;}

  //methode plus intuitive mias necessite une augmentation de 20% de 320 elements en terme de nombre alors que l'autre ca ajoute a 320 20% d'elements restants(un peu moins efficace (voir resume)).
  //PQ via RQ: 20% * 320 <<<< 320. (les nombres sont les memes au titre de la memoire qui parcoure a chaque fois (int)(j_precedent*1.2) a la place de (int)(j_precedent(debutant PAR 320) + 20% ''des elements restants'' faisant appel a N et j_precedent mais surtout a N..)
