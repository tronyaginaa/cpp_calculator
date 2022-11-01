#!/bin/bash

g++ -c -o exp.o exp.cpp
gcc -shared -o libexp.so exp.o

g++ -c -o sin.o sin.cpp
gcc -shared -o libsin.so sin.o

g++ -c -o cos.o cos.cpp
gcc -shared -o libcos.so cos.o

g++ -c -o sqrt.o sqrt.cpp
gcc -shared -o libsqrt.so sqrt.o
