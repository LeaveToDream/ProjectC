//
// Created by John-i5m on 25/04/2017.
//

#ifndef PROJECTC_GUI_H
#define PROJECTC_GUI_H

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

int maineuh (int argc, char* argv[]);
SDL_Texture* MYSDL_loadImage (const char path[], SDL_Renderer* renderer);
int MYSDL_init(SDL_Window ** window, SDL_Renderer **renderer, int width, int height );

#endif //PROJECTC_GUI_H
