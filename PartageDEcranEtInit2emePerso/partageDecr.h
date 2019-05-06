#ifndef FONCTIONS_H_
#define FONCTIONS_H_

typedef struct back 
{
SDL_Surface* sprite ;
SDL_Rect backpos ; 
SDL_Rect campos ; 
}back,b,b1 ; 

typedef struct perso

{
SDL_Surface* personnage[10];
SDL_Surface* img_int;
SDL_Rect pospersonnage;

}perso, p;

typedef struct perso2

{
SDL_Surface* personnage2[10];
SDL_Surface* img2_int;
SDL_Rect pospersonnage2;

}perso2, p2;

void initback( back* b);
void initback2( back* b1);
void afficher_Map(back b ,SDL_Surface *fenetre);
void afficher_Map2(back b1 ,SDL_Surface *fenetre);
void freeBackground(back* b );
void freeBackground2(back* b1 );
void initialiser_perso1(perso *p);
void initialiser_perso2(perso2 *p2);
void afficher1(SDL_Surface* fenetre,perso p);
void afficher2(SDL_Surface* fenetre,perso2 p2);
void liberer_player(perso* p);
void liberer_player2(perso2* p2);

#endif /* FONCTIONS_H_ */
