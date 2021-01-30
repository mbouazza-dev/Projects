#!/bin/bash
prog=test/*.tpc

for file in test/valides/*
do
	printf "Fichier testé: %20s\n" $file
	./bin/compil < $file
	printf "\n"
done

for file in test/invalides/*
do
	printf "Fichier testé: %20s\n" $file
	./bin/compil < $file
	printf "\n"
done