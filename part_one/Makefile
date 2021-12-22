F1=-std=c99
F2=-felf64
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


clean:
	rm -f *.sh~ *.s~ *.c~ *.o a.out Makefile~ qst file1.txt file2.txt file.txt file3.txt '#Makefile#' qst_avance_methode1 qst_avance_methode2_TOP && rm -f Makefile~ timing.dat timing.pdf

