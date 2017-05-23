#ifndef PROJECTC_IA_H
#define PROJECTC_IA_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef enum {value, posInf, negInf} specialInt;

typedef struct infInt {
    specialInt type;
    int value;
} infInt;


int main(nt argc, char const *argv[]);
int negamaxAB_IA(Board B, specialInt A, specialInt B, int depth, int difficulty);
int moveValue(Board B);
int evaluatePawnPotential(Board B);
bool moveIA(Board* b, coord* x, coord* y);

#endif