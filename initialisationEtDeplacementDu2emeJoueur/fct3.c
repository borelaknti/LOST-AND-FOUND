        #include <stdio.h>
	#include <stdlib.h>
	#include <SDL/SDL.h>
	#include <SDL/SDL_image.h>
	#include <time.h>
	#include "fct3.h"
        #include"fct1.h"
	#include <SDL/SDL_ttf.h>
	int afficherenigme(enigme e[], SDL_Surface *ecran)
	{
		int alea, MAX = 4, MIN=1;//Max et min a changer lors de la determination du nombre exact d'enigme
		/*SDL_Rect position;*/
		srand(time(NULL));
		alea=(rand()%(MAX -MIN +1) +MIN);
		e[alea].position.x = 200;
		e[alea].position.y = 200;
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
					if(positionclic.x < 555 && positionclic.x > 420  && positionclic.y > 350 && positionclic.y < 397) // selon que le clic soit fait entre un intervalle donner soit il est juste , soit il est faut
					{
						return 0;
					}
					if(positionclic.x > 240 && positionclic.x < 375 && positionclic.y > 350 && positionclic.y < 397)
					{
						return 1;
					}
					break;
				case 2:
					if(positionclic.x < 555 && positionclic.x > 420  && positionclic.y > 350 && positionclic.y < 397)
					{
						return 0;
					}
					if(positionclic.x > 240 && positionclic.x < 375 && positionclic.y > 350 && positionclic.y < 397)
					{
						return 1;
					}
					break;
				case 3:
					if(positionclic.x < 555 && positionclic.x > 420  && positionclic.y > 350 && positionclic.y < 397)
					{
						return 0;
					}
					if(positionclic.x > 240 && positionclic.x < 375 && positionclic.y > 350 && positionclic.y < 397)
					{
						return 1;
					}
					break;
				case 4:
	            			if(positionclic.x < 555 && positionclic.x > 420  && positionclic.y > 350 && positionclic.y < 397)
					{
						return 1;
					}
					if(positionclic.x > 240 && positionclic.x < 375 && positionclic.y > 350 && positionclic.y < 397)
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
		SDL_Surface *image1,*image2;
	    	SDL_Rect position;
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
	    	t[1].imageenigme = IMG_Load("enigme11.png");
	    	t[2].imageenigme = IMG_Load("enigme22.png");
	    	t[3].imageenigme = IMG_Load("enigme33.png");
	    	t[4].imageenigme = IMG_Load("enigme44.png");
		image1=IMG_Load("win.png");
		image2=IMG_Load("gameover.png");
		position.x =200 ;
		position.y =200; 
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
				SDL_BlitSurface(image1,NULL,ecran,&position);
				SDL_Flip(ecran);
	            		k = 500;
	            		continuer = 0;
			}
			else if(r==0)
	                {
	                        printf("\nReponse incorrect\n");
				SDL_BlitSurface(image2,NULL,ecran,&position);
				SDL_Flip(ecran);
	                        k = -500;
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
