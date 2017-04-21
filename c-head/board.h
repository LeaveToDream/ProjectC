#ifndef __BOARD__
#define __BOARD__

typedef enum Pawn Pawn ;
typedef enum Level Level ;
typedef struct Board Board ;
typedef struct Coord Coord ;

enum Pawn {None, White, Black};
enum Level {EASY=7, NORMAL=9, HARDCORE=15};

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

Board initBoard(Level level);
Coord initCoord(int x, int y);
Pawn enemyPawn(Pawn p);
Board fillBoard(Board b);
bool isInBoard(Board b, Coord c);
void possibleMove(Board b, Coord c);
bool isMovePossible(Board b, Coord p1, Coord p2);
bool movePawn(Board b, Coord p1, Coord p2);
void refreshPMAfterMove(Board b, Coord p);
bool removePawn(Board b, Coord p);
void display(Board b);
void freeBoard(Board b);


#endif
