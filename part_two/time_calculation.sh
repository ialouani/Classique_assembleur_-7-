#!/bin/bash
gcc -std=c99 $1.c -o time_i
( time ./time_i ) > fichier.txt 2>&1
cat fichier.txt
