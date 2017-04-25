
main : c-out/main.o c-out/board.o c-out/game.o c-out/find.o
	gcc -Wall -o c-bin/main c-out/main.o 

main.o : c-src/main.c
	gcc -Wall -c c-src/main.c -o c-out/main.o

board.o : c-src/board.c
	gcc -Wall -c c-src/board.c -o c-out/board.o

game.o : c-src/game.c
	gcc -Wall -c c-src/game.c -o c-out/game.o

find.o : c-src/find.c
	gcc -Wall -c c-src/find.c -o c-out/find.o


