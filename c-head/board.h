#ifndef __BOARD__
#define __BOARD__
#include <stdbool.h>

typedef enum Pawn Pawn ;
typedef enum Level Level ;
typedef enum Status Status ;
typedef struct Board Board ;
typedef struct Coord Coord ;

enum Pawn {None, White, Black};
enum Level {ALONE=0, EASY=1, NORMAL=2, HARD=3};
enum Status {Playing, Bot, WhitePlayer, BlackPlayer, Draw, Quit, Exit};

struct Board {
    int length;
    int whiteCount;
    int blackCount;
    Pawn** board;
    Coord*** possibleMove;
};

struct Coord {
    int x,y;
};

Board initBoard();
Coord initCoord(int x, int y);
Pawn enemyPawn(Pawn p);
Board fillBoard(Board b);
Status resolveGame(Board* b);
bool resolveMove(Board* b, Coord p);
bool isInBoard(Board b, Coord c);
void possibleMove(Board b, Coord c);
bool isMovePossible(Board b, Coord p1, Coord p2);
bool movePawn(Board b, Coord p1, Coord p2);
void refreshPMAfterMove(Board b, Coord p);
bool removePawn(Board* b, Coord p);
void display(Board b);
Board copyBoard(Board b);
void freeBoard(Board b);
bool compareCoord(Coord c1, Coord c2);

#endif
