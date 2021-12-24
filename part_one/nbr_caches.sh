#!/bin/bash
cat /proc/cpuinfo | grep 'cache size' | cut -d ":" -f2 > file.txt
#La taille de chaque cache (cache<->processeur<->memoire).
#Ou bien suivant ce shema suivant:
#CPU(central process unit) <-> cache <-> memoire.
#le nombre de caches va etre celui des coeurs car dans ces machines de 2000,
#chaque processeur est relié a son propre cache.
n=0
while read part
do
    if [ ! -z "$part" ];then
	if [ $n == 0 ];then
	    echo "cache $((n+1)) a la taille approximative: $part">file2.txt
	    ((n=n+1))
	else
	    echo "cache $((n+1)) a la taille approximative: $part">>file2.txt
      	    ((n=n+1))
	fi
    fi
done<file.txt
#FILE2.TXT est le fichier majeur.
#Autre methode plus simple nous invitant a reviser les premieres commandes.
number=$(cat /proc/cpuinfo | grep 'cache size' | cut -d ":" -f2 | wc -l)
#CAR MEME $n en echo donnera la valeur du nombre de caches presents.
#taille approximative: 6MB.(B=Byte=octet=8bits)
echo "Le nombre de caches pour ce MICROprocesseur est: $number." >> file2.txt
