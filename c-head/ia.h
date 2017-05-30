#ifndef PROJECTC_IA_H
#define PROJECTC_IA_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Move Move;

struct Move {
    Coord from;
    Coord to;
};

int negamaxAB_IA(Board B, specialInt A, specialInt B, int depth, int difficulty, Pawn couleur);
int evaluatePawnPotential(Board B);
int moveValue(Board B, Status s, int depth);
void initListPossibleMove(Move* listPossibleMove);
int generateListePossibleMove(Move* listPossibleMove, Board b, int* count, Pawn color);
Move initMove(Coord c1, Coord c2);

#endif