typedef struct enigme
{
	SDL_Surface *imageenigme;
	SDL_Rect position;
}enigme;
int afficher_enigme(enigme e[],SDL_Surface *ecran);
int resolution_enigme(enigme e[],int pos, SDL_Event event);
int enigme_clavier(SDL_Surface *ecran);
