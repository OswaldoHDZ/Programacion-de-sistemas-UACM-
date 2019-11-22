#!/bin/bash
# compilar bison & flex
clear
bison -d gramatica_python.y
flex gramatica_python.l
cc gramatica_python.tab.c -ly -lfl -lm
./a.out < programa.txt
