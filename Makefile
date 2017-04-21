
main : main.o
	gcc -Wall -o c-bin/main c-out/main.o 

main.o : c-src/main.c c-head/main.h c-src/game.c c-head/game.h
	gcc -Wall -c c-src/main.c -o c-out/main.o

board.o : c-src/board.c c-head/board.h c-src/game.c c-head/game.h
	gcc -Wall -c c-src/board.c -o c-out/board.o

game.o : c-src/board.c c-head/board.h c-src/game.c c-head/game.h find.c c-head/find.h
	gcc -Wall -c c-src/game.c -o c-out/game.o

find.o : c-src/find.c c-head/find.h c-src/board.c c-head/board.h c-src/game.c c-head/game.h
	gcc -Wall -c c-src/find.c -o c-out/find.o


