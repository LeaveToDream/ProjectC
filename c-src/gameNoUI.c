#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../c-head/board.h"
#include "../c-head/gameNoUI.h"
#include "../c-head/find.h"
#include "../c-head/getLine.h"

/**
 * Play a game func
 */
int playAGame(){
    /* code */
    printf("Hello Sir. \nSo you want to play Hasami Shogi.\nHere are the rules:\n");
    rules();
    // Initialise board, and fill it with pawn of the right color at the right location
    Board b = initBoard();
    b = fillBoard(b);
    printf("White pawns move first.\n\nPress Enter key to start\n");
    getchar();
    Status winner = gamePvP(b);
    switch(winner){
        case WhitePlayer :
            printf("******************\n");
            printf("White player wins.\n");
            printf("******************\n");
            break ;
        case BlackPlayer :
            printf("******************\n");
            printf("Black player wins.\n");
            printf("******************\n");
            break ;
        case Bot :
            printf("******************\n");
            printf("Computer wins [easy ~~].\n");
            printf("******************\n");
            break ;
        case Draw :
            printf("******************\n");
            printf("Game ended with no winner\n");
            printf("******************\n");
            break ;
        case Exit :
            printf("Game quit before ending.\n");
            freeBoard(b);
            printf("Game ended\nBoard cleaned\n");
            return 1;
        case Playing :
            printf("Error : Game ended while still tagged as continuing.\n");
        default :
            printf("/!\\/!\\/!\\ Something wrong happened /!\\/!\\/!\\ \n");
    }
    freeBoard(b);
    printf("Game ended\nBoard cleaned\n");
    return 0;
}

Status gamePvP(Board b){
    int passCount = 0 ;
    int n = 0 ;
    Coord turnReturn ;
    Status state ;
    printf("Let the game begin !\n\n");
    display(b);
    while(true){
        printf("Round %d\n",n++);
        //printf("White pawn count : %d\nBlack pawn count : %d\n",b.whiteCount, b.blackCount);
        //White player plays
        printf("White player turn\nYour move ?\n");
        turnReturn = playerTurn(&b, White);
        if(isInBoard(b, turnReturn)){ // Turn went right
            passCount = 0 ;
            if((state = resolveGame(&b))!= Playing ){
                return state ;
            } else {
                // Displaying the board after update
                printf("\nHere is the board : \n");
                display(b);
            }
        } else if(turnReturn.x == -1 ){
            switch(turnReturn.y){
                case 1 : // Player passed
                    passCount = passCount + 1 ;

                    // Draw check
                    if(passCount >= 2){
                        return Draw ;
                    }
                    break ;
                case 2 : // Player gave up
                    return BlackPlayer ;
                case 3 : // Hard quit
                    return Exit ;
                default: // Something went wrong
                    return Playing ;
            }
        }

        //Black player plays
        printf("Black player turn\nYour move ?\n");
        turnReturn = playerTurn(&b, Black);
        //turnReturn = initCoord(-1, 1); // For testing purpose
        if(isInBoard(b, turnReturn)){ // Turn went right
            passCount = 0 ;
            if((state = resolveGame(&b))!= Playing ){
                return state ;
            } else {
                // Displaying the board after update
                printf("\nHere is the board : \n");
                display(b);
            }
        } else if(turnReturn.x == -1 ){
            switch(turnReturn.y){
                case 1 : // Player passed
                    passCount = passCount + 1 ;

                    // Draw check
                    if(passCount >= 2){
                        return Draw ;
                    }
                    break ;
                case 2 : // Player gave up
                    return WhitePlayer ;
                case 3 : // Hard quit
                    return Exit ;
                default: // Something went wrong
                    return Playing ;
            }
        }
    }
}

Coord playerTurn(Board* b, Pawn side){
    char input[20] ;
    Coord locationCoord, targetCoord ;
    while(true){
        printf(">>> ");
        My_gets(input);
        if (input == NULL) {
          printf ("Error while reading input\n");
        } else {
          lower(input);
          // printf("%s\n", input);

          // Some process to determine whether player wants to play, pass,
          // display the rules, or i don't know what else
            if(inputIsAMove(input)){
              int x1, y1, x2, y2 ;
              if(processInputToMove(input, &x1, &y1, &x2, &y2)){
                  if(b->board[x1][y1]==enemyPawn(side)){
                      printf("Invalid play, can't move your opponent pawn. Please try again\n");
                  } else {
                      locationCoord = initCoord(x1, y1);
                      targetCoord = initCoord(x2, y2);
                      bool move = movePawn(*b, locationCoord, targetCoord);
                      if(move){
                          resolveMove(b, targetCoord);
                          return targetCoord ;
                      } else {
                          printf("Invalid play, can't go from %c%d to %c%d. Please try again\n",
                                 numberToLetter(x1), y1, numberToLetter(x2), y2);
                      }
                  }
              }else{
                  printf("Invalid play or error while processing. Please try again\n");
              }
          } else if(strcmp(input,"pass") == 0 ){
              return initCoord(-1,1) ;
          } else if(strcmp(input,"give up")==0){
              return initCoord(-1,2) ;
          } else if(strcmp(input,"exit") == 0 ){
              return initCoord(-1,3) ;
          } else if(strcmp(input,"rules")==0){
              rules() ;
          } else if(strcmp(input,"board")==0){
              display(*b) ;
          } else if(strcmp(input,"help")==0){
              printf("Type pass to pass your turn.\n");
              printf("Type give up to concede the victory.\n");
              printf("Type rules to receive a quick explanation of the game.\n");
              printf("Type board to display the current board.\n");
          } else {
              printf("Invalid command. Please try again. Type help to get help.\n");
          }
        }
    }
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

void rules(){
    // Display the rules.
    printf("The rules.\nBest joke ever.\n");
}

bool inputIsAMove(char* input){
    //apply regex "([A-Z]{1})([0-9]{1-2}) to ([A-Z]{1})([0-9]{1-2})"
    //return reg_matches(input, "([A-Z]{1})([0-9]{1-2}) to ([A-Z]{1})([0-9]{1-2})");
    return isAMove(input);
}

bool processInputToMove(char* input, int* x1, int* y1, int* x2, int* y2){
    //return reg_find_move(input, "([A-Z]{1})([0-9]{1-2}) to ([A-Z]{1})([0-9]{1-2})", x1, y1, x2, y2);
    return processMove(input, x1, y1, x2, y2);
}

int letterToNumber(char c){
    if(c >= 'a' && c <= 'z'){
        c = c + 'A' - 'a';
    }
    switch(c){
        case 'A' : return 0  ;
        case 'B' : return 1  ;
        case 'C' : return 2  ;
        case 'D' : return 3  ;
        case 'E' : return 4  ;
        case 'F' : return 5  ;
        case 'G' : return 6  ;
        case 'H' : return 7  ;
        case 'I' : return 8  ;
        case 'J' : return 9  ;
        case 'K' : return 10 ;
        case 'L' : return 11 ;
        case 'M' : return 12 ;
        case 'O' : return 13 ;
        case 'P' : return 14 ;
        case 'Q' : return 15 ;
        case 'R' : return 16 ;
        case 'S' : return 17 ;
        case 'T' : return 18 ;
        case 'U' : return 19 ;
        default :
            return -1 ;
    }
}

char numberToLetter(int n){
    switch(n){
        case 0  : return 'A' ;
        case 1  : return 'B' ;
        case 2  : return 'C' ;
        case 3  : return 'D' ;
        case 4  : return 'E' ;
        case 5  : return 'F' ;
        case 6  : return 'G' ;
        case 7  : return 'H' ;
        case 8  : return 'I' ;
        case 9  : return 'J' ;
        case 10 : return 'K' ;
        case 11 : return 'L' ;
        case 12 : return 'M' ;
        case 13 : return 'O' ;
        case 14 : return 'P' ;
        case 15 : return 'Q' ;
        case 16 : return 'R' ;
        case 17 : return 'S' ;
        case 18 : return 'T' ;
        case 19 : return 'U' ;
        default :
            return -1 ;
    }
}
