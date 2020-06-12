#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
 
int main( int argc, char**argv)
 
{



 SDL_Surface *sprite=NULL ,*personnage=NULL;

 
   SDL_Init(SDL_INIT_VIDEO);
 
   SDL_Surface*ecran=SDL_SetVideoMode(1600,400, 32, SDL_HWSURFACE |SDL_DOUBLEBUF);
SDL_Rect camera_pos;
camera_pos.x=0;
camera_pos.y=0;
 
  sprite= IMG_Load ("back.jpg");//ton décors, par ex: 1280x960
 
   Uint32 x=-100, y=-100; //les variables UINT32
 
    //les coordonnées de ton décors sur l'écran, le perso sera affiché au centre de l'écran
 
   SDL_Rect decors={x,y, sprite->w, sprite->h};
 
   personnage=IMG_Load("joueur1.png");//ton personnage
 
    //les coordonnées de ton perso sur l'écran, le perso sera affiché au centre de l'écran
 
   SDL_Rect perso={ ecran->w/2 - personnage->w/2, ecran->h/2 - personnage->w/2, personnage->w, personnage->h};
 
   for( SDL_Event evenement; evenement.type!=SDL_QUIT&& evenement.key.keysym.sym!=SDLK_ESCAPE; SDL_PollEvent(&evenement)){
 
    //remplissage de l'écran d'une couleur ici noir avant d'afficher les images
 
    SDL_FillRect(ecran, NULL, SDL_MapRGB( ecran->format, 0,0,0));
 
    //Tu dois gérer les événements ici avec switch pour déplacer le background
 
    switch( evenement.type){
 
   case SDL_KEYDOWN :
 
    switch(evenement.key.keysym.sym){
 
    case SDLK_LEFT :  x++; break;
 
    case SDLK_RIGHT : --x; break;
 
    case SDLK_UP : ++y; break;
 
    case SDLK_DOWN : --y; break;
 
    }
 
    ;
 
  break;
 
   }
 
   //tu affectes les nouvelles valeurs de x et y ici pour forcer le background a "scroller" dans toutes les directions
 
    decors.x=x; decors.y=y;
 
   //tu blittes ici
 
    SDL_BlitSurface( sprite, NULL, ecran, &decors);
 
    SDL_BlitSurface( personnage, NULL, ecran, &perso);
 
    SDL_Flip(ecran);
 
   }
 
   SDL_FreeSurface( sprite);
 
   SDL_FreeSurface( personnage);
 
    return 0;
 
}
