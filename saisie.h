#ifndef SAISIE_H_INCLUDED
#define SAISIE_H_INCLUDED
#include "combi.h"

int saisie_N(SDL_Renderer* r,  SDL_Surface* ecran,SDL_Window *fenetre );
int saisie_n(SDL_Renderer* r,  SDL_Surface* ecran,SDL_Window *fenetre,int N );
liste saisie_deb(SDL_Renderer* r,  SDL_Surface* ecran,SDL_Window *fenetre,int N );
liste saisie_fin(SDL_Renderer* r,  SDL_Surface* ecran,SDL_Window *fenetre,int N,liste tete);
char* Saisie_nom(SDL_Renderer *r,SDL_Surface*ecran,SDL_Window *fenetre);


#endif // SAISIE_H_INCLUDED
