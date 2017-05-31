#ifndef PROJECTC_IA_H
#define PROJECTC_IA_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "board.h"

typedef struct Move Move;
typedef struct ValuedMove ValuedMove;

struct Move {
    Coord from;
    Coord to;
};

int evaluatePawnPotential(Board B);

struct ValuedMove {
    int value;
    Move move;
};

ValuedMove negamaxAB_IA(Board b, int A, int B, int depth, int difficulty, Pawn color, Move lastMove);

int moveValue(Board B, Status s, int depth);
void initListPossibleMove(Move* listPossibleMove);
int generateListePossibleMove(Move* listPossibleMove, Board b, Pawn color);
Move initMove(Coord c1, Coord c2);
ValuedMove initValuedMove(int value, Move move);

#endif
