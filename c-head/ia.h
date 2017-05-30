#ifndef PROJECTC_IA_H
#define PROJECTC_IA_H

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "board.h"

typedef struct Move Move;
<<<<<<< HEAD
=======
typedef struct ValuedMove ValuedMove;
>>>>>>> fdc9416ac6735158f588b8710a3e0b05b53d11d2

struct Move {
    Coord from;
    Coord to;
};

<<<<<<< HEAD
int negamaxAB_IA(Board B, specialInt A, specialInt B, int depth, int difficulty, Pawn couleur);
int evaluatePawnPotential(Board B);
=======
struct ValuedMove {
    int value;
    Move move;
};

ValuedMove negamaxAB_IA(Board b, int A, int B, int depth, int difficulty, Pawn color, Move lastMove);
>>>>>>> fdc9416ac6735158f588b8710a3e0b05b53d11d2
int moveValue(Board B, Status s, int depth);
void initListPossibleMove(Move* listPossibleMove);
int generateListePossibleMove(Move* listPossibleMove, Board b, int* count, Pawn color);
Move initMove(Coord c1, Coord c2);
<<<<<<< HEAD
=======
ValuedMove initValuedMove(int value, Move move);
>>>>>>> fdc9416ac6735158f588b8710a3e0b05b53d11d2

#endif