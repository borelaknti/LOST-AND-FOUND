#include<stdlib.h>
#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include"fct1.h"
#include"fct3.h"
#include"fct2.h"
#include <SDL/SDL_ttf.h>
int main( )
 
{

 SDL_Surface *screen;
SDL_Surface *personnage[10],*personnage2[10],*image,*fleche,*pierre,*serpent, *texte=NULL,*texteX=NULL,*texte1=NULL,*texte2=NULL,*vie[5],*vie2[5],*coeur,*cle,*porte,*ennemi[5],*gameover;
SDL_Rect postionecran,pospersonnage,pospersonnage2,posfleche,pospierre,posserpent,posvie,posvie2,postexte,postexteX,postexte1,postexte2,poscoeur,poscle,posennemi,posporte,posgo;
SDL_Event event;
char pause;
int done=1,continuer=1,i=0,m1=0,j=4,ta=0,tp=0,k=0,k1=0,x1,y1,test,ta1=0,test5;
int tp1=0,p1=0,a=0,t=0,m=0,s=0,ta2=0,tp2=0,score=0,test1,test2,test3,t3=0,ta3=0,tp3=0,c=5,a2=0,p2=0,alea,r=1,test4,tes=0;
enigme e[5];
SDL_Color couleurNoire = {0, 0, 0};
char sc[20],temps[30];
TTF_Init();
TTF_Font *police = NULL;
police = TTF_OpenFont("angelina.TTF", 65);
sprintf(sc,"score :%d  ",score);

sprintf(temps,"temps %d:%d",m,s);

texte = TTF_RenderText_Blended(police, sc, couleurNoire);
texteX = TTF_RenderText_Blended(police, sc, couleurNoire);
texte1 = TTF_RenderText_Blended(police, temps, couleurNoire);
texte2 = TTF_RenderText_Blended(police, temps, couleurNoire);
double v_x = 1.5;

    double v_grav = 0.08;
    double v_saut = -4;

    double v_y = v_saut;

   SDL_Init(SDL_INIT_VIDEO);
 
   SDL_Surface*ecran=SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
 
   SDL_Surface*sprite=SDL_LoadBMP("cave.bmp");
 
   Uint32 x=-100, y=-300; 
 
    
 
   SDL_Rect decors={x,y, sprite->w, sprite->h};
                
vie[0]=IMG_Load("5.png");
vie[1]=IMG_Load("2.png");
vie[2]=IMG_Load("3.png");
vie[3]=IMG_Load("4.png");
vie[4]=IMG_Load("1.png");
           //vie du 2éme joueur
  vie2[0]=IMG_Load("5.png");
  vie2[1]=IMG_Load("2.png");
  vie2[2]=IMG_Load("3.png");
  vie2[3]=IMG_Load("4.png");
  vie2[4]=IMG_Load("1.png");
serpent=IMG_Load("serpe.png");
fleche=IMG_Load("fleche.png");
pierre=IMG_Load("pierre.png");
cle=IMG_Load("cll.png");
coeur=IMG_Load("vie.png");
porte=IMG_Load("porte1.png");
gameover=IMG_Load("gameover.png");
personnage[0]=IMG_Load("personnage11.png");
personnage[1]=IMG_Load("personnage22.png");
personnage[2]=IMG_Load("personnage33.png");
personnage[3]=IMG_Load("personnage44.png");
personnage[4]=IMG_Load("personnage1.png");
personnage[5]=IMG_Load("personnage2.png");
personnage[6]=IMG_Load("personnage3.png");
personnage[7]=IMG_Load("personnage4.png");
personnage[8]=IMG_Load("tir1.png");
personnage[9]=IMG_Load("saut2.png");
       //initialisation du 2éme joueur
  personnage2[0]=IMG_Load("personnage2.11.png");
  personnage2[1]=IMG_Load("personnage2.22.png");
  personnage2[2]=IMG_Load("personnage2.33.png");
  personnage2[3]=IMG_Load("personnage2.44.png");
  personnage2[4]=IMG_Load("personnage2.1.png");
  personnage2[5]=IMG_Load("personnage2.2.png");
  personnage2[6]=IMG_Load("personnage2.3.png");
  personnage2[7]=IMG_Load("personnage2.4.png");
  personnage2[8]=IMG_Load("tir2.1.png");
  personnage2[9]=IMG_Load("saut2.2.png");
ennemi[1]=IMG_Load("11.png");
ennemi[2]=IMG_Load("22.png");
ennemi[3]=IMG_Load("33.png");
ennemi[4]=IMG_Load("mort.png");
 pospierre.x=300;
 pospierre.y=400;
pospersonnage.x=100;
pospersonnage.y=320;
        // position 2éme joueur
  pospersonnage2.x=0;
  pospersonnage2.y=300;
posfleche.x=0;
posfleche.y=335;
posserpent.x=800;
posserpent.y=400;
posvie.x=0;
posvie.y=0; 
      // position vie du 2éme joueur
 posvie2.x=400;
 posvie2.y=0; 
postexte1.x=50;
postexte1.y=100; 
   // temps 2éeme joueur
  postexte2.x=450;
  postexte2.y=100; 
postexte.x=50;
postexte.y=0; 
    // score 2éme joueur 
  postexteX.x=450;
  postexteX.y=0;
poscoeur.x=150;
poscoeur.y=400; 
poscle.x=300;
 poscle.y=200; 
 posennemi.x=800;
 posennemi.y=300;
posporte.x=650;
posporte.y=240;
posgo.x=200;
posgo.y=200;
   for( SDL_Event evenement; evenement.type!=SDL_QUIT&& evenement.key.keysym.sym!=SDLK_ESCAPE; SDL_PollEvent(&evenement)){
 
    
 
    SDL_FillRect(ecran, NULL, SDL_MapRGB( ecran->format, 0,0,0));
 
   
   
 
    switch( evenement.type){
     case SDL_KEYUP :
     switch(evenement.key.keysym.sym){
       case SDLK_SPACE:
       i=2;
         break;
       }
     break;
    case SDL_KEYDOWN :
      
 
    switch(evenement.key.keysym.sym){                   //deplacement joueur 1
    
    case SDLK_RIGHT :
  if(x>-2500)
  x-=4; 
  pospierre.x-=4;
        if(i==3||i>=4)
                 { i=0;
                     j=4;}
                if(i<3)
                  i++;
        posfleche.x++;
      if(pospersonnage.x<800)
        pospersonnage.x++;
      break;
 
    case SDLK_LEFT : ++x;
pospersonnage.x--; 
  if(j==7)
                  j=4;
                if(j<7)
                  j++;
                  i=j;

break;
 
    case SDLK_DOWN : 
      pospersonnage.y++;

       break;
 
    case SDLK_UP : 
    k1=1;
     x1=x;
    break;
     case SDLK_SPACE:
        k=1;
        i=8;
     break;
 
    }
 
   break;
 
   }
 switch( evenement.type){
     case SDL_KEYUP :
     switch(evenement.key.keysym.sym){
       case SDLK_f:
       m1=2;
         break;
       }
     break;
    case SDL_KEYDOWN :
      
 
    switch(evenement.key.keysym.sym){               //deplacement joueur 2
    
    case SDLK_d :
  if(x>-2500)
  x-=4; 
  pospierre.x-=4;
        if(m1==3||m1>=4)
                 { m1=0;
                     j=4;}
                if(m1<3)
                  m1++;
        posfleche.x++;
      if(pospersonnage2.x<800)
        pospersonnage2.x++;
      break;
 
    case SDLK_q : ++x;
pospersonnage2.x--; 
  if(j==7)
                  j=4;
                if(j<7)
                  j++;
                  m1=j;

break;
 
    case SDLK_s : 
      pospersonnage2.y++;

       break;
 
    case SDLK_z : 
    k1=1;
     x1=x;
    break;
     case SDLK_f:
        k=1;
        m1=8;
     break;
 
    }
 
   break;
 
   }
ta3 = SDL_GetTicks();
         

        if (ta3 - tp3 > 30) 
              


        { 
           
    if(posennemi.x==0)
              { posennemi.x=0;
                }
             p2=a2;
               a2=posennemi.x;
             
              if(posennemi.x>0&&posennemi.x<=800&&p2>=a2&&tes!=1)
           { posennemi.x-=2; 
             if(r==3)
              r=1;
             if(r<3)
            r++;}
              
            tp3 = ta3; 

        }
ta2 = SDL_GetTicks();
         

        if (ta2 - tp2 >= 1000) 
              


        {   s++;
           if(s%60==0)
          {
               s=0;
              m++;}
          sprintf(temps,"temps %d:%d",m,s);

              

texte1 = TTF_RenderText_Blended(police, temps, couleurNoire);
texte2 = TTF_RenderText_Blended(police, temps, couleurNoire);
              
    
              
            tp2 = ta2; 

        }
 ta1 = SDL_GetTicks();
         

        if (ta1 - tp1 > 15) 
              


        { 
           
    if(posserpent.x==0)
              { posserpent.x=800;
                t3++;}
             p1=a;
               a=posserpent.x;
             
              if(posserpent.x>0&&posserpent.x<=800&&p1>=a&&t3<3)
            posserpent.x-=4; 
              
            tp1 = ta1; 

        }
  if(k==1)
 {
  ta = SDL_GetTicks();
    
         if (ta - tp > 15) 
            { posfleche.x+=3;
                tp=ta;}}
    if(k1==1&&x1-y1<113&&pospersonnage.x<800)
      {  if(pospersonnage.y>177&&pospersonnage.y<250)
             i=9;
         pospierre.x-=v_x+2;
         pospersonnage.x += v_x;
         posfleche.x +=v_x;
         if(x>-2500)  
         x-=v_x+2;
            pospersonnage.y += v_y;
          v_y += v_grav;
       }

     if(pospersonnage.y>250&&pospersonnage.y<300)
       i=2;
     if (pospersonnage.y >= 300)
	v_y = v_saut;
    decors.x=x; decors.y=y;
test=collision(personnage[i], pierre,pospierre,pospersonnage);
test1=collision(personnage[i], serpent,posserpent,pospersonnage);
test2=collision(personnage[i], coeur,poscoeur,pospersonnage);
test3=collision(personnage[i], cle,poscle,pospersonnage);
test5=collision(personnage[i], ennemi[r],posennemi,pospersonnage);
test4=collision2(fleche,ennemi[r],posfleche,posennemi);
if(test4==1&&k==1)
{r=4;
tes=1;
posennemi.y=500;}
if(test2==1)
{
if(t>0)
t--;
poscoeur.x+=200;}
if(test3==1)
{score +=20;
sprintf(sc,"score : %d ",score);
               texte = TTF_RenderText_Blended(police, sc, couleurNoire);
  texteX = TTF_RenderText_Blended(police, sc, couleurNoire);
poscle.x +=100;}
if (test1==1)
{if(t<4)
t++;
t3++;
posserpent.x=800;}

if(test==1)
{ 

                
                sprintf(sc,"score : %d ",score);
 
               texte = TTF_RenderText_Blended(police, sc, couleurNoire);
 texteX = TTF_RenderText_Blended(police, sc, couleurNoire);
 pospierre.x=0;
  pospierre.y=0;}

    SDL_BlitSurface( sprite, NULL, ecran, &decors);
if(x<=-2499)
 SDL_BlitSurface(porte,NULL,ecran,&posporte);
    SDL_BlitSurface(personnage[i],NULL,ecran,&pospersonnage); //blit perso 1
SDL_BlitSurface(personnage2[m1],NULL,ecran,&pospersonnage2);  //blit perso 2
    SDL_BlitSurface(ennemi[r],NULL,ecran,&posennemi);
SDL_BlitSurface(serpent, NULL, ecran, &posserpent);
  if(k==1)
    SDL_BlitSurface(fleche,NULL,ecran,&posfleche);

SDL_BlitSurface(texte,NULL,ecran,&postexte);
SDL_BlitSurface(texteX,NULL,ecran,&postexteX);
             SDL_BlitSurface(texte1,NULL,ecran,&postexte1);
  SDL_BlitSurface(texte2,NULL,ecran,&postexte2);
             SDL_BlitSurface(vie[t],NULL,ecran,&posvie);
  SDL_BlitSurface(vie2[t],NULL,ecran,&posvie2);
             SDL_BlitSurface(cle,NULL,ecran,&poscle);
             SDL_BlitSurface(coeur,NULL,ecran,&poscoeur);
 if(pospersonnage.x>750)
  alea= enigmes(ecran);
if(test5==1)
{
while(done)

{
SDL_PollEvent(&event);
SDL_BlitSurface(gameover,NULL,ecran,&posgo);
 SDL_Flip(ecran);
 
switch(event.type)
{
case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {   case SDLK_ESCAPE:
             done=0;
             break;}
 }}}
   
  if(posfleche.x>800)
  {k=0;
      posfleche.x=pospersonnage.x;}
    if(pospersonnage.y==300)
          {y1=x;
                 }
 
    SDL_Flip(ecran);
 
   }
 
   SDL_FreeSurface( sprite);

  
    return 0;
 
}

	

