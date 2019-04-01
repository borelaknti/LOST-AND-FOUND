#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include "enigme_clic.h"
#include <SDL/SDL_ttf.h>
int afficherenigme(enigme e[], SDL_Surface *ecran)
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
int resolution (enigme e[],int pos, SDL_Event event)
{
	SDL_Rect positionclic;
	positionclic.x = event.motion.x, positionclic.y = event.motion.y;
	switch(event.type)
	{
		case SDL_MOUSEBUTTONUP:
   		switch(pos)//pos designe le numero de l'image afficher dans le tableau
		{
			case 1:
				if(positionclic.x < 543 && positionclic.x > 133  && positionclic.y > 543 && positionclic.y < 700) // selon que le clic soit fait entre un intervalle donner soit il est juste , soit il est faut
				{
					return 0;
				}
				if(positionclic.x > 710 && positionclic.x < 1138 && positionclic.y > 543 && positionclic.y < 700)
				{
					return 1;
				}
				break;
			case 2:
				if(positionclic.x < 543 && positionclic.x > 133  && positionclic.y > 543 && positionclic.y < 700)
				{
					return 0;
				}
				if(positionclic.x > 710 && positionclic.x < 1138 && positionclic.y > 543 && positionclic.y < 700)
				{
					return 1;
				}
				break;
			case 3:
				if(positionclic.x < 543 && positionclic.x > 133  && positionclic.y > 543 && positionclic.y < 700)
				{
					return 0;
				}
				if(positionclic.x > 710 && positionclic.x < 1138 && positionclic.y > 543 && positionclic.y < 700)
				{
					return 1;
				}
				break;
			case 4:
            			if(positionclic.x < 543 && positionclic.x > 133  && positionclic.y > 543 && positionclic.y < 700)
				{
					return 1;
				}
				if(positionclic.x > 710 && positionclic.x < 1138 && positionclic.y > 543 && positionclic.y < 700)
				{
					return 0;
				}
				break;
		}
		break;
	}
	return 5;
}
int enigmes(SDL_Surface *ecran)
{
	SDL_Event event;
    	SDL_Surface *texte;
    	SDL_Rect position_time;
	SDL_Color couleurverte = {154,205,50}, couleurnoir={0,0,0};
	int pos,r, k = 0, i = 3, j, n = 0;
    	//int sec, min;
    	enigme t[5];
    	/*int compteur=16 , tempsprecedent=0;
	timer tempsactuel;
    	char temps[50];*/
    	int continuer = 1;
    	TTF_Font *police = NULL;
	TTF_Init();
	police = TTF_OpenFont("", 40);//entrer le nom du fichier en .ttf
    	t[1].imageenigme = IMG_Load("q 1.png");//charger les fichiers
    	t[2].imageenigme = IMG_Load("q 2.png");
    	t[3].imageenigme = IMG_Load("q 3.png");
    	t[4].imageenigme = IMG_Load("q 4.png");
	position_time.x = /*ecran->w / 2*/0;
	position_time.y = /*ecran->h / 2*/0;//la position a laquel on va afficher le temps qu'il reste a repondre a l'utilisateur 
	pos=afficherenigme(t,ecran);
	//tempsactuel.start();
	/*sprintf(temps,"time :%d",compteur);
	texte=TTF_RenderText_Solid(police,temps,couleurverte);*/
	while(continuer)
	{
		/*tempsactuel=SDL_GetTicks();
		if(tempsactuel-tempsprecedent>=1000)
		{
			compteur-=1;
			if(compteur>0)
			{
				sprintf(temps,"time :%d",compteur);
				texte=TTF_RenderText_Solid(police,temps,couleurverte);
				SDL_BlitSurface(texte, NULL, ecran, &position_time);
				//SDL_FreeSurface(texte);//voir si un probleme va se poser au niveau de la fermeture et de la reouverture
				SDL_Flip(ecran);
				tempsprecedent=tempsactuel;
			}
			else
			{
				compteur=0;
			}
		} */
		SDL_PollEvent(&event);
		r=resolution(t,pos,event);
		if(r==1)
		{
			printf("\nReponse correcte\n");
            		k += 500;
            		continuer = 0;
		}
		else if(r==0)
                {
                        printf("\nReponse incorrect\n");
                        k -= 500;
                        continuer = 0;
                }
	}
	TTF_CloseFont(police);
	TTF_Quit();
	SDL_FreeSurface(texte);
	for(j = 1; j < 5; j++)
    		SDL_FreeSurface(t[j].imageenigme);
	return k;
}
