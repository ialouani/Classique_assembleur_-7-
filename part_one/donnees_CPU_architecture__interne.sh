#!/bin/bash
#nbr_coeurs.
#PUIS: nom du modèle complet.
#PUIS FINALEMENT: la fréquence hertzienne du CPU de ce modele. 
info1=$(cat /proc/cpuinfo | grep -i "^processor" | wc -l)
info2=$(cat /proc/cpuinfo | grep -i "^model name" | awk -F": " '{print $2}' | head -1 | sed 's/\+//g')
info3=$(cat /proc/cpuinfo | grep "^cpu MHz" | awk -F": " '{print $2}' | head -1)
touch file_infos.txt
echo -e "Ce processus travaille et ce travail se fait en collaboration avec $info1 cores.\n\n\n\n" > file_infos.txt
echo -e "Cette machine a pour modele (modele de machine signifie l'entreprise qui a fabrique le microprocesseur (ss_type) + ss_type (Core(coeur principale et surtout liaisons(en lien avec les performances))) + i3/5/7/9 (~ 'alpha'à la puissance hertzienne globale) - marque(nombre<+|//) + CPU (mot dur (telquel)) de meme pour les deux +?'?' suivants: @ ; frequence moyenne pas basale.. EST:\n\n\n\t\t\t$info2.\n\n\n\n" >> file_infos.txt
echo -e "Sa fréquence de travail performante nominale en cours (actuellement###&..) est:\n\t\t\t$info3 MHz." >> file_infos.txt
