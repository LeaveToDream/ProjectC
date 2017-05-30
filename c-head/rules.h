#ifndef PROJECTC_RULES_H
#define PROJECTC_RULES_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "board.h"

typedef struct ResourcesRules ResourcesRules;

struct ResourcesRules {
  SDL_Texture * back;
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Rect quit;
  int state;
};

ResourcesRules* initResRules();
void waitForRulesEvent(ResourcesRules*);

void displayRules(ResourcesRules*);
void freeRules(ResourcesRules*);

void wrapRules();

#endif // PROJECTC_RULES_H
