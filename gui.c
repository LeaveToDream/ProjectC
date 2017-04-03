#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

int main (int argc, char* argv[]){
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window = SDL_CreateWindow("Hasami", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 200,200, SDL_WINDOW_OPENGL);

}
