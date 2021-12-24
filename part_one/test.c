#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {

  //creation d'un pid via un processus quelconque en cours
  //avec duplication via fork();appel0.
  
  pid_t c_pid = fork();//duplication processus appelant => a partir du
  //processus parent, on aura un fils de pid=pid(processus_pere)+1.
  //processus quelconque en cours pour affectation suivant fork().

  //!echec<=>c_pid retourne 2 fois:>
  //1->il renvoie le pid du processus enfant dans le parent.
  //2->il renvoie pour UN DEUXIEME APPEL 0 dans le fils.
  
  if (c_pid == -1) {//erreur n'arrivant presque jamais.
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (c_pid == 0) {//contraire:
      //renvoie 0 dans le fils donc pid=0 a l'entree du fils
      //=>trivialement application direct du processus enfant.
      //(comme une fonction sans arguments)
      //=>processus en cours: celui du FILS. (pid =pid_père+1)
        printf("printed from child process : %d\n", getpid());
        exit(EXIT_SUCCESS);
    }

    else {
        printf("printed from parent process : %d\n", getpid());
        wait(NULL);
    }//resume:

    /*
fork() en __2 met a l'entree du processus parent le pid du processus fils (pid_t c_pid=fork() permet la duplication d'un processus appelant QUELCONQUE ici en nouveau: fils => pid_new=pid++;pid--; donc en __2 ca va mettre a l'entree du processus pere le processus defini par le pid de l'enfant (par exemple parent est | grep [a]pt et fils est ps aux ; ps aux cmd. gnu/linux qui detient un unique pid et le bloc |grep [a]pt qui est une fonctionnalite est aussi definie comme fonction ayant un pid (variant selon les entrées(types par exemple)) donc en __2 ca va mettre pid_enfant vers pid_parent avec pid_enfant=pid_parent+1<pid_parent (notons que fork() avec affectation tout au debut a dupliquer le processus et la difference des pid est oblige sur gnu/linux de 2 processus occupant en entier des plages memoire differents et sinon des valeurs/adresses ###) donc cela va impliquer
vu que pid_enfant en entree < pid_parent et sont les memes et l'origine est le parent a executer le parent=>on est dans le processus pere.
    */

    /*
remarque IMPORTANTE:
fork() renvoie 0 ou le pid de l'enfant => appliquer processus enfant derive de celui du parent => appliquer le parent => getpid() renvoie le pid<.
    */

    //remarque2: processus parent c'est bon;(\ pid=pid_enfant-1)
    //=>pid_PARENT+1 non pris en compte (en attente)
    //car ~celui_du__parent cest pour cela appliquer parent sans passer par fils
    //n'impactait en rien le rslt final mais a la fin il faut terminer par
    //passage au pid_enfant => apres le getpid();c_pid devient 0,{car pas passage par celui dupliqué fils}~pid_suivant a prendre en compte "" "" ;((dans cette chaine de code avant le exit(macro de exit success))) (!#include<sys/wait.h>!) les 2& IMPLIQUENT un saut vers if(c_pid==0) et du coup getpid() retourne vu qu'on se retrouve dans le fils dont l'ENTREE MAIS PAS LE PID est a 0 le pid de l'enfant===pid_parent+1.

    //on aura a la fin apres epuisement buf'/frok ()/ ' ;  un exit en $?=0 avec:
    /*
pid_initial=pid_suivant -1;
pid_suivant=pid_initial +1;
    */

    /*
resume:
fork():
-1: error
0: processus fils (celui en cours dont on tiendra compte dans les statements de la condition)
Le PID du fils: on est dans le processus père.(((de meme)))
    */
    exit(EXIT_SUCCESS);
}
