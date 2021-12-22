#!/bin/bash
while read part
do
    echo $part > file1.txt
    grep 'cpu MHz' file1.txt > file2.txt
    retvalue=$?
    if [ "$retvalue" -eq 0 ];then
        export line=$part
	#echo $line
        echo $line | cut -d ":" -f2>file3.txt
    fi
done< /proc/cpuinfo
rm file1.txt
rm file2.txt
