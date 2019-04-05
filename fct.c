#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include"fct.h"


void charger_image(SDL_Surface *image,SDL_Surface *per,SDL_Surface *screen,SDL_Rect *posimg,SDL_Rect *posper)
{
per=IMG_Load("per.png");
image=IMG_Load("images.jpg");

posimg->x=0;
posimg->y=0;
posper->x=0;
posper->y=130;

SDL_BlitSurface(image,NULL,screen,posimg);
SDL_BlitSurface(per,NULL,screen,posper);

SDL_Flip(screen);


}















