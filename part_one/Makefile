F1=-std=c99
F2=-felf64
F3=--std=c++11
#Sur mon système, il y a quatre fichiers lisibles par l'utilisateur contenant des vidages hexadécimaux d'informations de périphérique; deux d'entre eux sont tous des zéros, deux autres contiennent des informations sur le disque et le DVD; Le DVD n'a pas de numéro de série et la série de disques commence à l'offset 0x20.
all: courbe_caches__MEMOIRE
frequence_donnee_actuelle: frq.sh #donne la frequence du coeur principale
#coeur 0 du cpu en cours.(qui peut agmenter legerement en cas de travail
#prolonge et sur les memes trucs)
	./frq.sh && cat file3.txt && rm file3.txt
qst1.o: qst1.s
	yasm $(F2) qst1.s
qst: qst1.o qst2.c
	gcc $(F1) qst1.o qst2.c -o qst
qst_exec: qst
	./qst #target|1 __final=> nombre de ticks du microprocesseur +
#debit en Mo/s (taille_donnees/(nbr_cycles/f)). n1<<N
qst3.o: qst3.s
	yasm $(F2) qst3.s
qst1: qst3.o qst4.c
	gcc $(F1) qst3.o qst4.c -o qst1
qst5.o: qst5.s
	yasm $(F2) qst5.s
qst2: qst5.o qst4.c
	gcc $(F1) qst5.o qst4.c -o qst2
qst_exec2: qst1 qst2
	./qst1 && ./qst2
#target|2 __final=> comparaison entre les timings et les debits ENTRE:
#un deroulement en 4/8 par rapport a aucun deroulement.(target [1])
qst_avance_methode1: qst7.s qst6.c
	yasm -felf64 qst7.s
	gcc -std=c99 qst7.o qst6.c -o qst_avance_methode1
qst_avance_methode2_TOP: qst7.s qst8.c
	yasm -felf64 qst7.s
	gcc -std=c99 qst7.o qst8.c -o qst_avance_methode2_TOP
qst_avance_exec1: qst_avance_methode1
	./qst_avance_methode1 #met en evidence l'existence des unites de
#memoire caches facilitant les manipulations.
qst_avance_exec2: qst_avance_methode2_TOP
	./qst_avance_methode2_TOP #de meme mais moins en details
#(voir resume)
fichier_depart_pyplot: qst_avance_exec2
	./qst_avance_methode2_TOP > timing.dat && rm qst_avance_methode2_TOP
a_reproduire:
	rm timing.dat && rm timing.pdf 
courbe_caches__MEMOIRE: fichier_depart_pyplot
	./passage.sh timing #avant: chargement en memoire de timing.dat
infos_caches: nbr_caches.sh
	./nbr_caches.sh
	less file2.txt
tout_infos_cpu: donnees_CPU_architecture__interne.sh
	./donnees_CPU_architecture__interne.sh
	gedit file_infos.txt &
tout_infos_cpu2: donnees_CPU_architecture__interne.sh
	./donnees_CPU_architecture__interne.sh && cat file_infos.txt
test_fork_tube_dup2: test.c test2.c
	gcc $(F1) test.c -o test  && gcc $(F1) test2.c -o test1
	./test && ./test1
configuration_manuelle_superficielle: eleve.cpp
	g++ --std=c++11 eleve.cpp -o infos_base_superficie
	./infos_base_superficie
ID_vendor_and__max_instructions_pour_cpuid: renseignements_basales_plus.cpp
	g++ $(F3) renseignements_basales_plus.cpp -o infos_cpuid_normaux && ./infos_cpuid_normaux
NOTSHORT__numero_serie_disque_dur_OU_ssd__comme_usb_donnees_numeriques: numero_de_serie.c
	gcc numero_de_serie.c -ludev -o sn
	./sn
short_serial_hard_disk_number: serie_number.sh
	 ./serie_number.sh -ludev
plus_avancement_cpp___aussi: tout_infos_cpu2 configuration_manuelle_superficielle ID_vendor_and__max_instructions_pour_cpuid NOTSHORT__numero_serie_disque_dur_OU_ssd__comme_usb_donnees_numeriques
plus_avancement_cpp___aussi_SHORT___mode: tout_infos_cpu2 configuration_manuelle_superficielle ID_vendor_and__max_instructions_pour_cpuid short_serial_hard_disk_number
numero_de_serie_DIRECT:
	udevadm info --query=all --name=/dev/sda | grep ID_SERIAL
numero_de_serie_short_meme_precedemment: serie_number_autre.sh
	./serie_number_autre.sh
#on dispose de targets qui permettent en plus de:(4 choses)
#1->nbr_cores/nom_modele_machine(intel(r) core(tm) i5-8250U CPU @ 1.60GHz)/f_moy--~/basale execution specifique VARIABLE) 's/$"2"<< plus precisement du CPU
#cerveau de la machine(CENTRAL PROCESSS UNIT(2 unites: de controle et de traitement)).
#2->Codename(bionic/. ->a partir de la 18.04LTS pour rendre plus rentable
#les acces systeme la gestion des dependances de paquets (dpkg) ++l'installation de mises a jour && release;description_TOTALE;--ajout de lts ou non--(pas de date d'expiration de la validite professionnelle grande mondiale de la version lts) (&en +=>description ID (--)).
#3->Max instruction ID(max(*(eax) lors des acces aux infos via cpuid)) && :>>
#Vendor.name() // Vendor.ID() : le premier c'est commercial (Genuine Intel)
#le deuxieme il l'englobe (entreprise a caractere technologique ouverte et financiere: Intel).
#4->numero de serie unique du disque dur de cette machine:/; >>>>
#rappel: structure deBASE:: CPU<->memoire<->HARD_DISK les caches sont entre cpu et memoire 'valeur--' et les peripheriques nn avec le SO la couche qui gere tt ca.
#en resume: modele+nbr_coeurs+frequence__normale
#&& pour 2: Codename(bionic);release,description(--LTS--(presence ou non)),descriptor id( UBUNTU).
#&& pour 3: Max__eax(pour___cpuid|grep $"i" i variant..(indirections)) +
#Vendor.name=Genuine Intek ; Vendor.ID=Intel.
#&& pour 4: numero de serie UNIQUE DU disque dur.
clean:
	rm -f *.sh~ *.s~ *.c~ *.o a.out Makefile~ qst file1.txt file2.txt file.txt file3.txt '#Makefile#' qst_avance_methode1 qst_avance_methode2_TOP && rm -f Makefile~ timing.dat timing.pdf file_infos.txt *.cpp~ a.out a.txt cpuid cpuid2 test test1 infos_base_superficie infos_cpuid_normaux sn

