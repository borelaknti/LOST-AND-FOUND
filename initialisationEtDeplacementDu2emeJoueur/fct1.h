#ifndef FONCTIONS_H_
#define FONCTIONS_H_
typedef struct enigme
	{
		SDL_Surface *imageenigme;
		SDL_Rect position;
	}enigme;
int collision(SDL_Surface *personnage,SDL_Surface * pierre,SDL_Rect pospierre,SDL_Rect pospersonnage);

int afficherenigme(enigme e[], SDL_Surface *ecran);
int resolution (enigme e[],int alea, SDL_Event event);
	int enigmes(SDL_Surface *ecran);
int collision2(SDL_Surface *personnage,SDL_Surface * pierre,SDL_Rect pospierre,SDL_Rect pospersonnage);

#endif /* FONCTIONS_H_ */
