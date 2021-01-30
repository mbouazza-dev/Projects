CFLAGS=-ansi -pedantic -Wall
LDFLAGS=-lMLV -lm
CC=gcc
OPT=-02
OBJ= gfx.o main.o player.o shoot.o foe.o menu.o sound.o


projectstars: $(OBJ)
	$(CC) -o $@ $^ -g $(CFLAGS) $(LDFLAGS)
	
install: projectstars
	mkdir bin
	mv projectstars bin/projectstars
	make mrproper

uninstall: mrproper
	rm -f bin/projectstars
	rm -rf bin


main.o: src/main.c includes/gfx.h includes/player.h includes/shoot.h includes/foe.h includes/menu.h includes/sound.h
	gcc -c src/main.c src/gfx.c src/player.c src/shoot.c src/foe.c $(LDFLAGS)

menu.o: src/menu.c includes/menu.h includes/gfx.h includes/menu.h
	gcc -c src/menu.c $(LDFLAGS)

gfx.o: src/gfx.c includes/gfx.h includes/player.h
	gcc -c src/gfx.c src/player.c $(LDFLAGS)

shoot.o: src/shoot.c includes/shoot.h includes/player.h includes/sound.h
	gcc -c src/shoot.c src/player.c $(LDFLAGS)

player.o: src/player.c includes/player.h
	gcc -c src/player.c $(LDFLAGS)

foe.o: src/foe.c includes/foe.h includes/player.h
	gcc -c src/foe.c $(LDFLAGS) 

sound.o: src/sound.c includes/sound.h
	gcc -c src/sound.c $(LDFLAGS) 

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean: 
	rm -rf *.o

mrproper: clean
	rm -f projectstars