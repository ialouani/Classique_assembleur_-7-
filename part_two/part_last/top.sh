#!/bin/bash
gcc -std=c99 file_cible.c -o fc1
( time ./fc1 0 ) >> file1.txt 2>&1 
gcc -std=c99 file_cible.c -o fc2
( time ./fc1 1 ) >> file1.txt 2>&1
