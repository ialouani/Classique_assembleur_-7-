#!/bin/bash
cp generique.c $4.c
echo "for(int $1=0;$1<N;$1++){" >>  $4.c
echo "for(int $2=0;$2<N;$2++){" >>  $4.c
echo "for(int $3=0;$3<N;$3++){" >>  $4.c
echo "C[i*N+j]=A[i*N+k]*B[k*N+j];}}}}" >> $4.c
