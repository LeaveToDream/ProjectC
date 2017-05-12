#include "../c-head/gui.h"
#include "../c-head/board.h"


//Screen dimension constants
const int SCREEN_WIDTH = 860;
const int SCREEN_HEIGHT = 640;

int maineuh (int argc, char* argv[]){
    //Screen dimension constants
    //The window we'll be rendering to
    SDL_Window* window = NULL;

    SDL_Renderer* renderer = NULL ;

    SDL_Texture * textureBack ;
    SDL_Texture * textureNone ;
    SDL_Texture * textureWhite ;
    SDL_Texture * textureBlack ;

    if(MYSDL_init(&window, &renderer, SCREEN_WIDTH, SCREEN_HEIGHT) == 0){
        textureBack = MYSDL_loadImage("../c-res/back.png", renderer);
        textureNone = MYSDL_loadImage("../c-res/none.png", renderer);
        textureWhite = MYSDL_loadImage("../c-res/white.png", renderer);
        textureBlack = MYSDL_loadImage("../c-res/black.png", renderer);

        if(!(textureBack == NULL || textureNone == NULL || textureWhite == NULL || textureBlack == NULL)){



            // While(playing)

                // On recupere les entrées

                // On modifie l'état

                // On affiche
            SDL_RenderCopy(renderer, textureBack, NULL, NULL); // On colle la texture de fond sur tout le canvas.

            // Whilling the pawns
            Board b = initBoard(NORMAL);
            b = fillBoard(b);

            int xOrigin = 50, yOrigin = 50, x, y;
            SDL_Rect rectangle = {xOrigin, yOrigin, 60, 60};
            for (int i = 0; i < b.length ; ++i) {
                rectangle.y = yOrigin+i*60;
                for (int j = 0; j < b.length ; ++j) {
                    rectangle.x = xOrigin+j * 60 ;
                    switch(b.board[i][j]){
                        case None :
                            // display texture none
                            SDL_RenderCopy(renderer, textureNone, NULL, &rectangle);
                            break;
                        case Black :
                            // display texture white ;
                            SDL_RenderCopy(renderer, textureBlack, NULL, &rectangle);
                            break ;
                        case White :
                            // display texture black ;
                            SDL_RenderCopy(renderer, textureWhite, NULL, &rectangle);
                            break ;
                        default:
                            // OMG WTF BBQ
                            break ;

                    }
                }
            }



            SDL_RenderPresent(renderer); // Display everything that was painted on it
            SDL_Delay(10000);
        } else {
            // ERROR : Could not initialize textures properly.
        }

    } else {
        // ERROR : Could not initialize SDL properly
    }

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}


int MYSDL_init(SDL_Window ** window, SDL_Renderer **renderer, int width, int height ){

    if(0 != SDL_Init(SDL_INIT_EVERYTHING)) {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return -1;
    }

    if(0 != SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, window, renderer)) {
        fprintf(stderr, "Erreur SDL_CreateWindowAndRenderer : %s", SDL_GetError());
        return -1;
    }

    return 0;
}

SDL_Texture* MYSDL_loadImage (const char path[], SDL_Renderer* renderer){

    SDL_Surface *tmp = NULL;
    SDL_Texture *texture = NULL;
    tmp = IMG_Load(path);
    if(NULL == tmp) {
        fprintf(stderr, "Erreur IMG_Load : %s", IMG_GetError());
        return NULL;
    }
    texture = SDL_CreateTextureFromSurface(renderer, tmp);
    SDL_FreeSurface(tmp);
    if(NULL == texture) {
        fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
        return NULL;
    }
    return texture;
}