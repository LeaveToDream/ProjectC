#ifndef __GAME_NO_UI__
#define __GAME_NO_UI__

#include "../c-head/board.h"




int playAGame();
Status gamePvP(Board b);
Level getDifficulty();
Coord playerTurn(Board* b, Pawn side);
void rules();
char numberToLetter(int n);
int letterToNumber(char c);
bool inputIsAMove(char* input);
bool processInputToMove(char* input, int* x1, int* y1, int* x2, int* y2);

#endif
