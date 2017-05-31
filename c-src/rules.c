#include <stdlib.h>

#include "../c-head/rules.h"
#include "../c-head/gui.h"

//Screen dimension constants
const int SCREEN_WIDTH_R = 860;
const int SCREEN_HEIGHT_R = 640;

ResourcesRules* initResRules() {
  ResourcesRules* res = (ResourcesRules*) malloc(sizeof(ResourcesRules));
  res->state = 1;
  if(MYSDL_init(&(res->window), &(res->renderer), SCREEN_WIDTH_R, SCREEN_HEIGHT_R) == 0) {
    res->back = MYSDL_loadImage("../c-res/rules.png", res->renderer);
    if(res->back!=NULL){
      res->quit = rect(700,570,130,50);
      return res;
    }else{
      fprintf(stderr, "Erreur MYSDL_loadImage : Could not initialize textures properly.\n");
      res->state = -1;
      return res ;
    }
  }else {
    fprintf(stderr, "Erreur MYSDL_init : Could not initialize SDL properly.\n");
    res->state =  -1;
    return res ;
  }
}

void waitForRulesEvent(ResourcesRules* res){
    SDL_Event events ;
    int x,y;
    printf("Waiting for rules event ");
    bool usefullEventAppeared = false ;
    while(!usefullEventAppeared){
        printf(".");
        SDL_WaitEvent(&events);
        switch (events.type){
            case SDL_QUIT:
                printf("\nQUIT CMD\n");
                fflush(stdout);
                usefullEventAppeared = true ;
                break;
            case SDL_MOUSEBUTTONDOWN:
                x = (int) events.button.x;
                y = (int) events.button.y;
                if(MYSDL_PointingRect(res->quit, x, y)){
                    printf("\nQUIT CMD\n");
                    usefullEventAppeared = true ;
                }
                break;
            default:
                // OMG WTF BBQ
                break;
        }
    }
    printf("\n");
    return ;
}

/*open the rules's window*/
void displayRules(ResourcesRules* res){
  SDL_RenderCopy(res->renderer, res->back, NULL, NULL);
  SDL_RenderPresent(res->renderer);
}
/*close the rules's window*/
void freeRules(ResourcesRules* res){
  SDL_Quit();
  free(res);
}

void wrapRules(){
  ResourcesRules* res=initResRules();
  displayRules(res);
  waitForRulesEvent(res);
  freeRules(res);
}
