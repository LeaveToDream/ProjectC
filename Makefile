
c-bin/main : c-bin c-out/main.o c-out/board.o c-out/gameNoUI.o c-out/gui.o c-out/gameUI.o c-out/find.o c-out/getLine.o c-out/rules.o c-out/menu.o c-out/ia.o
	gcc -Wall -o c-bin/play c-out/* -lSDL2 -lSDL2_image

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

c-out/menu.o : c-src/menu.c
	gcc -Wall -c c-src/menu.c -o c-out/menu.o

c-out/rules.o : c-src/rules.c
	gcc -Wall -c c-src/rules.c -o c-out/rules.o

c-out/ia.o : c-src/ia.c
	gcc -Wall -c c-src/ia.c -o c-out/ia.o

clean :
	rm c-out/* -f
	rm c-bin/* -f

c-bin :
	mkdir c-bin

c-out :
	mkdir c-out
