#ifndef BOARD
#define BOARD

typedef enum Pion Pion ;
typedef enum Level Level ;
typedef enum Status Status ;
typedef struct Board Board ;
typedef struct Coord Coord ;

enum Pion {None, White, Black};
enum Level {EASY=7, NORMAL=9, HARDCORE=15};
enum Status {Playing, White, Black, Draw}

struct Board {
  int length;
  Pion** board;
  Coord*** possibleMove;
};

struct Coord {
  int x,y;
};

Board init(Level level);
Coord initCoord(int x, int y);
void fillBoard(Board b);
bool isInBoard(Board b, Coord c);
void possibleMove(Board b, Coord c);
bool isMovePossible(Board b, Coord p1, Coord p2);
bool movePawn(Board b, Coord p1, Coord p2);
void refreshPMAfterMove(Board b, Coord p);
bool resolveMove(Board b, Coord p);
bool removePawn(Board b, Coord p);
void display(Board b);
void freeBoard(Board b);
void rules();


#endif
