F=-std=c99
#combinaisons des i,j,k possibles:
#i,j,k | i,k,j | j,i,k | j,k,i | k,i,j | k,j,i (6 possibles)((3!))
all:t__s
test: test1 test2 test3 test4 test5 test6  #creation depuis generique.c
test1: generique.c loop_ordre.sh
	./loop_ordre.sh i j k test_1 #creation du fichier test_1.c
#avec le bon ordre dans les boucles.
#il faudrait un code dechiffrable tel que:
#(binaire!(mieux!!!)) telque suite_de__binaires=>ordre: (i,j,k).
#sur 3 bits on a 8 possibilites.
#FACILE: 1->test1 ..(\forall{i}: i<->testi)
test2: generique.c loop_ordre.sh
	./loop_ordre.sh i k j test_2
test3: generique.c loop_ordre.sh
	./loop_ordre.sh j i k test_3
test4: generique.c loop_ordre.sh
	./loop_ordre.sh j k i test_4
test5: generique.c loop_ordre.sh
	./loop_ordre.sh k i j test_5
test6: generique.c loop_ordre.sh
	./loop_ordre.sh k j i test_6
t__s: t1 t2 t3 t4 t5 t6 #remplir fichier.txt par la valeur de retour de time .o+.
t1: test1
	./time_calculation.sh  test_1 #afficher le timing relatif
#a test_1.c en execution par exemple
#=>compilation en time_i puis ( time ./time_1 ) > file1.txt 2>&1
#=>cat file1.txt.(apres un > va re-ecrire sur le fichier (donc apres l'avoir ECR
#ASE).
t2: test2
	./time_calculation.sh  test_2
t3: test3
	./time_calculation.sh  test_3
t4: test4
	./time_calculation.sh  test_4
t5: test5
	./time_calculation.sh  test_5
t6: test6
	./time_calculation.sh  test_6
#on voudrait un fichier qui contiendrait plus..
#=>all_timing4.dat. VOILA
suite_valeurs_codage_adaptation_plusplus: top.sh #creation ensemble rslts.
	./top.sh #creation de all_timing4.dat
	cat all_timing4.dat
affichage_temps_en__fonctionde___ordre: top.sh afficher.sh
#((top.sh pour afficher sans pouvoir creer le fichier all_timing4.dat
#independamment.)) pas des .o ...     (compilation separee CAR<<<<)
	./top.sh
	./afficher.sh
#s(chiffrer-1(code_chacun)). AVEC: s prenant le code et donnant i,j,k --ordre.
clean:
	rm -f test_1.c test_2.c test_3.c test_4.c test_5.c test_6.c '#Makefile#' Makefile~ *.sh~ *.c~ *.cpp~ *.o~ time_i all_timing all_timing.dat all_timing2.dat all_timing3.dat all_timing4.dat
#fichier.txt deja bien traite (en RM) dans le script.
#file aussi (!!)./////
