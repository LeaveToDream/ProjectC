#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../c-head/board.h"
#include "../c-head/game.h"

Board initBoard(Level level){
    Board b;
    int n = (int) level;
    // Preparing pawn board
    b.board = (Pawn **) malloc(sizeof(Pawn*)*n);
    for(int i = 0; i<n;i++){
        b.board[i]= (Pawn *) malloc(sizeof(Pawn)*n);
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

    //b.blackCount = (int *) malloc(sizeof(int));
    //b.whiteCount = (int *) malloc(sizeof(int));

    //*(b.blackCount) = 0 ;
    //*(b.whiteCount) = 0 ;

    return b;
}

Coord initCoord(int x, int y){
    struct Coord p = {x,y};
    return p ;
}

Board fillBoard(Board b){
    int n = b.length ;
    int blackCount = 0, whiteCount = 0 , noneCount = 0 ;
    int line ;
    for(int i = 0; i<1;i++){
        for(int j = 0; j<n;j++){
            b.board[i][j]= Black;
            blackCount++;
        }
    }
    for(int i = 1; i<n-1;i++){
        for(int j = 0; j<n;j++){
            b.board[i][j]= None;
            noneCount++;
        }
    }
    for(int i = n-1; i<n;i++){
        for(int j = 0; j<n;j++){
            b.board[i][j]= White;
            whiteCount++;
        }
    }
    line = 0 ;
    for(int j = 0; j < n; j++) {
        possibleMove(b, initCoord(line,j));
        // the board, and coordinate of the pawn to process
    }
    line = n-1;
    for(int j = 0; j < n; j++) {
        possibleMove(b, initCoord(line,j));
        // the board, and coordinate of the pawn to process
    }
    b.whiteCount = whiteCount;
    b.blackCount = blackCount;

    //printf("Recap : white pawn count = %d, black pawn count = %d, empty cells = %d. \n", b.whiteCount, b.blackCount, noneCount);
    return b ;
}

bool isInBoard(Board b, Coord c){
    if(0 > c.x || c.x >= b.length){
        return false ;
    }
    if(0 > c.y || c.y >= b.length){
        return false ;
    }
    return true ;
}

Pawn enemyPawn(Pawn p){
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
            b.possibleMove[c.x][c.y][i]=initCoord(-1,-1);
        }
    }

    if(b.board[c.x][c.y]!=None){
        int x, y, i=0;
        Pawn p = b.board[c.x][c.y];
        Pawn enemy = enemyPawn(p);
        // Maintenant on test les quatres lignes, jusqu'a rencontrer un obstacle
        // Haut
        x = c.x;
        y = c.y;
        while(isInBoard(b, initCoord(x-1, y)) && b.board[x-1][y]==None){
            x = x-1;
            b.possibleMove[c.x][c.y][i]=initCoord(x,y);
            i++;
        }
        // Bas
        x = c.x;
        while(isInBoard(b, initCoord(x+1, y)) && b.board[x+1][y]==None){
            x = x+1;
            b.possibleMove[c.x][c.y][i]=initCoord(x,y);
            i++;
        }
        // Gauche
        x = c.x;
        while(isInBoard(b, initCoord(x, y-1)) && b.board[x][y-1]==None){
            y = y-1;
            b.possibleMove[c.x][c.y][i]=initCoord(x,y);
            i++;
        }
        // Droite
        y = c.y;
        while(isInBoard(b, initCoord(x, y+1)) && b.board[x][y+1]==None){
            y = y+1;
            b.possibleMove[c.x][c.y][i]=initCoord(x,y);
            i++;
        }
        // Si un Pawn est au contact
        y = c.y;

        // Hidari
        if(isInBoard(b, initCoord(x-1, y)) && b.board[x-1][y]==enemy){ // Tobiutsuru ga dekiru
            b.possibleMove[c.x][c.y][i]=initCoord(x-2,y);
            i++;
        }
        // Migi
        if(isInBoard(b, initCoord(x+1, y)) && b.board[x+1][y]==enemy){ // On peut sauter au dessus
            b.possibleMove[c.x][c.y][i]=initCoord(x+2,y);
            i++;
        }
        // Ué
        if(isInBoard(b, initCoord(x, y-1)) && b.board[x][y-1]==enemy){ // On peut sauter au dessus
            b.possibleMove[c.x][c.y][i]=initCoord(x,y-2);
            i++;
        }
        // Shita
        if(isInBoard(b, initCoord(x, y+1)) && b.board[x][y+1]==enemy){ // On peut sauter au dessus
            b.possibleMove[c.x][c.y][i]=initCoord(x,y+2);
        }
        // Dab
    }
}

bool isMovePossible(Board b, Coord p1, Coord p2){
    if(!(isInBoard(b,p1)||isInBoard(b,p2))){
        return false ;
    }
    for (int i = 0; i < (b.length)*2; i++) {
        if( (b.possibleMove[p1.x][p1.y][i]).x==p2.x && (b.possibleMove[p1.x][p1.y][i]).y==p2.y ){
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

bool removePawn(Board *b, Coord p){
    if(b->board[p.x][p.y]!=None){
        switch(b->board[p.x][p.y]){
            case White :
                (b->whiteCount)--;
                break;
            case Black :
                (b->blackCount)--;
        }
        b->board[p.x][p.y]=None;
        printf("Pawn eaten at location %c%d\n", numberToLetter(p.x), p.y);
        return true;
    }
    return false ;
}

void display(Board b) {
    char none = '.', black = 'b', white = 'w';
    printf("  ");
    for (int i = 0; i < b.length; i++) {
        printf("%d ", i);
    }

    printf("\n");

    for (int i = 0; i < b.length; i++) {

        // Line number
        printf("%c ", numberToLetter(i));

        for (int j = 0; j < b.length; j++) {

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

    printf("\n");
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
