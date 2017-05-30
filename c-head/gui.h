//
// Created by John-i5m on 25/04/2017.
//

#ifndef PROJECTC_GUI_H
#define PROJECTC_GUI_H

#include <stdbool.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "board.h"

//Screen dimension constants
const int SCREEN_WIDTH = 860;
const int SCREEN_HEIGHT = 640;

const int BOARD_X_ORIG = 50 ;
const int BOARD_Y_ORIG = 50 ;

const int CARD_X_ORIG = 120 ;
const int CARD_Y_ORIG = 120 ;

const int PLAYER_X_ORIG = 640 ;
const int PLAYER_Y_ORIG = 50 ;

const int PAWN_X_ORIG = 760 ;
const int PAWN_Y_ORIG = 45 ;

typedef struct Resources Resources ;
typedef struct Event Event ;
typedef enum EventType EventType;
typedef enum EventZone EventZone ;

enum EventType {
    UNDEF, QUIT, RIGHT_CLICK, LEFT_CLICK
};

enum EventZone {
    NONE, BOARD, BUTTONS, CARD_RESTART, CARD_QUIT
};

struct Resources {
    SDL_Window* window;
    SDL_Renderer* renderer ;
    SDL_Texture * back;
    SDL_Texture * none;
    SDL_Texture * white;
    SDL_Texture * whiteAlone;
    SDL_Texture * black;
    SDL_Texture * blackAlone;
    SDL_Texture * shining;
    SDL_Texture * playing;
    SDL_Texture * cardWhite;
    SDL_Texture * cardBlack;
    SDL_Texture * cardDraw;
    SDL_Texture * cardBot;
    SDL_Rect boardRect;
    SDL_Rect cardRestartRect;
    SDL_Rect cardQuitRect;
    SDL_Rect buttonRect;
    SDL_Rect buttonPassRect;
    SDL_Rect buttonGiveUpRect;
    SDL_Rect buttonRestartRect;
    SDL_Rect buttonRulesRect;
    int state ;
};

struct Event {
    EventType type ;
    EventZone zone ;
    int x ;
    int y ;
};

SDL_Rect rect(int x, int y, int w, int h);
Resources* initRes();
void freeRes(Resources* res);
void displayBoardUI(Resources* res, Board* b);
void displayWinningColorUI(Resources* res, Status status);
void displayPlayingColorUI(Resources* res, Pawn p);
void displayPossibleMoveUI(Resources* res, Board* b, Coord c);
void displayRules();
Event waitForUsefulEvent(Resources *res);
Event waitForCardEvent(Resources* res);
int testUI ();
Coord eventToCoord(Event* event);
SDL_Texture* MYSDL_loadImage (const char path[], SDL_Renderer* renderer);
int MYSDL_init(SDL_Window ** window, SDL_Renderer **renderer, int width, int height );
bool MYSDL_PointingRect(SDL_Rect rect, int x, int y);
bool MYSDL_isInRect(SDL_Rect rect, Event event);

#endif //PROJECTC_GUI_H
