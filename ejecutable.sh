#!/bin/bash
clear
bison -d gramatica.y 
flex gramatica.l
cc gramatica.tab.c -ly -lfl -lm
./a.out < programa.txt 
