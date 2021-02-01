CFLAGS=-ansi -g -pedantic -Wall -Wfatal-errors
LDFLAGS= -lm -lMLV
OBJ = utilitaire.o visite.o ville.o affichage.o mutation.o main.o
CC= gcc

pvc: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: main.c utilitaire.h visite.h ville.h affichage.h

utilitaire.o: utilitaire.c utilitaire.h visite.h

visite.o: visite.c visite.h ville.h

ville.o: ville.c ville.h

mutation.o: mutation.c mutation.h visite.h

affichage.o: affichage.c affichage.h ville.h

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o

mrproper: clean
	rm -f pvc
