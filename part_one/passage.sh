#!/usr/bin/gnuplot -persist
set log x
plot "timing.dat" w l
#l'avantage est de ne pas passer par les commandes depuis l'inventaire de
#GNUPLOT.
