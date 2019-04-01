typedef struct enigme
{
	SDL_Surface *imageenigme;
	SDL_Rect position;
}enigme;
int afficherenigme(enigme e[], SDL_Surface *ecran);
int resolution (enigme e[],int alea, SDL_Event event);
int enigmes(SDL_Surface *ecran);
