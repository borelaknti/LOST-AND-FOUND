#include<stdlib.h>
#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
 
int main( int argc, char**argv)
 
{
 
   SDL_Init(SDL_INIT_VIDEO);
 
   SDL_Surface*ecran=SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
 
   SDL_Surface*sprite=SDL_LoadBMP("cave.bmp");
 
   Uint32 x=-100, y=-100; 
 
    
 
   SDL_Rect decors={x,y, sprite->w, sprite->h};
 
   SDL_Surface*personnage=IMG_Load("perso.png");
 
    
 
   SDL_Rect perso={ ecran->w/2 - personnage->w/2, ecran->h/2 - personnage->w/2, personnage->w, personnage->h};
 
   for( SDL_Event evenement; evenement.type!=SDL_QUIT&& evenement.key.keysym.sym!=SDLK_ESCAPE; SDL_WaitEvent(&evenement)){
 
    
 
    SDL_FillRect(ecran, NULL, SDL_MapRGB( ecran->format, 0,0,0));
 
   
   
 
    switch( evenement.type){


    SDL_EnableKeyRepeat(70, 70);


    case SDL_KEYDOWN :
 
    switch(evenement.key.keysym.sym){
    
    case SDLK_RIGHT :  --x; break;
 
    case SDLK_LEFT : ++x; break;
 
    case SDLK_DOWN : --y; break;
 
    case SDLK_UP : ++y; break;
 
    }
 
    ;
 
  break;
 
   }
 
    
 
    decors.x=x; decors.y=y;
 
    SDL_BlitSurface( sprite, NULL, ecran, &decors);
 
    SDL_BlitSurface( personnage, NULL, ecran, &perso);
 
    SDL_Flip(ecran);
 
   }
 
   SDL_FreeSurface( sprite);

   SDL_FreeSurface( personnage);
 
    return 0;
 
}

