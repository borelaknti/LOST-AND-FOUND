#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include"fct.h"
#include<math.h>
#include <SDL/SDL_ttf.h>
int main(void){
SDL_Surface *screen;
SDL_Surface *vie[4];
SDL_Surface *personnage,*image,*pierre,*texte=NULL,*texte1=NULL,*diamond;
SDL_Rect postionecran,pospersonnage,pospierre,pos,p[5];
SDL_Event event;
SDL_Color couleurNoire = {0, 0, 0};
int continuer=1,ta=0,tp=0,ta1=0,tp1=0,w,w1,h,h1,x,x1,y,y1,p1=0,a=0,i=0,X1,X2,Y1,Y2,R1,R2,D1,D2,score=0,s=0,m=0,j=0,x2,y2,h2,w2,X3,Y3,R3,D3,D4;
char pause;
char sc[20],temps[30];
TTF_Init();
TTF_Font *police = NULL;
police = TTF_OpenFont("angelina.TTF", 65);
if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("unable to initialize SDL: %s\n",SDL_GetError());
return 1;
}
screen=SDL_SetVideoMode(1024,512,0,SDL_HWSURFACE|SDL_DOUBLEBUF);
if(screen==NULL){
printf("unable to set video mode:%s\n",SDL_GetError());
return 1;
}
charger_image(image,personnage,screen,&postionecran,&pospersonnage);
personnage=IMG_Load("per.png");
image=IMG_Load("images.jpg");
diamond=IMG_Load("diamond.png");
pierre=IMG_Load("pierre.png");
vie[0]=IMG_Load("5.png");
vie[1]=IMG_Load("2.png");
vie[2]=IMG_Load("3.png");
vie[3]=IMG_Load("4.png");
vie[4]=IMG_Load("1.png");
sprintf(sc,"score :%d",score);
sprintf(temps,"temps %d:%d",m,s);
texte = TTF_RenderText_Blended(police, sc, couleurNoire);
texte1 = TTF_RenderText_Blended(police, temps, couleurNoire);
w=personnage->w;
w1=pierre->w;
h=personnage->h;
h1=pierre->h;
h2=diamond->h;
w2=diamond->w;
pospierre.x=1024;
pospierre.y=320;
pos.x=0;
pos.y=400;
p[0].x=200;
p[0].y=305;
p[1].x=300;
p[1].y=305;
p[2].x=500;
p[2].y=305;
p[3].x=700;
p[3].y=305;
p[4].x=1024;
p[4].y=305;
while (continuer)

    {
       x2=p[j].x;
       x=pospersonnage.x;
       x1=pospierre.x;
       y=pospersonnage.y;
       y1=pospierre.y;
       y2=p[j].y;
       X1 = x + w/2;
       Y1 = y + h/2;
       X2 = x1 + w1/2;
       Y2 = y1 + h1/2;
       X3 = x2 + w2/2;
       Y3 = y2 + h2/2;
       /*R1=sqrt((w/2)*(w/2)+(h/2)*(h/2));*/
       R3=sqrt((w2/2)*(w2/2)+(h2/2)*(h2/2));
       if(w<h)
         R1=w/2;
       else 
         R1=h/2;
       if(w1<h1)
         R2=w1/2;
       else 
         R2=h1/2;
       /*if(w2<h2)
         R3=w2/2;
       else 
         R3=h2/2;   */
       D1=sqrt((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2));
       D3=sqrt((X1-X3)*(X1-X3)+(Y1-Y3)*(Y1-Y3));
       D2=R1+R2;
       D4=R1+R3;
        SDL_PollEvent(&event); 
        
        switch(event.type)

        {

            case SDL_QUIT:

                continuer = 0;

                break;
           case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {   case SDLK_ESCAPE:
             continuer=0;
             break;
            case SDLK_UP:
                pospersonnage.y--;
                break;
            case SDLK_DOWN:
                pospersonnage.y++;
                break;
            case SDLK_RIGHT:
                pospersonnage.x++;
                break;
            case SDLK_LEFT:
                pospersonnage.x--;
                break;
        }
        break;

        }


        ta = SDL_GetTicks();
         

        if (ta - tp > 15) 
              


        { 
           
    if(pospierre.x==0)
               pospierre.x=1024;
             p1=a;
               a=pospierre.x;
             
              if(pospierre.x>0&&pospierre.x<=1024&&p1>=a)
            pospierre.x--; 
              
            tp = ta; 

        }
         if(D3<=D4)
            { if(j<=3)
                j++;
                score=score+20;
                sprintf(sc,"score : %d",score);
               texte = TTF_RenderText_Blended(police, sc, couleurNoire);}

 
         if(D1<=D2)
           {         pospersonnage.x=pospersonnage.x-50;
                  i++;
                 }
ta1 = SDL_GetTicks();
         

        if (ta1 - tp1 >= 1000) 
              


        {   s++;
           if(s%60==0)
          {
               s=0;
              m++;}
          sprintf(temps,"temps %d:%d",m,s);

texte1 = TTF_RenderText_Blended(police, temps, couleurNoire);
              
    
              
            tp1 = ta1; 

        }
    if(i==4)
       continuer=0;
        
      SDL_BlitSurface(image,NULL,screen,&postionecran);
        SDL_BlitSurface(personnage, NULL, screen, &pospersonnage);
               SDL_BlitSurface(pierre, NULL, screen, &pospierre);
              SDL_BlitSurface(texte,NULL,screen,&postionecran);
             SDL_BlitSurface(texte1,NULL,screen,&pos);
             SDL_BlitSurface(vie[i],NULL,screen,&postionecran);
             SDL_BlitSurface(diamond,NULL,screen,&p[j]);
        SDL_Flip(screen);

    }











return(0);
}
