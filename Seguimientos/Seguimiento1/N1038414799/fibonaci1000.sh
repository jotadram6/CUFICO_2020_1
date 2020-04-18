#!/bin/bash

a=0 && b=1; echo ${a}; echo ${b}; for i in  {1..998}; do d=$((a+b)) && echo ${d} ;a=${b} && b=${d}; done;
