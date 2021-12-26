#!/bin/bash
#creation d'un file adpate a GNUPLOT.
#BUT DUSCRIPT: courbe representative.
#generation de fichiers.
make test #creation des fichiers cible --.
touch all_timing
declare -a List=(test_1.c test_2.c test_3.c test_4.c test_5.c test_6.c)
export cpt=1 #usage large !portée (non ici)
for i in ${List[@]} #ou bien for j in ${LIST[*]}.
do
	 #$@ liste des arguments et $#==Length($@)
    #echo $i (s'assurer du bon FILE)
    touch file.txt #(comment_~dernier ne marche plus)
    gcc -std=c99 $i -o time_i
    #compilation en time_i (objet executable)
    ( time ./time_i ) > fichier.txt 2>&1 #real,user,sys le tout en fichier.txt
    export line_j=$(tail -3 fichier.txt) && echo $line_j >> file.txt
    #il nous faut un fichier pour faire un cat avec sortie dans le process
    #awk(..///) => echo $(tail -3 fichier.txt) > file.txt
    #regrouper en une seule ligne depuis la fin en ordonnant les lignes de
    #fichier.txt.((avec sortie (rslt((qui est la ligne en question)) sur file.txt)))
    cat file.txt | awk -F " " '{print $2}' >> all_timing
    #on affiche depuis le separateur espace le 2ieme 'separe'(~~char ()).
    #>> pour eviter un > en premier puis un >> pour les autres suivants.
    rm fichier.txt && rm file.txt #surtout pour file..///
    ((cpt=cpt+1))
done
cpt2=1
mv all_timing all_timing.dat
touch all_timing3.dat
while read part
do
    echo $part $cpt2 >> all_timing2.dat #ajout sur chaque ligne ->FORMAT::   .. nbr. 
    echo $part | awk -F "m" '{print $2}' >> all_timing3.dat #contiendra v_?;;:s nbr.
    ((cpt2=cpt2+1))
done<all_timing.dat
cpt3=1
while read part2
do
    echo $cpt3 $part2 >> all_timing4.dat
    ((cpt3=cpt3+1))
done<all_timing3.dat


