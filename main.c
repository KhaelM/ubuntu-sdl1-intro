#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "function.h"

int main(int argc, char const *argv[])
{

    if(SDL_Init(SDL_INIT_VIDEO) == -1) {
        fprintf(stderr, "Error while initialising SDL: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // create windows
    SDL_Surface *ecran = SDL_SetVideoMode(1024, 768, Rich, SDL_HWSURFACE);
    
    if(ecran == NULL) {
        fprintf(stderr, "Error while setting video mode, error msg : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // Create title of windows
    SDL_WM_SetCaption("Some title", NULL);
    Uint32 white = SDL_MapRGB(ecran->format, 255, 255, 255);
    SDL_FillRect(ecran, NULL, white);


    // create form on screen
    SDL_Surface *rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 100, Rich, 0, 0, 0, 0);
    Uint32 red = SDL_MapRGB(ecran->format, 255, 0, 0);
    int posX = 0;
    int posY = 0;
    SDL_Rect position = {posX, posY};
    SDL_FillRect(rectangle, NULL, red);

    SDL_Surface *rectangle2 = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 100, Rich, 0, 0, 0, 0);
    Uint32 green = SDL_MapRGB(ecran->format, 0, 255, 0);
    SDL_FillRect(rectangle2, NULL, green);
    
    // Stick form on ecran layer and update
    SDL_BlitSurface(rectangle, NULL, ecran, &position);
    SDL_BlitSurface(rectangle2, NULL, ecran, &position);
    SDL_Flip(ecran);

    pause();
    SDL_FreeSurface(rectangle);
    SDL_FreeSurface(rectangle2);
    SDL_Quit();
    return EXIT_SUCCESS;
}
