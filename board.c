#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "board.h"



int main(int argc, char const *argv[]) {
  /* code */
  Level level = NORMAL ;
  printf("Hello Sir. \nSo you want to play Hasami Shogi.\n Here are the rules:\n");
  rules();
  printf("The difficulty is set to %s", level);
  Board b = init(level);
  Status state ;
  bool whitePlay, blackPlay, move ;
  char* location, target ;
  Coord locationCoord, targetCoord ;
  printf("White pawns move first. Let the game begin.");
  while(state==Playing){
    whitePlay = false ;
    blackPlay = false ;
    char* input;
    //White player plays
    printf("White player turn\nYour move :\n");
    while(!whitePlay){
      scanf(">>>%s\n", input);

      // Some process to determine wheiter the player wants to play, pass,
      // display the rules, or i don't know what else
      if(itsAMove){
        //apply regex "([A-Z]{1})([0-9]{1-2}) to ([A-Z]{1})([0-9]{1-2})"
        location = parser[1]+parser[2];
        target = parser[3]+parser[4];
        locationCoord = initCoord(letterToInt(parser[1]), parser[2]);
        targetCoord = initCoord(letterToInt(parser[3]), parser[4]);
        move = movePawn(b, locationCoord, targetCoord);
        if(move){
          resolveMove(b, locationCoord, targetCoord);
          whitePlay = true ;
          passCount = 0 ;
          printf("Here is the board : \n");
          display(b);
        } else {
          printf("Invalid play, can't go from %s to %s. Please try again\n", location, target);
        }
      } elseif(itsAPass) {
        whitePlay = true ;
        passCount++;
      } elseif(itsARule) {
        rules() ;
      } else {
        printf("Invalid command. Please try again.\n");
      }

      //
    }
    //Black player plays
    printf("Black player turn\nYour move :\n");
    while(!blackPlay){


    }

    // Resolving
    if(passCount >= 2){
      state = Draw ;
    } else {
      state = resolveGame()
    }
  }
  fillBoard(b);
  display(b);
  freeBoard(b);
  printf("Done\n");
  return 0;
}



Board init(Level level){
  Board b;
  int n = (int) level;
  // Preparing pawn board
  b.board = (Pion **) malloc(sizeof(Pion*)*n);
  for(int i = 0; i<n;i++){
    b.board[i]= (Pion *) malloc(sizeof(Pion)*n);
  }
  // Preparing possibleMove board
  b.possibleMove = (Coord ***) malloc(sizeof(Coord**)*n);
  for(int i = 0; i<n;i++){
    b.possibleMove[i]= (Coord **) malloc(sizeof(Coord*)*n);
    for (int j = 0; j < n; j++) {
      b.possibleMove[i][j]= (Coord *) malloc(sizeof(Coord)*2*n);
    }
  }


  b.length = n ;
  return b;
}

Coord initCoord(int x, int y){
  // TODO malloc qq chose et renvoyer l'objet ?
  struct Coord p = {x,y};
  return p ;
}

Coord* initCoordP(int x, int y){
  struct Coord* p = (Coord*) malloc(sizeof(Coord));
  p->x=x;
  p->y=y;
  return p ;
}
void fillBoard(Board b){
  int n = b.length ;
  int blackCount = 0, whiteCount = 0 , noneCount = 0 ;
  int i ;
  for(i = 0; i<2;i++){
    for(int j = 0; j<n;j++){
      b.board[i][j]= Black;
      blackCount++;
    }
  }
  for(int j = 0; j < n; j++) {
    possibleMove(b, initCoord(i,j));
    // the board, and coordinate of the pawn to process
  }
  for(i = 2; i<n-2;i++){
    for(int j = 0; j<n;j++){
      b.board[i][j]= None;
      noneCount++;
    }
  }
  for(int j = 0; j < n; j++) {
    possibleMove(b, initCoord(i,j));
    // the board, and coordinate of the pawn to process
  }
  for(i = n-2; i<n;i++){
    for(int j = 0; j<n;j++){
      b.board[i][j]= White;
      whiteCount++;
    }
  }
  //printf("Recap : white pawn count = %d, black pawn count = %d, empty cells = %d. \n", whiteCount, blackCount, noneCount);
}

bool isInBoard(Board b, Coord c){
  if(0 > c.x || c.x < b.length){
    return false ;
  }
  if(0 > c.y || c.y < b.length){
    return false ;
  }
  return true ;
}

Pion enemyPawn(Pion p){
  switch (p) {
    case White:
      return Black;
    case Black :
      return White;
    default :
      return None;
  }
}

void possibleMove(Board b, Coord c){
  if(isInBoard(b,c)==false){
    return ;
  }
  for (int i = 0; i < (b.length)*2; i++) {
    if((b.possibleMove[c.x][c.y][i]).x!=-1){
      //free(b.possibleMove[c.x][c.y][i]);
      b.possibleMove[c.x][c.y][i]=initCoord(-1,-1);
    }
  }
  int x, y, i=0;
  Pion p = b.board[c.x][c.y];
  Pion enemy = enemyPawn(p);
  // Maintenant on test les quatres lignes, jusqu'a rencontrer un obstacle
  // Gauche
  x = c.x;
  y = c.y;
  while(isInBoard(b, initCoord(x-1, y)) && b.board[x-1][y]==None){
      x = x-1;
      b.possibleMove[c.x][c.y][i]=initCoord(x,y);
      i++;
      //ajouterDans(possible, Coord(x,y));
  }
  // Droite
  x = c.x;
  while(isInBoard(b, initCoord(x+1, y)) && b.board[x+1][y]==None){
      x = x+1;
      b.possibleMove[c.x][c.y][i]=initCoord(x,y);
      i++;
      //ajouterDans(possible, Coord(x,y));
  }
  // Haut
  x = c.x;
  while(isInBoard(b, initCoord(x, y-1)) && b.board[x][y-1]==None){
      y = y-1;
      b.possibleMove[c.x][c.y][i]=initCoord(x,y);
      i++;
      //ajouterDans(possible, Coord(x,y));
  }
  // Bas
  y = c.y;
  while(isInBoard(b, initCoord(x, y+1)) && b.board[x][y-1]==None){
      y = y+1;
      b.possibleMove[c.x][c.y][i]=initCoord(x,y);
      i++;
  }
  // Si un pion est au contact
  y = c.y;

  // Hidari
  if(b.board[x-1][y]==enemy){ // Tobiutsuru ga dekiru
    b.possibleMove[c.x][c.y][i]=initCoord(x-2,y);
    i++;
  }
  // Migi
  if(b.board[x+1][y]==enemy){ // On peut sauter au dessus
    b.possibleMove[c.x][c.y][i]=initCoord(x+2,y);
    i++;
  }
  // Ué
  if(b.board[x][y-1]==enemy){ // On peut sauter au dessus
    b.possibleMove[c.x][c.y][i]=initCoord(x,y-2);
    i++;
  }
  // Shita
  if(b.board[x][y+1]==enemy){ // On peut sauter au dessus
    b.possibleMove[c.x][c.y][i]=initCoord(x,y+2);
    i++;
  }
  // Dab
}


bool isMovePossible(Board b, Coord p1, Coord p2){
    if(!(isInBoard(b,p1)||isInBoard(b,p2))){
      return false ;
    }
    for (int i = 0; i < (b.length)*2; i++) {
      if((b.possibleMove[p1.x][p1.y][i]).x==p2.x && (b.possibleMove[p1.x][p1.y][i]).y==p2.y){
        return true ;
      }
    }
    return false ;
}

bool movePawn(Board b, Coord p1, Coord p2){
  if(isMovePossible(b,p1,p2)){
    b.board[p2.x][p2.y]=b.board[p1.x][p1.y];
    b.board[p1.x][p1.y]=None;
    refreshPMAfterMove(b,p1); // Refresh every case around departure location
    refreshPMAfterMove(b,p2); // And arrivance location.
    // We do stricly 4n checks, whereas 3n-2 are mandatory, due to the fact
    // that pawns move in straigth line.
    return true ;
  } else {
    // OMG WTF BBQ
    return false ;
  }
}

void refreshPMAfterMove(Board b, Coord p){
  for (int i = 0; i < b.length; i++) {
    // We realize one horizontal & one vertical check around pawn p.
    possibleMove(b,initCoord(p.x, i));
    possibleMove(b,initCoord(i, p.y));
  }
  // Dab
}
bool resolveMove(Board b, Coord p){
  return false ;
}
bool removePawn(Board b, Coord p){
  if(b.board[p.x][p.y]!=None){
    b.board[p.x][p.y]=None;
    return true;
  }
  return false ;
}
void display(Board b){
  char none = '.', black = 'b', white = 'w';

  for(int i = 0; i<b.length;i++){
    for (int j = 0; j <b.length; j++) {

      switch (b.board[i][j]) {
        case Black:
          printf("%c ", black);
          break;
        case White:
          printf("%c ", white);
          break;
        default:
          printf("%c ", none);
          break;
      }
    }
    printf("\n");
  }
}

void freeBoard(Board b){
  int n = b.length;
  // freeing pawn board
  for(int i = 0; i<n;i++){
    free(b.board[i]);
  }
  free(b.board);

  // freeing possibleMove board
  for(int i = 0; i<n;i++){
    for (int j = 0; j < n; j++) {
      free(b.possibleMove[i][j]);
    }
    free(b.possibleMove[i]);
  }
  free(b.possibleMove);
}

void rules(){
  // Display the rules.
}
