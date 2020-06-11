#include <stdlib.h>
#include <stdio.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

void sofien(SDL_Surface *ecran)
{
    int i;
    SDL_Surface *image, *rotation, *WBG;
    image = IMG_Load("Dot.png");
    WBG = IMG_Load("WhiteBG.jpg");
    //rotation = rotozoomSurface(image, angle, zoom, 0);
    SDL_Rect positionFond;
    positionFond.x = 0;
    positionFond.y = 0;
    SDL_Rect positionDot;
    positionDot.x = 200;
    positionDot.y = 400;
    for (i = 0; i < 100; i++)
    {
        if (positionDot.x < 400)
        {
            positionDot.x += 10;
        }
        else
        {
            do
            {
                positionDot.x -= 10;
                SDL_BlitSurface(WBG, NULL, ecran, &positionFond);

                SDL_BlitSurface(image, NULL, ecran, &positionDot);
        SDL_Flip(ecran);

            } while (positionDot.x > 20);
        }

        SDL_BlitSurface(WBG, NULL, ecran, &positionFond);

        SDL_BlitSurface(image, NULL, ecran, &positionDot);
        SDL_Flip(ecran);
    }
}

void main(int argc, char *argv[]){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *ecran = NULL, *WBG = NULL, *cup, *Logo;
    SDL_Event event;

    ecran = SDL_SetVideoMode(1400, 900, 32, SDL_HWSURFACE);
    
    SDL_WM_SetCaption("jeu", NULL);
    SDL_WM_SetIcon(Logo, NULL);

    SDL_Rect positionFond;
    positionFond.x = 0;
    positionFond.y = 0;

    WBG = IMG_Load("WhiteBG.jpg");
    SDL_BlitSurface(WBG, NULL, ecran, &positionFond);

    SDL_Flip(ecran);
    int done = 1;
    
    while (done)
    {

        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            SDL_Quit();
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_s:
                sofien(ecran);
                break;
            
            default:
                break;
            }
        
        default:
            break;
        }
    }
    SDL_FreeSurface(WBG);
    SDL_FreeSurface(ecran);
    SDL_Quit();
}


