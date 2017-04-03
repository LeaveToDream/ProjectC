
main : main.o
	gcc -Wall -o main main.o

main.o : main.c main.h
	gcc -Wall -c main.c
