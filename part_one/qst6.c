#include<stdio.h>
#include<stdlib.h>
#define N 10000000

int memoire(float* A,int n1);

float debit(int nbr_cycles, int taille){
  float rslt_1=(float)((2917.092)/(nbr_cycles));
  float rslt_2=rslt_1*taille;
  return rslt_2;
}

int main(int argc, char* argv[]){
  float* A=(float*)calloc(N,sizeof(float));
  float debut=320;int p=1;int limite;
  while((int)debut<N && (int)debut!=limite){
    int len_parcours=(int)debut;
    int a =memoire(A,len_parcours);
    for(int i=1;i<20;i++){
      int b=memoire(A,len_parcours);
      if(b<a) a=b;
    }
    float debit_ici=debit(a,4*len_parcours);
    printf("parcours de %d elements suivant (%d) en Mo/s: %.5f\n",len_parcours,p,debit_ici);p++;
    limite=(int)debut; debut=debut+0.2*(N-debut);
    //a un certain degre plus haut, l'ajout devient negligeable car debut->N
    //donc la 2ieme partie 0.2*(N-debut) tend vers 0
    //du coup l'ajout est non pris en compte par le typecasting (int)
    //mais au  prochain  tour de boucle on aura: la nouveau_debut=nouveau_debut
    //+~0(qui tend de plus en plus vers 0 -- en avancant dans la boucle)
    //=>de meme prochainement meme entier ..=>docn mieux arreter la boucle
    //si l'ajout n'est pas significatif (ecart >=1).((car BUT: parcours d'ele-
    //ment))
  }
  return 0;
}
