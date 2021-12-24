#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>

char message[25] = "Cela provient d'un tube";
int main()
{
    /*
       * communication PERE --> FILS par pipe
     */

  //RQ ESSENTIELLE: avant l'execution, les pages virtuelles de la memoire(Sys+argv+env (en adresses decroissantes /ZONES''./////) puis: pile puis: dynamic biblios puis: le tas(vide au debut, un peu !=vide~~__2+ des un appel a une allocation puis repousser la limite a chaque appel(limite visible)) puis: vars. globales/statiques(avec portee les empechant de changer de valeur en cas de variable de contexte)+code du binaire a la fin) relatives au processus (1 seule page possible...) sont deja chargées à t_execution-dt.((disons: apres la compilation separee)) donc en gros un processus pour qu'il demarre il va pas commencer a executer sans lire ou ecrire cest logique donc il doit soit faire l'un des deux au debut => il va ecrire (dans la pile les variables allouees automatiquement) puis a la fin ecrire (formater les plages memoires en de nouvelles/rediriger des erreurs a des programmes (sortie<|exemple.: seg. fault)) donc tout pid: ce pid est relie a un processus qui dans un tuyau (c'est generique!//) commence par ecrire puis lire pourquoi ecrire car les pages memoires sont pretes ce qu'il va faire au ./a.out c'est les manipuler donc depiler par exemple ou empiler une nouvelle valeur => modifier avec lecture ensembliste connue => ecrire puis a la fin il finira son travail et la sortie de ce tuyau (exec. process{pid}:: ./a.out apres compilation separee) dont l'entree etait l'ecriture et la sortie la valeur le rslt le fichier .txt a generer.. donc: a la sortie il nous fournit le processus de lecture (comme au debut on lui a fournit la possibilite d'ecrire(manipuler les donnees dans le fichier resultant objet .o avec les lib?.a et les lib?.so) i.e. il donne a la sortie un process qui indique que quelquechose doit etre lue avec entree 3ieme processus<sortie_process[a.out char* argv[0<=i<argc] en exec.] donc sortie lecture vers la memoire par exemple avec lecture specifique puis sortie memoire processus d'affichage des resultats mis dans des buffers exemplaires classiques pour la libsc(librairie standart basique du c permettant un gcc sans lier les biblios dynamiques definissant les symboles fonctions /usr/include/stdio.h par exemple(symbole manquant printf apres compilation uniquement du prototype depuis le .h ));la compilation est possible car avec l'inclusion;gcc -E affiche bien le fichier en entier en terme de nom dans "<command-line>"\n#/usr/include/stddef.h avec des nombres...(le stddef permet d'utiliser printff???, size_t(versions pas c99 voire moins-..///)). Donc: ecriture->PROCESS->lecture <=> tube === 'int p[2]; int pipe(int[2]);';voilà.
  

  
  //car avec fork() c'est le pid du parent qui va s'executer
  //car le premier retour est le pid du fils(!=0) => on sera dans le processus
  //parent (sinon retour 0=>on est sur l'enfant).
  //donc avec fork(); si on veut ecrire le message de 24 octets dans la sortie
  //standard ; il faut que p[1]=fd telque fd=descriptor_file(FILE* F) soit
  //la sortie standard par defaut ici qui est: stdout.
  //rappel:a fork()- , on duplique le process appelant
  //DONC: write(p[1],message,24) va faire entrer au process write p[1]
  //mais fork() juste avant a marquer le processus parent donc le processus
  //marquant ici sera le parent ET PUISQUE le tube pipe est avant le premier
  //fork() ecrit c'est que le tube cree au debut a permit de lier son processus
  //d'entrée au parent de 'fork' et la sortie au fils de 'fork' donc p[1]
  //est relative au fils=>p[1] est un entier relatif a un fichier telque fork()
  //duplique p[0] qui est le fichier ou on doit ecrire donc fork() dans la deuxieme boucle fera un write dans le processus parent(entree des sorties de write vers des processus connus englobes en parent_proceSS) (fork()!=-1 && fork()!=0 2< a cette etape) donc write dans le fichier d'ecriture donc,c'est gagné! ; apres vient l'execution du 3ieme fork() qui fait un read suivant le fils qui est l'ecriture i.e. l'entree de read va etre le fichier attache a p[0] qui represente l'ecriture donc la sortie de la precedente condition.tout est bon.
  
  //c'est pour cela qu'on dit qu'ici le pere via frok() lié a p[0](caracteristiques heritees apres un fork() QUI LAISSE DU COUP LE PARENT p[0] SUIVANT LE TUBE EN ENTREE et de meme pour l'autre cote ; c'est pour cela qu'on doit creer le tuyau au debut avant le 1er appel a fork pour qu'apres l'appel a fork impose la caracteristique de l'entree au parent/enfant et inversement.) envoie indirectement au fils le message via le tube a imprimer a la fin sur __STDOUT pq? CAR:>>


  /*
    l'appel a fork() apres un int pipe(int [2]) et int p[2] permet de creer une duplication d'un processus appelant avec deux pid ###, si fork() renvoie le pid du fils, on va traiter le processus pere qui sera soit a l'entree du tube soit a la sortie ; d'une facon ~~(---)similaire, on le considere a la sortie donc a la sortie du tube on a p[0] ;(donc a l'entree on a p[1]) cela va se parametrer via: write(p[1]-car p[1] est en entree donc c'est le descripteur du fichier de lecture-,message,24) qui va ecrire 24 octets de *(message+0<=i<24) dans p[1] qui rappelons-le est a l'entree du tube car p[0] est a la sortie puis le dernier frok() obligatoire va faire un read depuis p[0] cad. fd de de de sortie du tube avec le processus fils qui est ici relatif a (le pere est via frok() fork(); plutot avant donc suivant p[1]) p[0] car p[1] est le pere donc dans le tube forcement p[0] est le fils et donc on va depuis p[0] qui est a la sortie du tube cad. le fd du fichier type__---lecture LIRE(read(p[0],&c,1)) chaque charactere dans p[0] mais cela c'est apres le fork() donc apres un write dans p[1] qui est celui de l'entree donc le prochain appel de fork() va executer ceci(car ca traite le processus fils donc relatif a p[0] qui est a la sortie donc fork() va faire appel a l'execution du processus fils (pid=pid_père+1) apres avoir execute celui du parent et donc ce qui manquait est fait dans le tube : la sortie ainsi definie ici comme p[0] est definie comme la sortie de write apres la derniere condition(execution du pid_parent relatif a p[1] qui fait un write donc fait tout~(++) pour le tube) et renvoyer dans p[0] la sortie du tube le rslt qui sera le fichier de depart pour le lire et afficher charactere par charactere et c'est ce qu'il fait read(p[0],&c,1) avec p[0]=tuyau_<<{./p[1].exec<=>exec. de write(p[1],message,24)} donc affichage du message dans le stdout ; tout cela <=> le pere p[1] apres un fork() est linké a la sortie d'entrée du tube(lecture) et est utilisé pour faire un writesur p[1]-1(file)-1 lui-meme() cad. que le read apres le prochain frok() evidemment_____2 va utiliser le message ecrit par le processus pere relatif a p[1] pour faire le processus p[0] relatif a la lecture depuis le p[0] qui a ete fait vu que l'entree du tube p[1] a ete connue lors de la precedente condition et que le tuyau est pret <=> le pere envoie via un write le message qui sera lu par le processus fils pour l'imprimer <=> le pere envoie au fils un message dans le TUBE.     */

  
    int p[2];
    int pipe(int[2]);
    //creation d'un tube p[0] descripteur pour lire et ecrire pour p[1].
    if (pipe(p) == -1) {
        fprintf(stderr, "erreur ouverture pipe\n");
        exit(1);
    }
    if (fork() == 0) {          /* processus fils(fork() initial INCLUS()). */
      //le deuxieme normalement.
        char c;
        close(p[1]);
        while (read(p[0], &c, 1) != 0)
            printf("%c", c);
	printf("\n");
        close(p[0]);
        exit(0);
    } else {                    /* suite pere(la premiere normalement) */
      close(p[0]);//fermer via descriptor_file p[0] a l'entree du tube.
      write(p[1], message, 24);//ecrire sur la sortie definie par
      //un fichier dont le descriptor est p[1] 24 octets(char car en code ASCII
      //1 octet pour chaque charactere(car c'est suffisant!)) du char*: message
      //.
      close(p[1]);//fermer la sortie d'ecriture qui etait ouverte par defaut des
      //la creation du tube.
      exit(0);//tout se passe bien<=>$? apres l'exec. affiche au terminal 0.
      //toujours un close du precedent p[??+/-|-/+<><>] et un close apres
      //du fd en cours puis un exit(0) car dans le main.
    }


    //meme si on fait un exit(0) en 2 pas uniquement un wait(NULL) (il faudrait

    //inclure le fichier /sys/wait.h );   l'application du processus parent ici
    //va (pid_enfant-1) va changer P[0] et du coup il y aura fork() autre qui attend detraiter le processus pid+1 obligatoirement.(la 1ere pas importante)./////
}

