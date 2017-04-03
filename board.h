#ifndef BOARD
#define BOARD

typedef enum Pion Pion ;
enum Pion {Blanc, Noir, None};

typedef enum Level Level ;
enum Level {EASY=7, NORMAL=9, HARDCORE=15};

typedef struct Board Board ;
struct Board {
  int taille;
  Pion** board;
};

typedef struct Coord Coord ;
struct Coord {
  int x,y;
};

int main();
Board init(Level level);
int[]* possibleMove(int x, int y);
int move(int x, int y);
int resolve(int x, int y);
int remove(int x, int y);

void afficher();

#endif
