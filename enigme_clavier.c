#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <string.h>
#include "enigme_clavier.h"
#include <SDL/SDL_ttf.h>
int afficher_enigme(enigme e[],SDL_Surface *ecran)
{
	int alea, MAX = 4, MIN=1;//Max et min a changer lors de la determination du nombre exact d'enigme
	/*SDL_Rect position;*/
	srand(time(NULL));
	alea=(rand()%(MAX -MIN +1) +MIN);
	e[alea].position.x = /*ecran->w / 2 - e[alea].imageenigme->w / 2*/0;
	e[alea].position.y = /*ecran->h / 2 - e[alea].imageenigme->h / 2*/0;
	SDL_BlitSurface(e[alea].imageenigme, NULL,ecran, &e[alea].position);
	SDL_Flip(ecran);
	return alea;
}
int resolution_enigme(enigme e[],int pos, SDL_Event event)
{
	FILE* reponse=NULL;
	reponse=fopen("reponse_enigme.txt","r");
	int cpt=0,continuer=1;
	char let,ch;
	if(reponse!=NULL)
	{
		let=fgetc(reponse);
		while(let!=EOF && cpt!=pos)
		{
			cpt+=1;
			let=fgetc(reponse);
		}
		/*do
		{
			cpt+=1;
			let=fgetc(reponse);	
		}while(let!=EOF && cpt!=pos);*/
                        SDL_WaitEvent(&event);
                        switch(event.type)
                        {
                                case SDL_KEYDOWN:
                                        switch(event.key.keysym.sym)
                                        {
                                                case SDLK_a:
                                                        ch='a';
                                                        break;
                                                case SDLK_b:
                                                        ch='b';
                                                        break;
                                                case SDLK_c:
                                                        ch='c';
                                                        break;
                                                case SDLK_d:
                                                        ch='d';
                                                        break;
						default:;
					}
			}
		fclose(reponse);
	}
	if(ch==let)
		return 1;
	if(ch!=let)
		return 0;
}
int enigme_clavier(SDL_Surface *ecran)
{
	SDL_Event event;
	int pos,r, k=0,i=3, j, n=0;
	SDL_Surface *image1;
	SDL_Surface *image2;
	SDL_Rect positionimage;
	enigme t[5];
	//int continuer=1;
	image1=IMG_Load("win.png");
	image2=IMG_Load("lost.png");
    	t[1].imageenigme = IMG_Load("enigme_1.png");
    	t[2].imageenigme = IMG_Load("enigme_2.png");
    	t[3].imageenigme = IMG_Load("enigme_3.jpg");
    	t[4].imageenigme = IMG_Load("enigme_4.jpg");
	positionimage.x=0;
	positionimage.y=0;
	pos=afficher_enigme(t,ecran);
	SDL_WaitEvent(&event);
	r=resolution_enigme(t,pos,event);
	if(r==1)
	{
		printf("\nReponse correcte\n");
		SDL_BlitSurface(image1,NULL,ecran,&positionimage);
		SDL_Flip(ecran);
		SDL_Delay(5000);
            	k += 500;
	}
	else
        {
                printf("\nReponse incorrect\n");
		SDL_BlitSurface(image2,NULL,ecran,&positionimage);
		SDL_Flip(ecran);
		SDL_Delay(5000);
                k -= 500;
        }
	for(j = 1; j < 5; j++)
		SDL_FreeSurface(t[j].imageenigme);
	SDL_FreeSurface(image1);
	SDL_FreeSurface(image2);
	return k;
}
