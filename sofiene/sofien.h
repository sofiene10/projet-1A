
#include "libs.h"
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
    for (i = 0; i < 250; i++)
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