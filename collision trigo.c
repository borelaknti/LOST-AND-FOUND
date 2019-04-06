#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include"fct1.h"
#include<math.h>
int collision(SDL_Surface *personnage,SDL_Surface * pierre,SDL_Rect pospierre,SDL_Rect pospersonnage)
{
int w,w1,h,h1,x,x1,y,y1,X1,X2,Y1,Y2,R1,R2,D1,D2;
w=personnage->w;
w1=pierre->w;
h=personnage->h;
h1=pierre->h;
x=pospersonnage.x;
x1=pospierre.x;
y=pospersonnage.y;
y1=pospierre.y;
X1 = x + w/2;
Y1 = y + h/2;
X2 = x1 + w1/2;
Y2 = y1 + h1/2;
/*R1=sqrt((w/2)*(w/2)+(h/2)*(h/2));
       R2=sqrt((w1/2)*(w1/2)+(h1/2)*(h1/2));*/
if(w<h)
         R1=w/2;
       else 
         R1=h/2;
       if(w1<h1)
         R2=w1/2;
       else 
         R2=h1/2;
D1=sqrt((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2));
D2=R1+R2;
if(D1<=D2)
return 1;
else 
return 0;
}
