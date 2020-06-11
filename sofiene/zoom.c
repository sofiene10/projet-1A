#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_rotozoom.h>
 
#define TEMPS       30 
 
int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *image = NULL, *rotation = NULL;
    SDL_Rect rect;
    SDL_Event event;
    double angle = 0;
 
    int continuer = 1;
    int tempsPrecedent = 0, tempsActuel = 0;
 
    SDL_Init(SDL_INIT_VIDEO);
 
    ecran = SDL_SetVideoMode(500, 500, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Faire des rotations avec SDL_gfx", NULL);
 
    image = SDL_LoadBMP("city.bmp");
 
    while(continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }
 
        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent > TEMPS)
        {
            angle += 2;
 
            tempsPrecedent = tempsActuel;
        }
        else
        {
            SDL_Delay(TEMPS - (tempsActuel - tempsPrecedent));
        }
 
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
 
        rotation = rotozoomSurface(image, angle, 1.0, 1); 
 
        
        rect.x =  200 - rotation->w / 2;
        rect.y =  200 - rotation->h / 2;
 
        SDL_BlitSurface(rotation , NULL, ecran, &rect);
        SDL_FreeSurface(rotation);
        SDL_Flip(ecran);
    }
 
    SDL_FreeSurface(ecran);
    SDL_FreeSurface(image);
    SDL_Quit();
 
    return EXIT_SUCCESS;
}
