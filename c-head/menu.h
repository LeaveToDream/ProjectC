#ifndef PROJECTC_MENU_H
#define PROJECTC_MENU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "board.h"

typedef enum EventMenu EventMenu ;
typedef struct ResourcesMenu ResourcesMenu;
enum EventMenu {
  PLAY, BUTTON_F, BUTTON_M, BUTTON_D, RULES, QUITMENU
};

struct ResourcesMenu {
  SDL_Texture * backMenu;
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Rect play;
  SDL_Rect button_f;
  SDL_Rect button_m;
  SDL_Rect button_d;
  SDL_Rect rules;
  SDL_Rect quit;
  int state;
};

ResourcesMenu* initResMenu();
EventMenu waitForMenuEvent(ResourcesMenu*);

void displayMenu(ResourcesMenu*);
void freeMenu(ResourcesMenu*);

#endif // PROJECTC_MENU_H
