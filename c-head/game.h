#ifndef __GAME__
#define __GAME__


typedef enum Status Status ;

enum Status {Playing, Bot, WhitePlayer, BlackPlayer, Draw};

void playAGame();
Status gamePvP(Board b);
int playerTurn(Board b, Pawn side);
Status resolveGame(Board b);
bool resolveMove(Board b, Coord p);
void rules();
char numberToLetter(int n);
int letterToNumber(char c);
bool inputIsAMove(char* input);
bool processInputToMove(char* input, int* x1, int* y1, int* x2, int* y2);

#endif
