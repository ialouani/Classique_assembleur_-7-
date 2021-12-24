#!/bin/bash
gcc numero_de_serie.c $1 -o sn
./sn | awk -F "Serial ID:" '{print $2}' | awk -F "_" '{print $6}' > file1.txt
export identifiant=$(sed -n '1p' file1.txt)
echo "E: ID_serial__SHORT:==    $identifiant" 
