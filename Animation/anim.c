
#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>

#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600
#define SPRITE_SIZE    64

int gameover;


SDL_Rect rcSrc, rcSprite;

void HandleEvent(SDL_Event event)
{
	switch (event.type) {
		
		case SDL_QUIT:
			gameover = 1;
			break;
		 case SDL_MOUSEBUTTONUP:
                               rcSprite.x = event.button.x;
                               rcSprite.y = event.button.y;
                                break;
		
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
				case SDLK_ESCAPE:
				gameover = 1;
                                case SDLK_q:
					gameover = 1;
					break;
				case SDLK_LEFT:
					if ( rcSrc.x == 192 )
						rcSrc.x = 128;
					else if(rcSrc.x == 128)
						rcSrc.x = 64;
					else if(rcSrc.x == 64)
                                               rcSrc.x = 0;
                                        else
                                               rcSrc.x = 192;
                                        rcSprite.x -= 5;
                                         
					break;
				case SDLK_RIGHT:
					if ( rcSrc.x == 256 )
						rcSrc.x = 320;
					else if(rcSrc.x == 320)
						rcSrc.x = 384;
					else if(rcSrc.x == 384)
                                               rcSrc.x = 448;
                                        else
                                               rcSrc.x = 256;
                                        rcSprite.x += 5;
					break;
			}
			break;
	}
}

int main(int argc, char* argv[])
{
	SDL_Surface *screen, *temp, *sprite, *grass;
	SDL_Rect rcGrass;
	int colorkey;

	
	SDL_Init(SDL_INIT_VIDEO);

	
	SDL_WM_SetCaption("SDL Animation", "SDL Animation");

	
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);

	
	SDL_EnableKeyRepeat(70, 70);

	
	temp   = SDL_LoadBMP("ss2.bmp");
	sprite = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);

	
	colorkey = SDL_MapRGB(screen->format, 255, 0, 255);
	SDL_SetColorKey(sprite, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);

	
	temp  = IMG_Load("jungle.png");
	grass = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);

	
	rcSprite.x = 300;
	rcSprite.y = 100;

	
	rcSrc.x = 256;
	rcSrc.y = 0;
	rcSrc.w = SPRITE_SIZE;
	rcSrc.h = SPRITE_SIZE;

	gameover = 0;

	
	while (!gameover)
	{
		SDL_Event event;
		
		
		SDL_WaitEvent(&event);
			HandleEvent(event);
		
		
		if (rcSprite.x <= 0)
			rcSprite.x = 0;
		if (rcSprite.x >= SCREEN_WIDTH - SPRITE_SIZE) 
			rcSprite.x = SCREEN_WIDTH - SPRITE_SIZE;

		if (rcSprite.y <= 0)
			rcSprite.y = 0;
		if (rcSprite.y >= SCREEN_HEIGHT - SPRITE_SIZE) 
			rcSprite.y = SCREEN_HEIGHT - SPRITE_SIZE;

		
		
		
		SDL_BlitSurface(grass, NULL, screen, &rcGrass);
		SDL_BlitSurface(sprite, &rcSrc, screen, &rcSprite);
		
			
		

		
		SDL_UpdateRect(screen, 0, 0, 0, 0);
	}

	
	SDL_FreeSurface(sprite);
	SDL_FreeSurface(grass);
	SDL_Quit();

	return 0;
}
