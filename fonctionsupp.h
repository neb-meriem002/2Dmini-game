#ifndef FONCTIONSUPP_H_INCLUDED
#define FONCTIONSUPP_H_INCLUDED

typedef struct joueur
{
char nom1[20];
int score;
}joueur;


void nettoyage_resources (SDL_Window *w, SDL_Renderer *r);
SDL_Surface * chargemment( int x );
void CreateLettre(SDL_Renderer *r,SDL_Surface *img,SDL_Texture *t_lettre,SDL_Rect rectangle);
SDL_Rect* positionnement( SDL_Rect p[], int N , int q );
SDL_Rect* positionnement1( SDL_Rect p[], int N , int q );
void meilleur_scores (joueur x);
void best_scores(SDL_Surface* ecran,SDL_Renderer* rendu,SDL_Window *fenetre);

#endif // FONCTIONSUPP_H_INCLUDED
