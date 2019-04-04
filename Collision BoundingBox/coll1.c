/* 
int collision(SDL_Rect* entiter1, SDL_Rect* entiter2)
{
int leftA, leftB;
int rightA, rightB;
int topA, topB;
int bottomA, bottomB;

leftA= entiter1->x;
rightA = entiter1->x + entiter1->w;
topA = entiter1->y;
bottomA = entiter1->y + entiter1->h;

leftB = entiter2->x;
rightB = entiter2->x + entiter2->w;
topB = entiter2->y;
bottomB = entiter2->y + entiter2->h;

if (bottomA <= topB)
return 1;
if (topA >= bottomB)
return 1;
if (rightA <= leftB)
return 1;
if (leftA >= rightB)
return 1;

return 0;

}

*/


/*
Le programme ci dessous va s'arreter si il y a une collision entre le personnage et la bombe.
*/

#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 448
#define SPRITE_SIZE    64
int collision(SDL_Rect* entiter1, SDL_Rect* entiter2)
{
int leftA, leftB;
int rightA, rightB;
int topA, topB;
int bottomA, bottomB;

leftA= entiter1->x;
rightA = entiter1->x + entiter1->w;
topA = entiter1->y;
bottomA = entiter1->y + entiter1->h;

leftB = entiter2->x;
rightB = entiter2->x + entiter2->w;
topB = entiter2->y;
bottomB = entiter2->y + entiter2->h;

if (bottomA <= topB)
return 1;
if (topA >= bottomB)
return 1;
if (rightA <= leftB)
return 1;
if (leftA >= rightB)
return 1;

return 0;

}
int main(int argc, char* argv[])
{
SDL_Surface *screen, *temp, *sprite, *grass, *TNT;
SDL_Rect rcSprite, rcGrass, rcTNT;
SDL_Event event;
Uint8 *keystate;
int colorkey, End;


SDL_Init(SDL_INIT_VIDEO);

	
SDL_WM_SetCaption("SDL Move", "SDL Move");

	
screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);

	
temp   = IMG_Load("sprite.png");
sprite = SDL_DisplayFormat(temp);
SDL_FreeSurface(temp);


colorkey = SDL_MapRGB(screen->format, 255, 0, 255);
SDL_SetColorKey(sprite,SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);


temp  = SDL_LoadBMP("grass.bmp");
grass = SDL_DisplayFormat(temp);
SDL_FreeSurface(temp);

temp  = SDL_LoadBMP("TNT.bmp");
TNT = SDL_DisplayFormat(temp);
SDL_FreeSurface(temp);
	
rcSprite.x = 0;
rcSprite.y = 0;

rcTNT.x=90;
rcTNT.y=90;

End = 0;

SDL_EnableKeyRepeat(70, 70);
	





while (!End)
{
		
if (SDL_WaitEvent(&event)) {
			
switch (event.type) {
				
case SDL_QUIT:
End = 1;
break;

            
case SDL_MOUSEBUTTONUP:


rcSprite.x = event.button.x;

rcSprite.y = event.button.y;
if(collision(&rcSprite,&rcTNT)==0)
{
End = 1;
}

break;

            
case SDL_KEYDOWN:
            
switch (event.key.keysym.sym) {
case SDLK_ESCAPE:
case SDLK_q:
End = 1;
break;
}
break;
}
}

		
keystate = SDL_GetKeyState(NULL);

if (keystate[SDLK_LEFT] ) {
rcSprite.x -= 2;
 if(collision(&rcSprite,&rcTNT)==0)
{
End = 1;
}
}
if (keystate[SDLK_RIGHT] ) {
rcSprite.x += 2;
 if(collision(&rcSprite,&rcTNT)==0)
{
End = 1;
}
}
if (keystate[SDLK_UP] ) {
rcSprite.y -= 2;
 if(collision(&rcSprite,&rcTNT)==0)
{
End = 1;
}
}
if (keystate[SDLK_DOWN] ) {
rcSprite.y += 2;
if(collision(&rcSprite,&rcTNT)==0)
{
End = 1;
}
}

		
if ( rcSprite.x < 0 ) {
rcSprite.x = 0;
}
else if ( rcSprite.x > SCREEN_WIDTH-SPRITE_SIZE ) {
rcSprite.x = SCREEN_WIDTH-SPRITE_SIZE;
}
if ( rcSprite.y < 0 ) {
rcSprite.y = 0;
}
else if ( rcSprite.y > SCREEN_HEIGHT-SPRITE_SIZE ) {
rcSprite.y = SCREEN_HEIGHT-SPRITE_SIZE;
}

		
for (int x = 0; x < SCREEN_WIDTH/SPRITE_SIZE; x++) {
for (int y = 0; y < SCREEN_HEIGHT/SPRITE_SIZE; y++) {
rcGrass.x = x * SPRITE_SIZE;
rcGrass.y = y * SPRITE_SIZE;
SDL_BlitSurface(grass, NULL, screen, &rcGrass);
}
}

		
SDL_BlitSurface(sprite, NULL, screen, &rcSprite);
SDL_BlitSurface(TNT, NULL, screen, &rcTNT);

		
SDL_UpdateRect(screen,0,0,0,0);
}

	
SDL_FreeSurface(sprite);
SDL_FreeSurface(grass);
SDL_Quit();

return 0;
}




