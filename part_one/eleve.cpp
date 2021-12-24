#include <iostream>
#include <cstring>
#include <sys/wait.h>
#include <unistd.h>

//ls -la >> a.txt ; awk {'print $5 "        " $1'} a.txt .


using namespace std;

char* GetSystemOutput(char* cmd)
{
    int buff_size = 32;
    char* buff = new char[buff_size];//instanciation de la classe char par new
    //nom_de__la_classe puis la taille.((caracteristique importante!!((2)))).///

    char* ret = NULL;
    string str = "";

    int fd[2];//tableau de 2 descripteurs cles d'acces au fichiers.(r/w...)
    int old_fd[3];//un ancien ajoute de 1.
    pipe(fd);//le tube est cree en utilisant avec les fd
    //l'entree de lecture classique et la sortie d'ecriture classique.(###)
    //ne pas donner d'arguments a pipe va automatiquement considerer le tableau
    //de 2 elements precedents comme un couple (pere,fils) et en faire un tuyau
    //avec 2 entrees differentes dans les 2 cas et meme chose exactement
    //pour la SORTIE ; c'est que fork() qui va initier ces processus et du coup
    //savoir en fd[0] qui sera par exemple le fichier d'ecriture(presque tjrs)
    //l'entree principale<=>process_parent en gros et de meme pour fd[1] qui dans ce cas va representer le processus fils au processus relatif a fd[0].(ou inversement;rappelons que le pipe peut avoir le fd[0] qui represente w en entree comme en sortie COMME on a dit tout au debut)./

    old_fd[0] = dup(STDIN_FILENO);//fd telque stdin_fileno a le meme fd
    old_fd[1] = dup(STDOUT_FILENO);//de meme
    old_fd[2] = dup(STDERR_FILENO);//de meme
    //old_fd contient les 3 descripteurs des fichiers d'ecriture/lecture standart et pour le 3ieme le descriptor du fichier ou se trouve le contenu de la sortie d'erreur.

    int pid = fork();//appel a fork() 1 seule fois(la premiere)
    //=>duplication de processus et creation d'un pid_enfant=pid_parent+1.
    switch(pid)
    {
       case 0://on est sur le processus fils.
	 //saut ici apres default et sortie definitive car break tout a la fin.

	 //travail avec processus fils d'entrée reading_porcess && (une fonction peut avoir une fonction en parametre(void* strcmp(size_t strlen(char* s),char* s1, char* s2)) qui prendra strlen pour calculer les longueurs,c'est variable(plusieurs methodes pour calculer string str/<<    str.length();;) + rslt_tube===fd[1].
	 //bloc pere avec: ecriture,fd[0] + manips. => sortie dans la 1ere partie du tube c'est pour cela le tube se met en lecture attachée à fd[0] relatif au pere (entree de fd[0] (file) vers le pere avec le processus d'ecriture ici ///schematisation__explication+)).

	 //bloc fils:(processus fils ICI (pid_pere+1))::
	 //entree fd[1] resultat du tube + ###(2 fois) writing process=>rslt_final
	 //par effet de bord, rslt_final update -era RET puis return ret pour
	 //la fonction::   **char* GetSystemOutput(char* cmd)**.////
	 close(fd[0]);//normal.(copie deja faite hhh!!!)
	 //il doit now appeler une fct. qui utilise fd[1] ..
	 //on veut afficher sur la sortie standart, ret est ~??pret =>dup2.
	 close(STDOUT_FILENO);//au cas ou.. dup2 (tjrs existe) cree une copie
	 //vierge.
	 close(STDERR_FILENO);//comment (2) la-haut conviennent a ICI.
	 //fd[1] est prete c'est ret => on copie dans fd[1] le OuT
	 //du processus (pid--)=>on copie le rslt resultant de default:
	 //=>on lit depuis fd[1] qui vaudra vu ces remarques ret avec creation
	 //d'une copie sur fd[1].(redondance mais on doit proceder comme ceci)
	 dup2(fd[1], STDOUT_FILENO);//de meme(ci-dessus).
	 dup2(fd[1], STDERR_FILENO);//de meme_2 (ci - dessus)./
	 //ajout encore pas recreation d'une nouvelle copie INDEPENDANTE.
               system(cmd);
	       
	       //On appelle un prog. shell classique cree par cmd("usr/bin/lsb_release -a") avec des sdtin deja mises a jour (le resultat du processus pere(car dup2(fd[0],STDIN_FILENO) lie fd[0] a STDIN_FILENO (pas de file entrant en jeu a la deuxieme modif. et plus..) et donc ce prog.shell va prendre ret(resultante du processus pere fd[0] qui suivant le tube fournit en ecriture ret) et va appeler la fonction system sur une 'autre' entree principale qui est cmd ; en gros fd[1] relatif au fils qui est suivant sortie lecture du pipe va tout simplement lire la sortie du PIPE et va l'afficher sur le stdout devenu vierge apres les 2 commandes:close(STDOUT_FILENO) ;  dup2(fd[1],STDOUT_FILENO)(linkage apres ceci) donc system(cmd) va retenir pid_enfant qui execute le processus de lecture de sortie du tub (valeur de (char*)RET) et la linker a stdout tout cela avec appel systeme pour rendre globale les affichages_rslts. 
	       
               //execlp((const char*)cmd, cmd,0);
               close (fd[1]);//obligée.
               exit(0);//($?==0)oui/:non .
               break;

    case -1://rien ; erreur dans l'appel de fork (size_t >=0 et pid jamais <0)
               cerr << "GetSystemOutput/fork() error\n" << endl;
	       //syntaxe de printf dans .cpp (header: iostream.h)
	       //pour la sortie d'erreur fprintf(stderr,"")<=>cerr << "" << endl
               exit(1);//car probleme, on va pas faire exit(0)
	       //quand meme!!!!!

    default://on est dans process_parent/pid=--pid_prec.
      //demarrage du prog. depuis ici car tjrs fork() renvoie une valeur!=0
      //&&!=-1 au debut.(plus precisement, elle renvoie le pid du fils>0 car
      //pid_fils=pid_parent+1>=1)
      close(fd[1]);//fermer la copie du descripteur de STDOUT_FILENO
      //hhhhh, ca sert a rien de faire un close de 2___(fd[3])(old_fd[3])
      dup2(fd[0], STDIN_FILENO);//faire une copie du descriptor(STDIN_FILENO)
      //vers fd[0].(~affectation) => a retenir(fonction dup2).

      /*
      int test_rapide(char* test1, char* test2){//meme longueur.
	if(! *test1 || ! *test2 ) return 1;
	return *test1++=*test2++ && test_rapide(test1,test2);}
      */

      //string str_avant=""
      int rc = 1;//int i=0,j=0;
               while (rc > 0)//ou bien while () (si str existe;
		 //donc ""+*buff(1 element du tableau char[](buff);rc)
		 //i.e. *str!='\0' car on aura rc=0 a un tour ou fd[0] en entier
		 /*suivant tous les appels a ete parcouru donc str.append(buff,rc) va concatener a str precedemment les rc prochains characteres de buff (type char[]) donc au debut str vaudra les 32 characteres prochains de buff(buff=buff_debut+buff_size) si buff_size est bon___2 puis ajouter les rc prochains suivant l'apres APPEL a read donc str a la fin quand rc va faire en sorte que rc prochain=0;là str va valoir str_avant car rc=0 donc concatenation a rc de 0 characteres depuis buff.).////
		  */ 
               {
		 //strcpy(str_avant,str);(retourne un pointeur sur le
		 //zero terminal de la destination)
		 rc = read(fd[0], buff, buff_size);//<=>read(fd[0],&c,32)
		 //avec char c est tel que char* buff verifie: *buff=c
		 //<->on lit depuis fd[0] 32 char et on les ecrit
		 //pas a pas dans new char[buff_size] ou bien plus
		 //precisement dans buff cad. *buff=fd[0] puis:
		 //*(buff+i)=fd[0]_en_position_i avec 1<=i<=31.
		 //RESUME: on remplit 32 octets a partir de buff avec
		 //les 32 premiers de fd[0].
		 //ca va lire 32 octets depuis fd[0] cad. une chaine de 32
		 //characteres et la mettre dans la suite des (buff[i])_{i}
		 //rc renvoyee va etre le nombre de characteres lus.
		 //tant que rc>0 cad. j'arrive a relire d'autres char[] et les
		 //mettre dans new char[buff_size] 

		 str.append(buff, rc);

//on ajoute a la suite *(buff+i)
		 //1 element depuis str ; cad. str devient: "`${*buff}`"
		 //str VA DEVENIR str.concatenate("`${*(buff+i)}`;0<=i<rc).
		 //mais avant str.append -immediatement buff se positionnera au 33-ieme characetre du tableau char[] nomme buff donc str va recuperer a partir de la derniere position+1 reconnue depuis la lecture de fd[0]+comparaison avec la suite des *buff : rc(nbr_char_lus) prochains de buff avec affectation, donc
		 //ca changera a chaque tour de boucle.
		 //a la fin rc=0(fd[0] atteint la limite => str="")
		 //i+=32;
		 //En conclusion, str contiendra buff[33].........la fin de
		 //Char [] buff ('\0')
		 //buff==NULL a la fin (!presence effets de bord(fonction read))
		 //fd[0] change pas , c'est un idparticulier de fichier
		 //c'est juste que ftell(-1idparticulier_fct-1(fd[0]))
		 //s'incremente de rc.(curseur_-> debut__ lecture)


		 //~*buff est (nil) a la fin c'est pour cela
		 //qu'a chaque tour on peut le moduler, cest a dire:
		 //mettre a 0 tous les prochains characteres (len==32)
		 //mais cela impacterait la boucle et ne peut pas se faire
		 //a la fin, et beh oui! car buff est deferencable a 99%
		 //donc a 80%; on peut pousser la limite 'non ecrite' debut
		 //par +dernier_element de fd[0] parsize_t(%ld) buff_size 0
		 //en terme d'adresse meme si buff a une taille de 32
		 //n'oublions pas qu'on manipule buff===new char[buff_size]
		 //donc a priori l'acces au 33i-ème element est logiquement possible donc allons-y remplissons les 32 prochains octets apres le zero terminal par 32 0 <=> memset(buff,0,buff_size).
		 
		 //j+=rc;
                   //memset(buff, 0, buff_size);(mettre les 32 octets
		 //prochains a partir de *buff (32 characteres;sizeof(*buff)=1)
		 //a 0.(pour que *(buff+len)='\0' ;existe len>=0.///
               }


	       //a la fin, fd[0] (ftell,fseek(args[])) a ete entierement parcourue et son contenu est dans buff theoriquement Char [] $(buff-j) avec str buff[33] jusqu'à la fin de buff (*buff='\0') et rc est nulle.(variable NULLE)


	       //str de type objet string => conversion en char*
	       //str.c_str() donne la CONVERSION en char* pour appliquer strlen.
               ret = new char [strlen((char*)str.c_str())];

               strcpy(ret, (char*)str.c_str());//possible meme si ret=NULL
	       //au debut car modification d'adresse très locale( () ) .

	       //ret devient le (char*)str.c_str d'avant (str.c_str() renvoie
	       //le string sous forme d'un tableau ORDINAIRE)
               waitpid(pid, NULL, 0);//pid=fork() en premier=>pid du fils:fd[1].
	       //decrementation du pid pour un waitpid qui est equiv. à
	       //attendre l'exec. du prochain PROCESS.
               close(fd[0]);
	       //en gros ici, on a ecrit dans str 33-..-\0 de fd[0] qui est
	       //l'entree vers le pere via une ecriture suivant le tube; i.e.
	       //on fait depuis fd[0] en faisant entrant le processus ecriture
	       //au pere relatif a fd[0] i.e. le pere a 2 entrees ecriture et
	       //fd[0] donc relatif a fd[0] pour fd[2](int pipe(fd)) et relatif
	       //a ecriture pour le tube (pipe creee au debut):ecriture_entree
	       //=>fichier en lecture/ecriture.
	       //PUIS: le tuyau est pres => on met en lecture et en ecriture&pere suivant fd[0] dans l'entree principale unique du tube (<<<<|ok./ )  <=>  lecture depuis l'entree fd[1] avec str pret,(rc=0),fd[0] identificateur hors portee ~ici (entree vers pere avec ecriture : process_parent qui met la boucle ecriture depuis fd[0](r!!) dans buff + str's updating) en entree au process{//pid--//}
	       //avec donnée d'entrée fd[1] sortie du tuyau (id__file d'ecriture ) et lecture___process.
	       //dup2(fd[0],STDIN_FILENO) marque le caractere lecture et ecriture dans un buffer_annexe du fichier dont le descriptor est fd[0].
	       //rappel: ret c'est la meme que str.
	       //**ret=new char[strlen(char*)str.c_str()].**

	       // std::cout << ret << std::endl;
	       
    }

    dup2(STDIN_FILENO, old_fd[0]);//copie des elements sortants un par un
    //vers le tableau des old_fd[i];0<=i<3.
    dup2(STDOUT_FILENO, old_fd[1]);
    dup2(STDERR_FILENO, old_fd[2]);

    return ret;
}

int main(int argc, char* argv[]){
  
  char* p=strdup("/usr/bin/lsb_release -a");//<=>(char*)___typecasting.
  char* p2=GetSystemOutput(p);//appel
  //cree le pipe ecriture lecture apres fork()
  //int fd[2]=>fd[0] relie a w/e et fd[1] relie a r/s.
  //frok()__2iemeappel renvoie pid_fils===pid_;/fd[1]/;
  //=>application suivant le processus pere qui est linkée a e[tube]==fd[0]
  //donc on doit depuis fd[0] pouvoir ecrire dans un buffer les elements de fd[0] puis le tuyau va les retourner en lecture dans fd[1];on commence par:
  /*
fclose(fd[1]);
dup2(fd[0],STDIN_FILENO);//linkage+pas non statique car but=>saut_rslt?=>close(fd[0])
puis boucle:
(rc>0)?do{
rc=read(fd[0],buff,buff_size);str.append(buff,buff_size);}:break;
PUIS::
ret=(char*)new char[strlen(char*)str.c_str()] avec str=buff[33+]((...////));
PUIS saut vers fork()==0 (2ieme processus) (car le pipe execute le premier et le rslt fourni est envoye vers l'entree du processus_fils ici avec r_process et fd[0] (avant, on doit faire: close(fd[0])) =>::::
close(fd[0]);
dup2(fd[1],STDIN_FILENO);dup2(fd[1],STDERR); puis faire un appel system:
system(cmd) pour executer suivant le processus_fils la lecture de fd[0] (sortie du 1/2 rslt_pipe()) avec STDIN en globale(variable pas statique) cad. ca va lire la sortie du processus_pere qui est ret (fd[0]<->STDIN_FILENO juste avant) ;;AVECCAON peut appeler system sur cmd qui va lire depuis stdin qui vaudra fd[0] PRECEDENT __rslt(ret de type char*)(()) et le linker avec le stdout (dup2(fd[1],stdout));JUSTE AVANT apres on met un close(fd[1]) (dup2 a assure la copie independante) puis on fait un break puis saut vers label: return ret;(ret=system(cmd) en sortie car on a linké STDOUT_NOFILE/FILE_NO avec fd[1] => return $(__stdout);;
APRES:
on a appelle sur le fichier executable en char[] avec l'option -a pour qu'il copie a partir de la position 33 tout le fichier et lexecution de ce file.cpp va afficher (sdt::count << ?? << std::endl) la sortie standard de system(cmd) cad. la valeur ret retrouvee a l'appel 2 de fork()).
VOILA.
RESUME en ++++ DE TOUTES LES ETAPES REQUISES.
  */

  //rq: system(cmd) va faire ./cmd avec remplacement de cmd par le path et ajout
  //""pas_present_ecriture_brute de l'option du coup va se deplacer vers /usr/bin et executer ./lsb_release -a et la mettre dans la valeur retournee ret.
  /*
rq2:
il faut preserver ces valeurs en sorties du systeme:
=>=>3 fois ::::  dup2(STDIN/STDOUT/STDERR _FILENO,old_fd[0<=i<2]) avant logiquement le 'return "$ret"'./////
  */
  do{
  printf("%c",*p2);
  }while(*p2++);
  
  
  return 0;
}


