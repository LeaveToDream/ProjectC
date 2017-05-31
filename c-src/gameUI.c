//
// Created by John-i5m on 15/05/2017.
//

#include <stdio.h>
#include <stdbool.h>

#include "../c-head/gameUI.h"
#include "../c-head/board.h"
#include "../c-head/gui.h"
#include "../c-head/ia.h"

int playAGameUI(Level level){

    // Initialise board, and fill it with pawn of the right color at the right location
    Status winner = Exit;
    printf("Starting a new game\n");
    Board b = initBoard();
    b = fillBoard(b);
    printf("Board instanced\n");
    Resources * res = initRes() ;
    if(res->state==1){
      printf("Resources loaded\n");
      winner = gamePvPUI(b, res);
      if(!(winner==Exit||winner==Home||winner==Restart)){
          displayWinningColorUI(res, winner);
          Event event = waitForCardEvent(res);
          if(event.zone==CARD_RESTART){
                winner=Restart;
          } else if(event.zone==CARD_HOME){
                winner=Home;
          }
      }
    }
    printf("Game ended\n");
    freeBoard(b);
    printf("Board cleaned\n");
    freeRes(res);
    printf("Resources cleaned\n");
    if(winner==Exit||winner==Home){
      return 1;
    } else if (winner==Restart){
      return 2;
    } else {
      return 0;
    }
}

Status gamePvPUI(Board b, Resources* res){
    int passCount = 0 ;
    Coord turnReturn ;
    Status state ;
    displayBoardUI(res, &b);
    displayBoardUI(res, &b);
    while(true){
        printf("Start of a round\n");
        displayPlayingColorUI(res, White);
        turnReturn = playerTurnUI(res, &b, White);
        if(isInBoard(b, turnReturn)){ // Turn went right
            passCount = 0 ;
            if((state = resolveGame(&b))!= Playing ){
                return state ;
            } else {
                displayBoardUI(res, &b);
                displayBoardUI(res, &b);
            }
        } else if(turnReturn.x == -1 ){
            switch(turnReturn.y){
                case 1 : // Player passed
                    passCount = passCount + 1 ;
                    if(passCount >= 2){ // Draw check
                        return Draw ;
                    }
                    break ;
                case 2 : // Player gave up
                    return BlackPlayer ;
                case 3 : // Restart
                    return Restart ;
                case 4 : // Home
                    return Home ;
                default: // Something went wrong
                    return Playing;
            }
        }

        displayPlayingColorUI(res, Black);
        turnReturn = playerTurnUI(res, &b, Black);
        if(isInBoard(b, turnReturn)){ // Turn went right
            passCount = 0 ;
            if((state = resolveGame(&b))!= Playing ){
                return state ;
            } else {
                displayBoardUI(res, &b);
                displayBoardUI(res, &b);
            }
        } else if(turnReturn.x == -1 ){
            switch(turnReturn.y){
                case 1 : // Player passed
                    passCount = passCount + 1 ;
                    if(passCount >= 2){ // Draw check
                        return Draw ;
                    }
                    break ;
                case 2 : // Player gave up
                    return WhitePlayer ;
                case 3 : // Restart
                    return Restart ;
                case 4 : // Home
                    return Home ;
                default: // Something went wrong
                    return Playing;
            }
        }
    }
}

Status gameIAUI(Board b, Resources* res, Level difficulty){
    int passCount = 0 ;
    Coord turnReturn ;
    Status state ;
    displayBoardUI(res, &b);
    while(true){
        printf("Start of a round\n");
        displayPlayingColorUI(res, White);
        turnReturn = playerTurnUI(res, &b, White);
        if(isInBoard(b, turnReturn)){ // Turn went right
            passCount = 0 ;
            if((state = resolveGame(&b))!= Playing ){
                return state ;
            } else {
                displayBoardUI(res, &b);
            }
        } else if(turnReturn.x == -1 ){
            switch(turnReturn.y){
                case 1 : // Player passed
                    passCount = passCount + 1 ;
                    if(passCount >= 2){ // Draw check
                        return Draw ;
                    }
                    break ;
                case 2 : // Player gave up
                    return BlackPlayer ;
                case 3 : // Restart
                    return Restart ;
                case 4 : // Home
                    return Home ;
            }
        }

        displayPlayingColorUI(res, Black);
        turnReturn = IATurnUI(res, &b, Black, difficulty);
        if(isInBoard(b, turnReturn)){ // Turn went right
            passCount = 0 ;
            if((state = resolveGame(&b))!= Playing ){
                return state ;
            } else {
                displayBoardUI(res, &b);
            }
        } else {} //TODO debug
    }
}

Coord playerTurnUI(Resources* res, Board* b, Pawn side){

    Coord locationCoord, targetCoord ;
    Event event ;
    while(true){
        printf("Start of a player turn(%d)\n", (int) side);
        //printf(">>> ");
        event = waitForUsefulEvent(res);
        // Some process to determine whether player wants to play, pass,
        // display the rules, or i don't know what else
        if(event.type==QUIT){
            return initCoord(-1,4) ;
        } else if(event.zone==BOARD){
            int x1, y1, x2, y2 ;
            locationCoord = eventToCoord(&event);
            x1 = locationCoord.x ;
            y1 = locationCoord.y ;
            if(b->board[x1][y1]==side){
                displayPossibleMoveUI(res, b, locationCoord );
                bool targetSelected = false ;
                while(!targetSelected){
                    printf("Pawn (%d,%d) selected, waiting for valid target location or cancel.\n", x1, y1);
                    event = waitForUsefulEvent(res);
                    if(event.type==QUIT){
                        return initCoord(-1,4) ;
                    } else if(event.zone==BOARD){
                        if(event.type==RIGHT_CLICK){
                            //targetCoord = initCoord(-1, 0);
                            targetSelected = true ;
                            displayBoardUI(res, b);
                            displayPlayingColorUI(res, side);
                        } else {
                            targetCoord = eventToCoord(&event);
                            x2 = targetCoord.x ;
                            y2 = targetCoord.y ;
                            bool move = movePawn(*b, locationCoord, targetCoord);
                            if(move){
                                resolveMove(b, targetCoord);
                                return targetCoord ;
                            } else {
                                printf("Invalid play, can't go from (%d,%d) to (%d,%d). Please try again\n", x1, y1, x2, y2);
                                //TODO add a beep
                            }
                        }

                    } else if(event.zone==BUTTONS) {
                        if (MYSDL_isInRect(res->buttonPassRect, event)) {
                            //pass
                            displayBoardUI(res, b);
                            return initCoord(-1, 1);
                        } else if (MYSDL_isInRect(res->buttonGiveUpRect, event)) {
                            //give up
                            return initCoord(-1, 2);
                        } else if (MYSDL_isInRect(res->buttonRestartRect, event)) {
                            //Restart
                            return initCoord(-1, 3);
                        } else if (MYSDL_isInRect(res->buttonHomeRect, event)) {
                            //Home
                            return initCoord(-1, 4);
                        }
                    }

                }
            }
        } else if(event.zone==BUTTONS) {
            if(MYSDL_isInRect(res->buttonPassRect, event)){
                //pass
                return initCoord(-1,1) ;
            } else if(MYSDL_isInRect(res->buttonGiveUpRect, event)){
                //give up
                return initCoord(-1,2) ;
            } else if(MYSDL_isInRect(res->buttonRestartRect, event)){
                //Restart
                return initCoord(-1,3) ;
            } else if(MYSDL_isInRect(res->buttonHomeRect, event)){
                //Home
                return initCoord(-1,4) ;
            }
        }else {
            printf("Invalid command. Please try again. Type help to get help.\n");
        }

    }
}

Coord IATurnUI(Resources* res, Board* b, Pawn side, Level difficulty) {
    int maxDepth;
    Move move = initMove(initCoord(-1, -1), initCoord(-1, -1));
    if (difficulty == EASY) {
        maxDepth = 2;
    }
    if (difficulty == NORMAL) {
        maxDepth = 2;
    }
    if (difficulty == HARD) {
        maxDepth = 2;
    }
    ValuedMove IAMove = negamaxAB_IA(*b, -100, 100, 0, maxDepth, Black, move);
    bool checkMove = movePawn(*b, IAMove.move.from, IAMove.move.to);
    if (checkMove) {
        resolveMove(b, IAMove.move.to);
        return IAMove.move.to;
    }
}
