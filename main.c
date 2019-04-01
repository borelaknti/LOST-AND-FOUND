#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include "enigme_clic.h"
#include <SDL/SDL_ttf.h>
int main()
{
	SDL_Surface *ecran=NULL ;
	SDL_Surface *image;
	SDL_Event event;
	SDL_Rect positionimage;
	int continuer=1,s;
	SDL_Init(SDL_INIT_VIDEO);
	ecran=SDL_SetVideoMode(1000,667,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	image=IMG_Load("fond.jpg");
	positionimage.x=0;
	positionimage.y=0;
	SDL_BlitSurface(image,NULL,ecran,&positionimage);
	SDL_Flip(ecran);
	while(continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				continuer=0;
			break;
			case SDL_KEYDOWN:
				s=enigmes(ecran);
				continuer=0;
			break;
		}
	}
	SDL_Quit();
	return 0;
}
