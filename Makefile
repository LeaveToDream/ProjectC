
c-bin/main : c-bin c-out/main.o c-out/board.o c-out/game.o c-out/find.o c-out/getLine.o
	gcc -Wall -o c-bin/main c-out/*

c-out/main.o : c-out c-src/main.c
	gcc -Wall -c c-src/main.c  -o c-out/main.o

c-out/board.o : c-out c-src/board.c
	gcc -Wall -c c-src/board.c -o c-out/board.o

c-out/game.o : c-out c-src/game.c
	gcc -Wall -c c-src/game.c -o c-out/game.o

c-out/find.o : c-out c-src/find.c
	gcc -Wall -c c-src/find.c -o c-out/find.o

c-out/getLine.o : c-out c-src/getLine.c
	gcc -Wall -c c-src/getLine.c -o c-out/getLine.o

clean :
	rm c-out/* -f

testUI : c-out/gui.o
	gcc -Wall -o c-bin/UI c-out/gui.o -lSDL2

c-out/gui.o : c-src/gui.c
	gcc -Wall -c c-src/gui.c -o c-out/gui.o

c-bin : 
	mkdir c-bin

c-out :
	mkdir c-out
