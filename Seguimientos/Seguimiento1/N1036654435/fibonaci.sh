#! /bin/bash

a=0 && b=1 && c=0 && N=10
for ((i=0; i<N; i++)); do echo $a ; c=$((a+b)) ; a=$b ; b=$c; done
echo " ---- Fin 10 iteraciones ---- "
a=0 && b=1 && c=0 && N=100
for ((i=0; i<N; i++)); do echo $a ; c=$((a+b)) ; a=$b ; b=$c; done
echo " ---- Fin 100 iteraciones ---- "
a=0 && b=1 && c=0 && N=1000
for ((i=0; i<N; i++)); do echo $a ; c=$((a+b)) ; a=$b ; b=$c; done
echo " ---- Fin 1000 iteraciones ---- "

echo " Notamos que a partir de la 93 iteración, la computadora empieza a realizar cálculos extraños, donde aparecen números negativos"
