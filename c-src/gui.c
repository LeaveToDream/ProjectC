#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "../c-head/gui.h"
#include "../c-head/board.h"

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

SDL_Rect rect(int x, int y, int w, int h){
    SDL_Rect temp = {x,y,w,h};
    return temp ;
}

Resources* initRes(){
    Resources* res = (Resources*) malloc(sizeof(Resources))  ;
    res->state = 1 ;
    if(MYSDL_init(&(res->window), &(res->renderer), SCREEN_WIDTH, SCREEN_HEIGHT) == 0) {

        res->back           = MYSDL_loadImage("../c-res/back.png", res->renderer);
        res->none           = MYSDL_loadImage("../c-res/none.png", res->renderer);
        res->white          = MYSDL_loadImage("../c-res/white.png", res->renderer);
        res->whiteAlone     = MYSDL_loadImage("../c-res/whiteAlone.png", res->renderer);
        res->black          = MYSDL_loadImage("../c-res/black.png", res->renderer);
        res->blackAlone     = MYSDL_loadImage("../c-res/blackAlone.png", res->renderer);
        res->shining        = MYSDL_loadImage("../c-res/shining.png", res->renderer);
        res->playing        = MYSDL_loadImage("../c-res/playing.png", res->renderer);
        res->cardWhite      = MYSDL_loadImage("../c-res/cardWhite.png", res->renderer);
        res->cardBlack      = MYSDL_loadImage("../c-res/cardBlack.png", res->renderer);
        res->cardBot        = MYSDL_loadImage("../c-res/cardBot.png", res->renderer);
        res->cardDraw       = MYSDL_loadImage("../c-res/cardDraw.png", res->renderer);

        if(!(   res->back==NULL     || res->none==NULL||
                res->white==NULL    || res->whiteAlone==NULL||
                res->black==NULL    || res->blackAlone==NULL||
                res->shining==NULL  || res->cardBlack==NULL||
                res->cardBot==NULL  || res->cardWhite==NULL||
                res->cardDraw==NULL || res->playing==NULL)){
            // Successfully init Resources. Set state to 0 (no error) and return it


            res->boardRect          = rect(50,50,540,540) ;
            res->cardRestartRect    = rect(CARD_X_ORIG+90,CARD_Y_ORIG+235,220,60) ;
            res->cardHomeRect       = rect(CARD_X_ORIG+90,CARD_Y_ORIG+295,220,60) ;
            res->buttonRect         = rect(747,527,90,90) ;
            res->buttonPassRect     = rect(747,527,45,45) ;
            res->buttonGiveUpRect   = rect(792,527,45,45) ;
            res->buttonRestartRect  = rect(747,572,45,45) ;
            res->buttonHomeRect     = rect(792,572,45,45) ;

            return res ;
        } else {
            // ERROR : Could not initialize textures properly.
            fprintf(stderr, "Erreur MYSDL_loadImage : Could not initialize textures properly.\n");
            res->state =  -1;
            return res ;
        }

    } else {
        // ERROR : Could not initialize SDL properly
        fprintf(stderr, "Erreur MYSDL_init : Could not initialize SDL properly.\n");
        res->state =  -1;
        return res ;
    }
}

void freeRes(Resources *res) {
    SDL_Quit();
    free(res);
}

void displayBoardUI(Resources* res, Board* b){
    SDL_RenderCopy(res->renderer, res->back, NULL, NULL);
    // fill canvas with back.png
    SDL_Rect rectanglePlay = {PLAYER_X_ORIG, PLAYER_Y_ORIG, 104, 30};
    SDL_RenderCopy(res->renderer, res->playing, NULL, &rectanglePlay);

    SDL_Rect rectangle = {BOARD_X_ORIG, BOARD_Y_ORIG, 60, 60};
    for (int i = 0; i < b->length ; ++i) {
        rectangle.y = BOARD_Y_ORIG+i*60;
        for (int j = 0; j < b->length ; ++j) {
            rectangle.x = BOARD_X_ORIG+j * 60 ;
            switch(b->board[i][j]){
                case None :
                    // display texture none
                    SDL_RenderCopy(res->renderer, res->none, NULL, &rectangle);
                    break;
                case Black :
                    // display texture white ;
                    SDL_RenderCopy(res->renderer, res->black, NULL, &rectangle);
                    break ;
                case White :
                    // display texture black ;
                    SDL_RenderCopy(res->renderer, res->white, NULL, &rectangle);
                    break ;
                default:
                    // OMG WTF BBQ
                    break ;

            }
        }
    }
    SDL_RenderPresent(res->renderer); // Display everything that was painted on it
}

Event waitForUsefulEvent(Resources *res){
    SDL_Event events ;
    Event event = {UNDEF, NONE, 0, 0};
    int i = 0 ;
    bool usefullEventAppeared = false ;
    printf("Waiting for usefull event ");
    while(!usefullEventAppeared){
        printf(".");
        SDL_WaitEvent(&events);
        switch (events.type){
            case SDL_QUIT:
                printf("\nQUIT CMD\n");
                fflush(stdout);
                event.type = QUIT;
                usefullEventAppeared = true ;
                break;
            case SDL_MOUSEBUTTONDOWN:
                // Compute the type of event
                switch(events.button.button){
                    case SDL_BUTTON_LEFT :
                        event.type = LEFT_CLICK;
                        break;
                    case SDL_BUTTON_RIGHT :
                        event.type = RIGHT_CLICK;
                        break;
                    default:
                        event.type = UNDEF;
                }
                event.x = (int) events.button.x;
                event.y = (int) events.button.y;

                if(MYSDL_PointingRect(res->boardRect, event.x, event.y)){
                    printf("\nBOARD in wait event \n");
                    event.zone=BOARD ;
                    usefullEventAppeared = true ;
                } else if(MYSDL_PointingRect(res->buttonRect, event.x, event.y)){
                    printf("\nBUTTONS in wait event \n");
                    event.zone=BUTTONS ;
                    usefullEventAppeared = true ;
                }
                break;
            default:
                // OMG WTF BBQ
                break;
        }
    }
    printf("-----------------------------------------------------------------\n");
    return event ;
}

Event waitForCardEvent(Resources* res){
    SDL_Event events ;
    Event event = {UNDEF, NONE, 0, 0};
    printf("Waiting for card event ");
    bool usefullEventAppeared = false ;
    while(!usefullEventAppeared){
        printf(".");
        SDL_WaitEvent(&events);
        switch (events.type){
            case SDL_QUIT:
                printf("\nQUIT CMD\n");
                fflush(stdout);
                event.type = QUIT;
                usefullEventAppeared = true ;
                break;
            case SDL_MOUSEBUTTONDOWN:

                event.x = (int) events.button.x;
                event.y = (int) events.button.y;

                if(MYSDL_PointingRect(res->cardRestartRect, event.x, event.y)){
                    printf("\nRESTART CMD\n");
                    event.zone=CARD_RESTART ;
                    usefullEventAppeared = true ;
                } else if(MYSDL_PointingRect(res->cardHomeRect, event.x, event.y)){
                    printf("\nHOME CMD\n");
                    event.zone=CARD_HOME ;
                    usefullEventAppeared = true ;
                }
                break;
            default:
                // OMG WTF BBQ
                break;
        }
    }
    printf("\n");
    return event ;
}

void displayPossibleMoveUI(Resources* res, Board* b, Coord c){
    Coord* possibleMove = b->possibleMove[c.x][c.y];
    for (int i = 0; i < 2*b->length ; ++i) {
        if(possibleMove[i].x!=-1){
            SDL_Rect rectangle = {BOARD_X_ORIG, BOARD_Y_ORIG, 60, 60};
            rectangle.x = BOARD_X_ORIG+possibleMove[i].y *60;
            rectangle.y = BOARD_Y_ORIG+possibleMove[i].x *60;
            // display texture glowing
            SDL_RenderCopy(res->renderer, res->shining, NULL, &rectangle);
        }
    }
    SDL_RenderPresent(res->renderer); // Display everything that was painted on it
}

void displayPlayingColorUI(Resources* res, Pawn p){
    SDL_Texture* pawn ;

    switch(p) {
        case Black :
            pawn = res->blackAlone;
            break;
        case White :
            pawn = res->whiteAlone;
            break;
        default:
            fprintf(stderr, "Erreur displayPlayingColorUI : Wrong pawn input\n");
            getchar();
            exit(-1);
    }

    SDL_Rect rectangle = {PAWN_X_ORIG, PAWN_Y_ORIG, 38, 38};
    SDL_RenderCopy(res->renderer, pawn, NULL, &rectangle);
    SDL_RenderPresent(res->renderer); // Display everything that was painted on it
}

void displayWinningColorUI(Resources* res, Status status){
    SDL_Texture* card ;

    switch(status) {
        case BlackPlayer :
            card = res->cardBlack;
            break;
        case WhitePlayer :
            card = res->cardWhite;
            break;
        case Bot:
            card = res->cardBot;
            break;
        case Draw:
            card = res->cardDraw;
            break;
        default:
            fprintf(stderr, "Erreur displayWinningColorUI : Wrong status input (%d)\n", status);
            getchar();
            exit(-1);
    }

    SDL_Rect rectangle = {CARD_X_ORIG, CARD_Y_ORIG, 400, 400};
    SDL_RenderCopy(res->renderer, card, NULL, &rectangle);
    SDL_RenderPresent(res->renderer); // Display everything that was painted on it
}

Coord eventToCoord(Event* event){
    return initCoord((event->y-BOARD_Y_ORIG)/60,(event->x-BOARD_X_ORIG)/60);
}

int testUI (){
    Resources * res = initRes() ;
    Board board = initBoard(NORMAL);
    Board* b = &board ;
    fillBoard(board);
    displayBoardUI(res, b);
    displayPossibleMoveUI(res, b, initCoord(0,0));
    displayPlayingColorUI(res, White);
    SDL_Delay(10000);

    freeRes(res);

    return 0 ;
}


int MYSDL_init(SDL_Window ** window, SDL_Renderer **renderer, int width, int height ){

    if(0 != SDL_Init(SDL_INIT_EVERYTHING)) {
        fprintf(stderr, "Erreur SDL_Init : %s\n", SDL_GetError());
        return -1;
    }

    if(0 != SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, window, renderer)) {
        fprintf(stderr, "Erreur SDL_CreateWindowAndRenderer : %s\n", SDL_GetError());
        return -1;
    }

    return 0;
}

SDL_Texture* MYSDL_loadImage (const char path[], SDL_Renderer* renderer){

    SDL_Surface *tmp = NULL;
    SDL_Texture *texture = NULL;
    tmp = IMG_Load(path);
    if(NULL == tmp) {
        fprintf(stderr, "Erreur IMG_Load : %s\n", IMG_GetError());
        return NULL;
    }
    texture = SDL_CreateTextureFromSurface(renderer, tmp);
    SDL_FreeSurface(tmp);
    if(NULL == texture) {
        fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s\n", SDL_GetError());
        return NULL;
    }
    return texture;
}

bool MYSDL_PointingRect(SDL_Rect rect, int x, int y){
    //rect = { x, y, w, h}
    return (x>=rect.x)&&(x<rect.x+rect.w)&&(y>=rect.y)&&(y<rect.y+rect.h);
}

bool MYSDL_isInRect(SDL_Rect rect, Event event){
    return MYSDL_PointingRect(rect, event.x, event.y);
}
