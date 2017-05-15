#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//#include <afxres.h>

#include "../c-head/board.h"
#include "../c-head/game.h"
#include "../c-head/find.h"
#include "../c-head/getLine.h"

#define max(a,b) ((a)>(b)?(a):b)
#define min(a,b) ((a)<(b)?(a):b)
/**
 * Play a game func
 */
int playAGame(){
    /* code */
    printf("Hello Sir. \nSo you want to play Dai Hasami Shogi.\nHere are the rules:\n");
    rules();
    Level level = getDifficulty() ;
    switch(level){
        case EASY :
            printf("The difficulty is set to easy. Board is %dx%d\n", level, level);
            break ;

        case NORMAL :
            printf("The difficulty is set to normal. Board is %dx%d\n", level,level);
            break ;

        case HARDCORE :
            printf("The difficulty is set to hard. Board is %dx%d\n", level, level);
            break ;

        default:
            printf("The difficulty has not been set correctly. Board is screwed");
            break ;
    }

    // Initialise board, and fill it with pawn of the right color at the right location
    Board b = initBoard(level);
    b = fillBoard(b);
    printf("White pawns move first.\n\nPress Enter key to start\n");
    getchar();
    Status winner = gamePvP(b);
    switch(winner){
        case WhitePlayer :
            printf("White player wins.");
            printf("\n");
            break ;
        case BlackPlayer :
            printf("Black player wins.");
            printf("\n");
            break ;
        case Bot :
            printf("Computer wins [easy ~~].");
            printf("\n");
            break ;
        case Draw :
            printf("Game ended with no winner");
            printf("\n");
            break ;
        case Exit :
            printf("Game quit before ending.\n");
            freeBoard(b);
            printf("Game ended\nBoard cleaned\n");
            return 1;
        case Playing :
            printf("Error : Game ended while still tagged as continuing.");
            printf("\n");
        default :
            printf("Something wrong happened");
            printf("\n");
    }
    freeBoard(b);
    printf("Game ended\nBoard cleaned\n");
    return 0;
}

Level getDifficulty(){
    return NORMAL ;
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
            if((state = resolveGame(&b, turnReturn))!= Playing ){
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
            }
        }

        //Black player plays
        printf("Black player turn\nYour move ?\n");
        turnReturn = playerTurn(&b, Black);
        //turnReturn = initCoord(-1, 1); // For testing purpose
        if(isInBoard(b, turnReturn)){ // Turn went right
            passCount = 0 ;
            if((state = resolveGame(&b, turnReturn))!= Playing ){
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

Status resolveGame(Board* b, Coord c){
    if(b->whiteCount<5 && b->blackCount<5){
        return Draw ;
    } else if(b->whiteCount<5) {
        return BlackPlayer ;
    } else if(b->blackCount<5) {
        return WhitePlayer ;
    }

    int countB = 0, countW = 0 ;

    int iMin = - c.x + max(0, c.x-4);
    int iMax = - c.x + min(b->length-1, c.x+4);

    // Vertical path
    for (int i = iMin; i <= iMax; ++i) {
        if(isInBoard(*b, initCoord(c.x+i,c.y))){
            switch(b->board[c.x+i][c.y]){
                case White :
                    countB = 0 ;
                    if(i<b->length-2){
                        countW++;
                        if(countW == 5){
                            return WhitePlayer ;
                        }
                    }
                    break;
                case Black :
                    countW = 0 ;
                    if(i>2){
                        countB++;
                        if(countB == 5){
                            return BlackPlayer ;
                        }
                    }
                    break;

                default:
                    countB = 0 ;
                    countW = 0 ;
            }
        }
    }



    // Reboot
    countB = 0 ;
    countW = 0 ;

    // Diagonal paths :
    // From top left to bottom right

    for (int i = iMin; i <= iMax; ++i) {
        if(isInBoard(*b, initCoord(c.x+i,c.y+i))){
            switch(b->board[c.x+i][c.y+i]){
                case White :
                    countB = 0 ;
                    if(c.x+i<b->length-2){
                        countW++;
                        if(countW == 5){
                            return WhitePlayer ;
                        }
                    }
                    break;
                case Black :
                    countW = 0 ;
                    if(c.x+i>2){
                        countB++;
                        if(countB == 5){
                            return BlackPlayer;
                        }
                    }
                    break;

                default:
                    countB = 0 ;
                    countW = 0 ;
            }
        }
    }

    // Reboot
    countB = 0 ;
    countW = 0 ;

    // From top right to bottom left
    for (int i = iMin; i <= iMax; ++i) {
        if(isInBoard(*b, initCoord(c.x+i,c.y-i))){
            switch(b->board[c.x+i][c.y-i]){
                case White :
                    countB = 0 ;
                    if(c.x+i<b->length-2){
                        countW++;
                        if(countW == 5){
                            return WhitePlayer ;
                        }
                    }
                    break;
                case Black :
                    countW = 0 ;
                    if(c.x+i>2){
                        countB++;
                        if(countB == 5){
                            return BlackPlayer ;
                        }
                    }
                    break;

                default:
                    countB = 0 ;
                    countW = 0 ;
            }
        }
    }

    return Playing;
}

bool resolveMove(Board* b, Coord p){
    // We have 4 check to do : vertical/horizontal for black/white pawn.
    Coord empty = initCoord(-1, -1);
    Coord tempW[b->length]  ; int i = 0 ;
    Coord tempB[b->length]  ; int j = 0 ;
    Coord toSup[2*b->length]; int k = 0 ;

    for(int l = 0, ll = 0; l<b->length;l++){
        tempB[l] = empty ;
        tempW[l] = empty ;
        toSup[ll] = empty ;
        ll++;
        toSup[ll] = empty ;
        ll++;
    }

    bool switchW = false, switchB = false ;

    // First, the two horizontal ones
    for(int l = 0; l<b->length;l++){
        switch(b->board[p.x][l]){
            case White :
                // move tempW to toSup
                while (i>0){
                    i--;
                    toSup[k] = tempW[i];
                    tempW[i] = empty ,
                    k++;
                }
                // put switchW to true
                switchW = true ;
                // add to tempB if (switchB)
                if(switchB){
                    tempB[j]=initCoord(p.x, l);
                    j++;
                }
                break;
            case Black :
                // move tempB to toSup
                while (j>0) {
                    j--;
                    toSup[k] = tempB[j];
                    tempB[j] = empty ;
                    k++;
                }
                // put switchB to true
                switchB = true ;
                // add to tempW if (switchW)
                if(switchW){
                    tempW[i]=initCoord(p.x, l);
                    i++;
                }
                break;
            default :
                // clear tempW & tempB
                while (j>0) {
                    j--;
                    tempB[j] = empty ;
                }
                while (i>0){
                    i--;
                    tempW[i] = empty ;
                }
                // And set switchB & switchW to false
                switchB = false ;
                switchW = false ;
                break;
        }
    }

    // clear tempW & tempB
    while (j>0) {
        j--;
        tempB[j] = empty ;
    }
    while (i>0){
        i--;
        tempW[i] = empty ;
    }
    // And set switchB & switchW to false
    switchB = false ;
    switchW = false ;

    // And then the two vertical ones
    for(int l = 0; l<b->length;l++){
        switch(b->board[l][p.y]){
            case White :
                // move tempW to toSup
                while (i>0) {
                    i--;
                    toSup[k] = tempW[i];
                    tempW[i] = empty ;
                    k++;
                }
                // put switchW to true
                switchW = true ;
                // add to tempB if (switchB)
                if(switchB){
                    tempB[j]=initCoord(l, p.y);
                    j++;
                }
                break;
            case Black :
                // move tempB to toSup
                while (j>0) {
                    j--;
                    toSup[k] = tempB[j];
                    tempB[j] = empty ;
                    k++;
                }
                // put switchB to true
                switchB = true ;
                // add to tempW if (switchW)
                if(switchW){
                    tempW[i]=initCoord(l, p.y);
                    i++;
                }
                break;
            default :
                // clear tempW & tempB
                while (j>0) {
                    j--;
                    tempB[j] = empty ;
                }
                while (i>0) {
                    i--;
                    tempW[i] = empty ;
                }
                // And set switchB & switchW to false
                switchB = false ;
                switchW = false ;
                break;
        }
    }
    bool ret = true ;
    bool tempBool ;
    for (int l = 0; l < k; l++) {
        if(((toSup[l]).x!=-1) && ((toSup[l]).y!=-1)){
            tempBool = removePawn(b, toSup[l]);
            if (tempBool){
                refreshPMAfterMove(*b, toSup[l]);
            } else {
                ret = false ;
            }
        }
    }

    return ret ;
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
