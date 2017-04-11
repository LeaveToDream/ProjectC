
main : main.o
	gcc -Wall -o main main.o

main.o : main.c main.h
	gcc -Wall -c main.c

test : board.o
	gcc -Wall -o test test.o

test.o : board.c board.h
	gcc -Wall -c board.c -o test.o
