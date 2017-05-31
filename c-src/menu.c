
#include <stdlib.h>
#include "../c-head/menu.h"
#include "../c-head/gui.h"

//Screen dimension constants
const int SCREEN_WIDTH_M = 860;
const int SCREEN_HEIGHT_M = 640;

ResourcesMenu* initResMenu() {
  ResourcesMenu* menu= (ResourcesMenu*) malloc(sizeof(ResourcesMenu));
  menu->state = 1;
  if(MYSDL_init(&(menu->window), &(menu->renderer), SCREEN_WIDTH_M, SCREEN_HEIGHT_M) == 0) {
    menu-> backMenu = MYSDL_loadImage("../c-res/menu.png", menu->renderer);
    if(menu->backMenu!=NULL){
      menu->play = rect(160,240,190,45);
      menu->button_f = rect(235,340,180,35);
      menu->button_m = rect(235,380,220,35);
      menu->button_d = rect(235,420,245,35);
      menu->rules = rect(160,460,150,45);
      menu->quit = rect(160,510,170,45);
      return menu;
    }else{
      fprintf(stderr, "Erreur MYSDL_loadImage : Could not initialize textures properly.\n");
      menu->state = -1;
      return menu ;
    }
  }else {
    fprintf(stderr, "Erreur MYSDL_init : Could not initialize SDL properly.\n");
    menu->state =  -1;
    return menu ;
  }
}

EventMenu waitForMenuEvent(ResourcesMenu* menu){
    SDL_Event events ;
    EventMenu event = QUITMENU;
    int x,y ;
    printf("Waiting for menu event ");
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
                if(MYSDL_PointingRect(menu->play, x, y)){
                    printf("\nTWO PLAYER CMD\n");
                    event = PLAY ;
                    usefullEventAppeared = true ;
                }else if(MYSDL_PointingRect(menu->button_f, x, y)){
                    printf("\nONE PLAYER EASY CMD\n");
                    event = BUTTON_F ;
                    usefullEventAppeared = true ;
                }else if(MYSDL_PointingRect(menu->button_m, x, y)){
                    printf("\nONE PLAYER MEDIUM CMD\n");
                    event = BUTTON_M ;
                    usefullEventAppeared = true ;
                }else if(MYSDL_PointingRect(menu->button_d, x, y)){
                    printf("\nONE PLAYER HARD CMD\n");
                    event = BUTTON_D ;
                    usefullEventAppeared = true ;
                }else if(MYSDL_PointingRect(menu->rules, x, y)){
                    printf("\nRULES CMD\n");
                    event = RULES ;
                    usefullEventAppeared = true ;
                }else if(MYSDL_PointingRect(menu->quit, x, y)){
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
    return event ;
}

/*open the menu's window*/
void displayMenu(ResourcesMenu* res){
  SDL_RenderCopy(res->renderer, res->backMenu, NULL, NULL);
  SDL_RenderPresent(res->renderer);
}
/*close the menu's window*/
void freeMenu(ResourcesMenu* res){
  SDL_Quit();
  free(res);
}
