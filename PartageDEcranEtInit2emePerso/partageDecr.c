#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include"SDL/SDL_mixer.h"
#include "partageDecr.h"




void initback( back* b)
{
//creation background
b->sprite=SDL_LoadBMP("cave.bmp") ;  
b->backpos.x=0;
b->backpos.y=0;     
b->campos.x=0;
b->campos.y=0;
b->campos.w=800 ;
b->campos.h=300;
}

void initback2( back* b1)
{
//creation background
b1->sprite=SDL_LoadBMP("cave.bmp") ; 
b1->backpos.x=0;
b1->backpos.y=300;     
b1->campos.x=0;
b1->campos.y=300;
b1->campos.w=800 ;
b1->campos.h=300;
}
void afficher_Map(back b ,SDL_Surface *fenetre)
{

   SDL_BlitSurface(b.sprite,NULL,fenetre,&b.backpos);

SDL_Flip(fenetre);

}

void afficher_Map2(back b1 ,SDL_Surface *fenetre)
{

   SDL_BlitSurface(b1.sprite,NULL,fenetre,&b1.backpos);

SDL_Flip(fenetre);

}
void freeBackground(back* b )
{
	SDL_FreeSurface(b->sprite);
}

void freeBackground2(back* b1 )
{
	SDL_FreeSurface(b1->sprite);
}



void initialiser_perso1(perso *p)
{
p->personnage[0]= IMG_Load("personnage11.png");               
p->personnage[1]=IMG_Load("personnage22.png");
p->personnage[2]=IMG_Load("personnage33.png");
p->personnage[3]=IMG_Load("personnage44.png");
p->personnage[4]=IMG_Load("personnage1.png");
p->personnage[5]=IMG_Load("personnage2.png");
p->personnage[6]=IMG_Load("personnage3.png");
p->personnage[7]=IMG_Load("personnage4.png");
p->personnage[8]=IMG_Load("tir1.png");
p->personnage[9]=IMG_Load("saut2.png");
         
        
         p->pospersonnage.x=10;
         p->pospersonnage.y=280;
         
            p->img_int=p->personnage[0];
}


void initialiser_perso2(perso2 *p2)
{
p2->personnage2[0]=IMG_Load("personnage2.11.png");
p2->personnage2[1]=IMG_Load("personnage2.22.png");
p2->personnage2[2]=IMG_Load("personnage2.33.png");
p2->personnage2[3]=IMG_Load("personnage2.44.png");
p2->personnage2[4]=IMG_Load("personnage2.1.png");
p2->personnage2[5]=IMG_Load("personnage2.2.png");
p2->personnage2[6]=IMG_Load("personnage2.3.png");
p2->personnage2[7]=IMG_Load("personnage2.4.png");
p2->personnage2[8]=IMG_Load("tir2.1.png");
p2->personnage2[9]=IMG_Load("saut2.2.png");

        
         p2->pospersonnage2.x=10;
         p2->pospersonnage2.y=580;
         
            p2->img2_int=p2->personnage2[0] ;
}

void afficher1(SDL_Surface* fenetre,perso p)
{

SDL_BlitSurface(p.img_int,NULL,fenetre,&p.pospersonnage);
SDL_Flip(fenetre);

}
void afficher2(SDL_Surface* fenetre,perso2 p2)
{

SDL_BlitSurface(p2.img2_int,NULL,fenetre,&p2.pospersonnage2);
SDL_Flip(fenetre);

}
void liberer_player(perso* p)
{

SDL_FreeSurface(p->img_int);

}
void liberer_player2(perso2* p2)
{

SDL_FreeSurface(p2->img2_int);

}
  
