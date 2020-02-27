#!/bin/bash

f0=0
f1=1
echo ""
echo "Primeros 10 números de la sucesión de Fibonacci"
echo ""
echo ${0} ${f0}
echo ${1} ${f1}
for i in {2..9}
do
    fi=$((f0 + f1))
    echo ${i} ${fi}
    f0=$f1
    f1=$fi
done

f0=0
f1=1
echo ""
echo "Primeros 100 números de la sucesión de Fibonacci"
echo ""
echo ${0} ${f0}
echo ${1} ${f1}
for i in {2..99}
do
    fi=$(bc <<< "${f0} + ${f1}")
    echo ${i} ${fi}
    f0=$f1
    f1=$fi
done

f0=0
f1=1
echo ""
echo "Primeros 1000 números de la sucesión de Fibonacci"
echo ""
echo ${0} ${f0}
echo ${1} ${f1}
for i in {2..999}
do
    fi=$(bc <<< "${f0} + ${f1}")
    echo ${i} ${fi}
    f0=$f1
    f1=$fi
done
