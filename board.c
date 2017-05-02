#include <stdio.h>
#include <string.h>
#include <stdbool.h>


Board init(Level level){
  Board b;
  int n = (int) level;
  b.board = (double **) malloc(sizeof(double*)*n);
  for(int i = 0; i<n;i++){
    m.board[i]= (double *) malloc(sizeof(double)*n);
  }
  b.taille = n ;
  return b;
}

void fillBoard(Board b){
  for(int i = 0; i<2;i++){
    for(int j = 0; j<n;j++){
      m.board[i][j]= Noir;
    }
  }
  for(int i = 2; i<n-2;i++){
    for(int j = 0; j<n;j++){
      m.board[i][j]= None;
    }
  }
  for(int i = n-2; i<n;i++){
    for(int j = 0; j<n;j++){
      m.board[i][j]= Blanc;
    }
  }
}

bool isInBoard(Board b, Coord c){
  if(0 > c.x || c.x < b.taille){
    return false ;
  }
  if(0 > c.y || c.y < b.taille){
    return false ;
  }
  return true ;
}

Pion pionEnnemi(Pion p){
  if
}

Coord* possibleMove(Board b, Coord c){
  if(isInBoard(c)==false){
    return *NULL ;
  }
  Coord* possible[2*b.taille] ;
  int x, y;
  Pion p = b.board[x][y];
  Pion contreP = pionEnnemi(p)
  // Maintenant on test les quatres lignes, jusqu'a rencontrer un obstacle
  // Gauche
  x = c.x;
  y = c.y;
  while(isInBoard(x-1, y) && b.board[x-1][y]==None){
      x = x-1;
      //ajouterDans(possible, Coord(x,y));
  }
  // Droite
  x = c.x;
  y = c.y;
  while(isInBoard(x+1, y) && b.board[x+1][y]==None){
      x = x+1;
      //ajouterDans(possible, Coord(x,y));
  }
  // Haut
  x = c.x;
  y = c.y;
  while(isInBoard(x, y-1) && b.board[x][y-1]==None){
      y = y-1;
      //ajouterDans(possible, Coord(x,y));
  }
  // Bas
  x = c.x;
  y = c.y;
  while(isInBoard(x, y+1) && b.board[x][y-1]==None){
      y = y+1;
      //ajouterDans(possible, Coord(x,y));
  }
  // Si un pion est au contact
  if()
}


int isMovePossible(Board b, int x1, int y1, int x2, int y2){
    int isInBoardCount = isInBoard(x1,y1)+isInBoard(x2,y2);



  //4 possibilities of deplacement

}

int move(Board b, int x1, int y1, int x2, int y2){

}
int resolve(Board b, int x, int y);
int remove(Board b, int x, int y);
void afficher(Board b);
