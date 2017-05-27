
c-bin/main : c-bin c-out/main.o c-out/board.o c-out/gameNoUI.o c-out/gameUI.o c-out/find.o c-out/getLine.o
	gcc -Wall -o c-bin/main c-out/* -lSDL2

c-out/main.o : c-out c-src/main.c
	gcc -Wall -c c-src/main.c  -o c-out/main.o

c-out/board.o : c-out c-src/board.c
	gcc -Wall -c c-src/board.c -o c-out/board.o

c-out/gameNoUI.o : c-out c-src/gameNoUI.c
	gcc -Wall -c c-src/gameNoUI.c -o c-out/gameNoUI.o

c-out/gameUI.o : c-out c-src/gameUI.c
	gcc -Wall -c c-src/gameUI.c -o c-out/gameUI.o

c-out/find.o : c-out c-src/find.c
	gcc -Wall -c c-src/find.c -o c-out/find.o

c-out/getLine.o : c-out c-src/getLine.c
	gcc -Wall -c c-src/getLine.c -o c-out/getLine.o

c-out/gui.o : c-src/gui.c
	gcc -Wall -c c-src/gui.c -o c-out/gui.o

clean :
	rm c-out/* -f

c-bin :
	mkdir c-bin

c-out :
	mkdir c-out
