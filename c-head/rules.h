#ifndef PROJECTC_RULES_H
#define PROJECTC_RULES_H

#include "board.h"
#include <SDL2/SDL.h>
#if defined(__APPLE__) && defined(__MACH__)
#include <SDL2_image/SDL_image.h>
#else
#include <SDL2/SDL_image.h>
#endif

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
